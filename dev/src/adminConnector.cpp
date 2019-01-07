#include "adminConnector.hpp"

bkc::node::admCon::admCon(blc::tools::pipe &pipe, std::string name, std::string addr, int port) : actor(pipe, name), _client(addr, port, true)
{
	this->admProto();
	this->masterProto();

	this->_client.openComm();
	this->_client.setPortData(std::stoi(this->_client.read()));
	this->_client.setBlockData(true);
	this->_client.setTypeData(PF_INET);
	this->_client.openData();

	this->start();
}

void bkc::node::admCon::readMaster()
{
	int code = 0;
	std::string data = this->_pipe.read();
	try {
		code = std::stoi(data);
	} catch (std::exception &e) {
		bfc::cout << "error: master code was:" << data << blc::endl;
	}
	std::string tmp = this->_pipe.read();

	if (this->_masterProto.activate(code, tmp) == 280){
		this->kill();
	}
}

void bkc::node::admCon::readAdm()
{
	int code = 0;
	std::string data = this->_client.read();
	try {
		code = std::stoi(data);
	} catch (std::exception &e) {
		bfc::cout << "error: client code was:" << data << blc::endl;
	}
	std::string tmp = this->_client.readData();

	if (this->_admProto.activate(code, tmp) == 280)
		this->kill();
}

void bkc::node::admCon::thick()
{
	while (this->isAlive()){
		if (this->_pipe.readable())
			this->readMaster();
		else if (this->_client.readableComm())
			this->readAdm();
		std::this_thread::sleep_for(std::chrono::duration<double, std::milli>(5));
	}
	this->_client.close();
}
