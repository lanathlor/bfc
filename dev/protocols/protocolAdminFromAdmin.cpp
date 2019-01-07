#include "adminConnector.hpp"

void bkc::node::admCon::admProto()
{
	this->_admProto.add(301, [=](std::string str){
		this->send(301, str);
		return (0);
	});
	this->_admProto.add(302, [=](std::string str){
		this->send(302, str);
		return (0);
	});
	this->_admProto.add(300, [=](std::string str){
		this->send(300, str);
		return (0);
	});
	this->_admProto.add(280, [=](std::string str){
		this->send(280);
		return (280);
	});
}
