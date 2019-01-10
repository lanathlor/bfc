#include <algorithm>
#include <bfc/bfc.hpp>

#include "peerConnector.hpp"
#include "connectedPeer.hpp"

void bfc::masterThread::peerProto()
{
	this->_peer.add(280, [](std::string str){
		bfc::masterThread::remove(str);
		return (0);
	});
	this->_peer.add(301, [](std::string str){
		std::cout << str << std::endl;
		return (0);
	});
	this->_adm.add(302, [this](std::string str){
		for (int i = str.find(';'); i != std::string::npos; i = str.find(';')){
			std::string tmp = blc::tools::serializable::cut(str, ';');
			if (std::find(this->_knownPeer.begin(), this->_knownPeer.end(), tmp) == this->_knownPeer.end() && tmp != bfc::masterThread::_myself){
				int port = 0;
				std::string addr = tmp.substr(0, tmp.find(':'));

				try {
					port = std::stoi(tmp.substr(tmp.find(':') + 1, tmp.size()));
				} catch (blc::error::exception &e) {
					bfc::cout << tmp.substr(tmp.find(':') + 1, tmp.size()) << blc::endl;
					throw blc::error::exception("bad number");
				}

				this->_knownPeer.push_back(tmp);
				if (bkc::connectedPeer::isConnected(addr, port) == true) {
					std::cout << tmp << " is duble" << std::endl;
				} else {
					bfc::factory<bkc::node::peerCon>("peerClient" + std::to_string(std::rand()), addr, port);
					bkc::connectedPeer::connect(addr, port);
				}
				bfc::cout << "new peer : " << tmp << blc::endl;
			}
		}
		return (0);
	});
	this->_adm.add(303, [this](std::string str){
		for (auto it = this->_knownPeer.begin(); it != this->_knownPeer.end(); it++){
			if (*it == str){
				this->_knownPeer.erase(it);
			}
		}
		return (0);
	});
	this->_peer.add(350, [](std::string str){
		bfc::cout << "username : " << str << blc::endl;

		return (0);
	});
	this->_peer.add(352, [](std::string str){
		bkc::connectedPeer::connect(str);

		return (0);
	});
}
