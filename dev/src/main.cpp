#include <blc/blc.hpp>
#include <nlohmann/json.hpp>
#include <bfc/bfc.hpp>
#include "adminConnector.hpp"
#include "cinConnector.hpp"
#include "peerServer.hpp"
#include "identity.hpp"

#include "rsaKey.hpp"

#include <stdio.h>
#include <ios>
#include <iomanip>

bkc::rsaKey	bkc::myLog;

// auto flags = std::cout.flags();
// std::cout.fill('0');
// std::cout.width(2);
// for (unsigned char c : bkc::myLog.getPub()){
// 	std::cout << std::hex << +c;
// }
// std::cout << std::endl;
// std::cout.flags(flags);

// std::vector<std::string> bfc::ReqFlags()
// {
// 	// return (std::vector<std::string>({"pub", "priv", "N", "P"}));
// 	return (std::vector<std::string>({}));
// }

static bool handleKey()
{
	std::string pub_name = "public_key.der";
	std::string pri_name = "private_key.der";

	if (bfc::flags::isSet("pub"))
		pub_name = bfc::flags::getValue("pub");
	if (bfc::flags::isSet("pri"))
		pri_name = bfc::flags::getValue("pri");

	if (bfc::flags::isSet("create")) {
		bkc::rsaKey key = bkc::rsaKey::make();

		std::ofstream pub(pub_name);
		std::ofstream pri(pri_name);

		pub << key.getPub();
		pri << key.getPriv();

		if (bfc::flags::isSet("use")){
			bkc::myLog = key;
		} else {
			bfc::exit();
			return (false);
		}
	} else {
		bkc::myLog = bkc::rsaKey::open(pub_name, pri_name);
	}
	return (true);
}

static void launch(std::string addr, int port)
{
	bfc::factory<bkc::node::admCon>("adm", addr, port);
	bfc::factory<bkc::node::cinCon>("cin");
}

static void readConfFile(const std::string &fileName)
{
	std::ifstream file;
	std::string tmp;
	int port;

	try {
		file.open(fileName);
		long file_size = blc::tools::fileSize(file);
		char *data = new char [file_size];
		file.read(data, file_size);
		file.close();
		tmp = std::string(data, data + file_size);
		delete [] data;
	} catch (blc::error::exception &e) {
		std::cerr << e.what() << std::endl;
		throw blc::error::exception(assertError("error with \"" + fileName + "\" file"));
	}

	nlohmann::json j;
	std::string addr;

	try {
		j = nlohmann::json::parse(tmp);
		addr = j["ip"];
		port = j["port"].get<int>();
	} catch (blc::error::exception &e) {
		std::cerr << e.what() << std::endl;
		throw blc::error::exception(assertError("error parsing conf file"));
	} catch (nlohmann::detail::parse_error &e) {
		std::cerr << e.what() << std::endl;
		throw blc::error::exception(assertError("error parsing conf file"));
	}

	try {
		launch(addr, port);
	} catch (blc::error::exception &e) {
		std::cerr << e.what() << std::endl;
		throw blc::error::exception(assertError("error in launch"));
	}
}

void bfc::initActor()
{
	if (handleKey() == false)
		return;
	if (bfc::flags::isSet("P") && bfc::flags::isSet("N")){
		try {
			int port;

			try {
				port = std::stoi(bfc::flags::getValue("P"));
			} catch (std::invalid_argument &e) {
				throw blc::error::exception(assertError("stoi"));
			}
			launch(bfc::flags::getValue("N"), port);
		} catch (blc::error::exception &e) {
			std::cerr << e.what() << std::endl;
			throw blc::error::exception(assertError(""));
		}
	} else if (bfc::flags::isSet("set")) {
		readConfFile(bfc::flags::getValue("conf"));
	} else {
		readConfFile("conf.bkc");
	}
}

int bfc::main()
{
	int port = blc::network::findFreePort();

	ltc_mp = ltm_desc;
	try {
		bfc::masterThread::actor("adm").send(352, std::to_string(port));
		bfc::masterThread::actor("adm").send(350, "lanath");
		bfc::masterThread::actor("adm").send(301, std::to_string(port));
		bfc::masterThread::actor("adm").send(401);
		bfc::masterThread::actor("adm").send(301, "ok");
		std::cout << port << std::endl;
		bfc::factory<bkc::node::peerServ>("server", 50, port);
	} catch (blc::error::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return (0);
}


void bfc::masterThread::readActor()
{
	this->for_each({"adm"}, this->_adm);
	this->for_each({"cin"}, this->_cin);
	this->for_each({"server"}, this->_serv);
	this->for_each({"peer*"}, this->_peer);
}

void bfc::masterThread::thick()
{
	static int i = 0;

	if (i == 0){
		this->adminProto();
		this->cinProto();
		this->peerProto();
		this->servProto();
	}

	i++;
	if (i == 200000){
		this->masterPipe["adm"] << "401" << blc::endl << blc::endl;
		i = 0;
	}
}