#include <bfc/bfc.hpp>

void bfc::masterThread::peerProto()
{
	this->_peer.add(301, [](std::string str){
		std::cout << str << std::endl;
		return (0);
	});
	this->_peer.add(280, [](std::string str){
		bfc::masterThread::remove(str);
		return (0);
	});
}
