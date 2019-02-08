#include <bfc/masterThread.hpp>
#include "cinConnector.hpp"

void bkc::node::cinCon::cinProto()
{
	this->_cin.add("quit", [=](std::string str){
		this->send(280, str);
		// this->_pipe << "280" << blc::endl << blc::endl;
		return (280);
	});
	this->_cin.add("push", [=](std::string str){
		// this->send(301, str);
		if (bfc::flags::isSet("a") == false)
			bfc::masterThread::actor("adm").send(301, str);
		bfc::masterThread::for_each("peer*", [=](std::map<std::string, blc::tools::pipe>::iterator it){
			bfc::masterThread::actor(it->first).send(301, str);
		});
		 // << "301" << blc::endl;
		// this->_pipe <<  str << blc::endl;
		return (0);
	});
	this->_cin.add("print", [=](std::string str){
		if (str == "p")
			this->send(420);
			// this->_pipe << "420" << blc::endl << blc::endl;
		return (0);
	});
	this->_cin.add("send", [=](std::string str){
		this->send(305, str);
		return (0);
	});
}
