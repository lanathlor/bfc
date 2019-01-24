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

#include <stdio.h>
#include <ios>
#include <iomanip>

bkc::rsaKey	bkc::myLog;

void bfc::initActor()
{
	bfc::usage.add({"--help"}, "show this helper");
	bfc::usage.add({"--create"}, "create a pair of key. will erase already existing key");
	bfc::usage.add({"--init=CHAIN_NAME"}, "create a init file for a new chain");
	bfc::usage.add({"--use"}, "use the newly created key and/or configuration file to run");
	bfc::usage.add({"--a"}, "run as admin of the chain");
	bfc::usage.add({"--input=FILE"}, "read a file as the new stdin");
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

	if (bfc::flags::isSet("init")){
		if ((bkc::initChain() = file) == "")
			return;
	}
	if (bfc::flags::isSet("conf")) {
		readConfFile(bfc::flags::getValue("conf"));
	} else {
		readConfFile(file);
	}
}

int bfc::main()
{

	ltc_mp = ltm_desc;

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