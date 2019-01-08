#include <blc/blc.hpp>
#include <nlohmann/json.hpp>
#include <bfc/bfc.hpp>
#include "adminConnector.hpp"
#include "cinConnector.hpp"
#include "peerServer.hpp"
#include "identity.hpp"

#include "handleKeyParam.hpp"
#include "confFile.hpp"

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

void bfc::initActor()
{
	if (handleKey() == false)
		return;
	if (bfc::flags::isSet("conf")) {
		readConfFile(bfc::flags::getValue("conf"));
	} else {
		readConfFile("conf.bkc");
	}
}

int bfc::main()
{

	ltc_mp = ltm_desc;
	try {
		if (bfc::flags::isSet("a") == false) {
			int port = blc::network::findFreePort();

			std::cout << port << std::endl;
			bfc::masterThread::actor("adm").send(352, std::to_string(port));
			bfc::masterThread::actor("adm").send(350, "lanath");
			bfc::masterThread::actor("adm").send(301, std::to_string(port));
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