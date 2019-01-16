#include <bfc/bfc.hpp>

void bfc::masterThread::cinProto()
{
	this->_cin.add(280, [](std::pair<std::map<std::string, blc::tools::pipe>::iterator, std::string> data){
		bfc::masterThread::kill();
		return (0);
	});
	this->_cin.add(301, [](std::pair<std::map<std::string, blc::tools::pipe>::iterator, std::string> data){
		if (bfc::flags::isSet("a") == false)
			bfc::masterThread::actor("adm").send(301, data.second);
		// bfc::masterThread::masterPipe["adm"] << str << blc::endl;
		bfc::masterThread::for_each("peer*", [=](std::map<std::string, blc::tools::pipe>::iterator it){
			bfc::masterThread::actor(it->first).send(301, data.second);
		});
		return (0);
	});
	this->_cin.add(420, [this](std::pair<std::map<std::string, blc::tools::pipe>::iterator, std::string> data){
		for (auto it = this->_knownPeer.begin(); it != this->_knownPeer.end(); it++){
			std::cout << *it << std::endl;
		}
		return (0);
	});
}
