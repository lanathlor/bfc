#include <nlohmann/json.hpp>
#include "adminConnector.hpp"

using json = nlohmann::json;

void bkc::node::admCon::masterProto()
{
	this->_masterProto.add(301, [=](std::string str){
		json j = {
			{"code", 301},
			{"data", str},
			{"user", "lanath"}
		};

		this->_client << j.dump() << blc::endl << blc::endl;
		return (0);
	});
	this->_masterProto.add(280, [=](std::string str){
		json j = {
			{"code", 280},
			{"data", ""},
			{"user", "lanath"}
		};

		this->_client << j.dump() << blc::endl << blc::endl;
		this->kill();
		bfc::masterThread::remove(str);
		return (0);
	});
	this->_masterProto.add(350, [=](std::string str){
		json j = {
			{"code", 350},
			{"data", str},
			{"user", "lanath"}
		};

		this->_client << j.dump() << blc::endl << blc::endl;
		return (0);
	});
	this->_masterProto.add(352, [=](std::string str){
		json j = {
			{"code", 352},
			{"data", str},
			{"user", "lanath"}
		};

		this->_client << j.dump() << blc::endl << blc::endl;
		return (0);
	});
	this->_masterProto.add(401, [=](std::string str){
		json j = {
			{"code", 401},
			{"data", str},
			{"user", "lanath"}
		};

		this->_client << j.dump() << blc::endl << blc::endl;
		return (0);
	});
}
