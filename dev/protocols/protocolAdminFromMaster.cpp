#include "adminConnector.hpp"

void bkc::node::admCon::masterProto()
{
	this->_masterProto.add(301, [=](std::string str){
		this->_client.getComm() << "301" << blc::endl;
		this->_client.getData() << str << blc::endl;
		return (0);
	});
	this->_masterProto.add(280, [=](std::string str){
		this->_client.getComm() << "280" << blc::endl;
		this->_live = false;
		bfc::masterThread::remove(str);
		return (0);
	});
	this->_masterProto.add(350, [=](std::string str){
		this->_client.getComm() << "350" << blc::endl;
		this->_client.getData() << str << blc::endl;
		return (0);
	});
	this->_masterProto.add(352, [=](std::string str){
		this->_client.getComm() << "352" << blc::endl;
		this->_client.getData() << str << blc::endl;
		return (0);
	});
	this->_masterProto.add(401, [=](std::string str){
		this->_client.getComm() << "401" << blc::endl;
		this->_client.getData() << str << blc::endl;
		return (0);
	});
}
