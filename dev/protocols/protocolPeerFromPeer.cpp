#include <nlohmann/json.hpp>
#include "peerConnector.hpp"
#include "servConnector.hpp"
#include "connectedPeer.hpp"
#include "rsaKey.hpp"

using json = nlohmann::json;

void bkc::node::peerCon::peerProto()
{
	this->_peerProto.add(280, [=](std::string str){
		this->kill();
		this->send(280, this->getName());
		return (280);
	});
	this->_peerProto.add(301, [=](std::string str){
		json j = json::parse(str);
		bkc::rsaKey key;

		try {
			key.importPub(j["user"].get<std::string>());
			if (key.verifyPrintable(j["data"].get<std::string>(), j["sign"].get<std::string>()))
				this->send(301, j["data"].get<std::string>());
		} catch (json::type_error &e) {
			bfc::cout << this->getName() << ": data badly formated" << blc::endl;
		}
		return (0);
	});
	this->_peerProto.add(302, [=](std::string str){
		json j = json::parse(str);

		this->send(302, j["data"].get<std::string>());
		return (0);
	});
	this->_peerProto.add(350, [=](std::string str){
		json j = json::parse(str);

		this->send(350, j["data"].get<std::string>());
		return (0);
	});
	this->_peerProto.add(352, [=](std::string str){
		json j = json::parse(str);

		this->send(352, this->_client.getAddress() + j["data"].get<std::string>());
		return (0);
	});
	this->_peerProto.add(401, [=](std::string str){
		this->send(401);
		return (0);
	});
}

void bkc::node::servCon::peerProto()
{
	this->_peerProto.add(280, [=](std::string str){
		this->kill();
		this->send(280, this->getName());
		return (280);
	});
	this->_peerProto.add(301, [=](std::string str){
		json j = json::parse(str);
		bkc::rsaKey key;

		try {
			key.importPub(j["user"].get<std::string>());
			if (key.verifyPrintable(j["data"].get<std::string>(), j["sign"].get<std::string>()))
				this->send(301, j["data"].get<std::string>());
		} catch (json::type_error &e) {
			bfc::cout << this->getName() << ": data badly formated" << blc::endl;
		}
		this->send(301, j["data"].get<std::string>());
		return (0);
	});
	this->_peerProto.add(302, [=](std::string str){
		json j = json::parse(str);

		this->send(302, j["data"].get<std::string>());
		return (0);
	});
	this->_peerProto.add(350, [=](std::string str){
		json j = json::parse(str);

		this->send(350, j["data"].get<std::string>());
		return (0);
	});
	this->_peerProto.add(352, [=](std::string str){
		json j = json::parse(str);

		this->send(352, this->_client.getAddress() + ":" + j["data"].get<std::string>());
		return (0);
	});
	this->_peerProto.add(401, [=](std::string str){
		this->send(401);
		return (0);
	});
}