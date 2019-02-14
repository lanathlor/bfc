#include <blc/blc.hpp>
#include <nlohmann/json.hpp>
#include <bfc/bfc.hpp>
#include "identity.hpp"

#include "handleKeyParam.hpp"
#include "confFile.hpp"

#include "connectedFunction.hpp"

#include "rsaKey.hpp"
#include "getMyIp.hpp"

#include "aliasMap.hpp"
#include "functionMap.hpp"
#include "trans.hpp"

#include <stdio.h>
#include <ios>
#include <iomanip>

bkc::rsaKey	bkc::myLog;

std::string confile = "./conf.bkc";
std::string userfile = "./users.bkc";
std::string keyfile = "./keypair.bkc";
std::string to = "";
std::string func;

static void createKey(const std::string &keyfile)
{
	json j;
	std::ofstream os;
	bkc::rsaKey key = bkc::rsaKey::make();

	j["pub"] = key.printablePub();
	j["priv"] = key.printablePriv();
	os.open(keyfile);
	os << j.dump() << std::endl;
	os.close();

}

void bfc::initActor()
{
	ltc_mp = ltm_desc;

	bfc::usage.add({"--help"}, "show this helper.");
	bfc::usage.add({"--chain=FILE"}, "use to specifie file to connect to the chain. DEFAULT: ./conf.bkc");
	bfc::usage.add({"--user-list=FILE"}, "use to specifie file to use for loading users. DEFAULT: ./users.bkc");
	bfc::usage.add({"--key=FILE"}, "use to specifie file to use for loading key. DEFAULT: ./keypair.bkc");
	bfc::usage.add({"--to=ALIAS"}, "use to specifie file to use for loading receiver");
	bfc::usage.add({"--create"}, "create a new key and save it in the file specified with --key flag");
	bfc::usage.add({"--f=function"}, "call the function. type --f=help to see the list");

	if (bfc::flags::isSet("help")){
		std::cout << bfc::usage << std::endl;
		bfc::exit();
		return;
	}
	if (bfc::flags::isSet("chain"))
		confile = bfc::flags::getValue("chain");
	if (bfc::flags::isSet("user-list"))
		userfile = bfc::flags::getValue("user-list");
	if (bfc::flags::isSet("key"))
		keyfile = bfc::flags::getValue("key");
	if (bfc::flags::isSet("to"))
		to = bfc::flags::getValue("to");
	if (bfc::flags::isSet("f"))
		func = bfc::flags::getValue("f");
	if (bfc::flags::isSet("create"))
		createKey(keyfile);

}

static void makeAction(bkc::trader &trader, std::string str)
{
	json j = {
		{"code", str},
		{"to", ""},
		{"amount", 0}
	};

	bkc::user::functionMap map;
	if (bfc::flags::isSet("to"))
		j["to"] = bfc::flags::getValue("to");
	if (bfc::flags::isSet("amount"))
	j["amount"] = std::stod(bfc::flags::getValue("amount"));

	map.call(trader, j);
}

int bfc::main()
{
	std::ifstream is;
	std::ifstream alias;

	alias.open(userfile);
	bkc::user::alias.load(alias);
	alias.close();

	is.open(keyfile);

	std::string tmp;

	std::getline(is, tmp);
	json j = json::parse(tmp);
	bkc::myLog.importPub(j["pub"].get<std::string>());
	bkc::myLog.importPriv(j["priv"].get<std::string>());

	json conf = bkc::readConfFile(confile);

	bkc::trader trader(bkc::myLog, conf["ip"].get<std::string>(), conf["port"].get<int>());

	bkc::user::functionMap map;

	if (bfc::flags::isSet("f"))
		makeAction(trader, bfc::flags::getValue("f"));

	std::ofstream oalias;

	oalias.open(userfile);
	bkc::user::alias.dump(oalias);
	oalias.close();
	bfc::exit();
	return (0);
}

void bfc::masterThread::readActor()
{
}

void bfc::masterThread::thick()
{
}
