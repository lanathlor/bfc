#include <bfc/bfc.hpp>
#include "functionMap.hpp"
#include "aliasMap.hpp"

bkc::user::functionMap::functionMap()
{
	this->add("msg", [](std::pair<json, bkc::trader &> data){
		data.second.message(data.first["to"].get<std::string>());
		return (0);
	});
	this->add("send", [](std::pair<json, bkc::trader &> data){
		bkc::rsaKey key;

		std::string pub = bkc::user::alias.pub(data.first["to"].get<std::string>());
		key.importPub(pub);
		data.second.send(key, data.first["amount"].get<double>());
		return (0);
	});
	this->add("balance", [](std::pair<json, bkc::trader &> data){
		std::cout << data.second.getBalance() << std::endl;

		return (0);
	});
	this->add("add", [](std::pair<json, bkc::trader &> data){
		std::string key;
		if (bfc::flags::isSet("new")){
			std::ifstream is;

			is.open(bfc::flags::getValue("new"));
			std::getline(is, key);
		} else {
			std::getline(std::cin, key);
		}
		bkc::user::alias.add(data.first["to"].get<std::string>(), key);

		return (0);
	});
	this->add("toPrint", [](std::pair<json, bkc::trader &> data){
		if (bfc::flags::isSet("new")){
			bkc::rsaKey key = bkc::rsaKey::open("./public_key.der", bfc::flags::getValue("new"));
			std::cout << key.printablePriv() << std::endl;
		}
		return (0);
	});
}

void bkc::user::functionMap::call(bkc::trader &user, json j)
{
	this->activate(j["code"], std::pair<json, bkc::trader &>(j, user));
}
