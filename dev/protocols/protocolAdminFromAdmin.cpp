#include <nlohmann/json.hpp>
#include "adminConnector.hpp"

using json = nlohmann::json;

void bkc::node::admCon::admProto()
{
	this->_admProto.add(301, [=](std::string str){
		json j = json::parse(str);

		this->send(301, j["data"].get<std::string>());
		// this->_pipe << "301" << blc::endl;
		// this->_pipe << str << blc::endl;
		return (0);
	});
	this->_admProto.add(302, [=](std::string str){
		this->_pipe << "302" << blc::endl;
		this->_pipe << str << blc::endl;
		return (0);
	});
	this->_admProto.add(300, [=](std::string str){
		this->_pipe << "300" << blc::endl;
		this->_pipe << str << blc::endl;
		return (0);
	});
	this->_admProto.add(280, [=](std::string str){
		this->kill();
		this->send(280, this->getName());
		return (280);
	});
	this->_admProto.add(350, [=](std::string str){
		json j = json::parse(str);

		this->send(301, j["data"]);
		return (0);
	});
	this->_admProto.add(352, [=](std::string str){
		json j = json::parse(str);

		this->send(301, j["data"]);
		return (0);
	});
	this->_admProto.add(401, [=](std::string str){
		json j = json::parse(str);

		this->send(301, j["data"]);
		return (0);
	});
}
