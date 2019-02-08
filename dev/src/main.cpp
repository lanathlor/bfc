#include <blc/blc.hpp>
#include <nlohmann/json.hpp>
#include <bfc/bfc.hpp>
#include "adminConnector.hpp"
#include "cinConnector.hpp"
#include "peerServer.hpp"
#include "identity.hpp"

#include "handleKeyParam.hpp"
#include "confFile.hpp"
#include "initChain.hpp"

#include "rsaKey.hpp"
#include "getMyIp.hpp"

#include "trans.hpp"
#include "chain.hpp"

#include <stdio.h>
#include <ios>
#include <iomanip>

bkc::rsaKey	bkc::myLog;

void bfc::initActor()
{
	ltc_mp = ltm_desc;

	bfc::usage.add({"--help"}, "show this helper");
	bfc::usage.add({"--create"}, "create a pair of key. will erase already existing key");
	bfc::usage.add({"--init=CHAIN_NAME"}, "create a init file for a new chain");
	bfc::usage.add({"--use"}, "use the newly created key and/or configuration file to run");
	bfc::usage.add({"--a"}, "run as admin of the chain");
	bfc::usage.add({"--input=FILE"}, "read a file as the new stdin");
	bfc::usage.add({"--output_chain=FILE"}, "file to dump the chain state, default is ./dump.dc");
	bfc::usage.add({"--input_chain=FILE"}, "file to get the chain state, default is ./dump.dc");
	bfc::usage.add({"--pub=FILE"}, "select the public key file to read (or write if --create is used)");
	bfc::usage.add({"--pri=FILE"}, "select the public key file to read (or write if --create is used)");

	if (bfc::flags::isSet("help")){
		std::cout << bfc::usage << std::endl;
		bfc::exit();
		return;
	}
	if (handleKey() == false)
		return;
	std::string file = "conf.bkc";

	std::string in = "./dump.dc";
	std::string out = "./dump.dc";
	if (bfc::flags::isSet("output_chain"))
		out = bfc::flags::getValue("output_chain");
	if (bfc::flags::isSet("input_chain"))
		in = bfc::flags::getValue("input_chain");
	if (bfc::flags::isSet("init")){
		if ((bkc::initChain() = file) == "")
			return;
	}
	if (bfc::flags::isSet("conf")) {
		readConfFile(bfc::flags::getValue("conf"));
	} else {
		readConfFile(file);
	}
	bfc::factory<bkc::chain>("chain", bkc::myLog, 4, in, out);
}

int bfc::main()
{
	try {
		if (bfc::flags::isSet("a") == false) {
			int port = blc::network::findFreePort();

			bfc::masterThread::_myself = bkc::getMyIp() + ":" + std::to_string(port);
			std::cout << port << std::endl;


			bfc::masterThread::actor("adm").send(352, std::to_string(port));
			bfc::masterThread::actor("adm").send(401);
			bfc::masterThread::actor("adm").send(301, "ok");
			bfc::factory<bkc::node::peerServ>("server", 50, port);
		}
	} catch (blc::error::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}


void bfc::masterThread::readActor()
{
	if (bfc::flags::isSet("a") == false)
		this->for_each({"adm"}, this->_adm);
	this->for_each({"cin"}, this->_cin);
	this->for_each({"server"}, this->_serv);
	this->for_each({"peer*"}, this->_peer);
}

void bfc::masterThread::thick()
{
	static int i = 0;

	if (i == 0){
		if (bfc::flags::isSet("a") == false)
			this->adminProto();
		this->cinProto();
		this->peerProto();
		this->servProto();
	}

	i++;
	if (i == 200000 && bfc::flags::isSet("a") == false){
		this->masterPipe["adm"] << "401" << blc::endl << blc::endl;
		i = 0;
	}
}