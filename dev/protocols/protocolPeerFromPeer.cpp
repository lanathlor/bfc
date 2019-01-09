#include <nlohmann/json.hpp>
#include "peerConnector.hpp"
#include "servConnector.hpp"

using json = nlohmann::json;

void bkc::node::peerCon::peerProto()
{
	this->_peerProto.add(301, [=](std::string str){
		json j = json::parse(str);

		this->send(301, j["data"].get<std::string>());
		// this->_pipe << "301" << blc::endl;
		// this->_pipe << str << blc::endl;
		return (0);
	});
	this->_peerProto.add(302, [=](std::string str){
		this->_pipe << "302" << blc::endl;
		this->_pipe << str << blc::endl;
		return (0);
	});
	this->_peerProto.add(300, [=](std::string str){
		this->_pipe << "300" << blc::endl;
		this->_pipe << str << blc::endl;
		return (0);
	});
	this->_peerProto.add(280, [=](std::string str){
		this->kill();
		this->send(280, this->getName());
		return (280);
	});
	this->_peerProto.add(350, [=](std::string str){
		json j = json::parse(str);

		this->send(301, j["data"].get<std::string>());
		return (0);
	});
	this->_peerProto.add(352, [=](std::string str){
		json j = json::parse(str);

		this->send(352, this->_client.getAddress() + j["data"].get<std::string>());
		this->send(301, j["data"].get<std::string>());
		return (0);
	});
	this->_peerProto.add(401, [=](std::string str){
		json j = json::parse(str);

		this->send(301, j["data"].get<std::string>());
		return (0);
	});
}

void bkc::node::servCon::peerProto()
{
	this->_peerProto.add(301, [=](std::string str){
		json j = json::parse(str);

		this->send(301, j["data"].get<std::string>());
		// this->_pipe << "301" << blc::endl;
		// this->_pipe << "ok" << blc::endl;
		return (0);
	});
	this->_peerProto.add(302, [=](std::string str){
		this->_pipe << "302" << blc::endl;
		this->_pipe << str << blc::endl;
		return (0);
	});
	this->_peerProto.add(300, [=](std::string str){
		this->_pipe << "300" << blc::endl;
		this->_pipe << str << blc::endl;
		return (0);
	});
	this->_peerProto.add(280, [=](std::string str){
		this->kill();
		this->send(280, this->getName());
		return (280);
	});
	this->_peerProto.add(350, [=](std::string str){
		json j = json::parse(str);

		this->send(301, j["data"].get<std::string>());
		return (0);
	});
	this->_peerProto.add(352, [=](std::string str){
		json j = json::parse(str);

		this->send(352, this->_client.getAddress() + j["data"].get<std::string>());
		this->send(301, std::string("port : ") + j["data"].get<std::string>());
		return (0);
	});
	this->_peerProto.add(401, [=](std::string str){
		json j = json::parse(str);

		this->send(301, j["data"].get<std::string>());
		return (0);
	});
}