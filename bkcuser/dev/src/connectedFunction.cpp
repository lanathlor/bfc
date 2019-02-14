#include <nlohmann/json.hpp>

#include "connectedFunction.hpp"

using json = nlohmann::json;

bkc::trader::trader(const std::string &pubKey, const std::string &privKey, const std::string &addr, int port) : _key(pubKey, privKey), _sock(addr, port)
{
	try {
		this->_sock.setBlock(true);
		this->_sock.open();
	} catch (blc::error::exception &e){
		std::cerr << e.what() << std::endl;
	}
}

bkc::trader::trader(const bkc::rsaKey &key, const std::string &addr, int port) : _key(key), _sock(addr, port)
{
	try {
		this->_sock.setBlock(true);
		this->_sock.open();
	} catch (blc::error::exception &e){
		std::cerr << e.what() << std::endl;
	}
}

bkc::trader::~trader()
{
	json j = {
		{"code", 280},
		{"data", ""},
		{"user", this->_key.printablePub()}
	};

	this->_sock << j.dump() << blc::endl << blc::endl;
	this->_sock.close();
}

double bkc::trader::getBalance(const bkc::rsaKey &key) const
{
	json j = {
		{"code", 490},
		{"data", key.printablePub()},
		{"user", this->_key.printablePub()}
	};

	const_cast<blc::network::Socket &>(this->_sock) << j.dump() << blc::endl << blc::endl;
	std::string tmp = this->_sock.read();
	this->_sock.read();
	j = json::parse(tmp);

	return (j["data"].get<double>());
}

double bkc::trader::getBalance() const
{
	json j = {
		{"code", 490},
		{"data", this->_key.printablePub()},
		{"user", this->_key.printablePub()}
	};

	const_cast<blc::network::Socket &>(this->_sock) << j.dump() << blc::endl << blc::endl;
	std::string tmp = this->_sock.read();
	this->_sock.read();

	j = json::parse(tmp);
	return (j["data"].get<double>());
}

bool bkc::trader::send(const bkc::rsaKey &to, double amount) const
{
	bkc::trans t = bkc::trans::createTrans(this->_key.printablePub(), to.printablePub(), amount, this->_key);
	this->send(t);
	return (true);
}

void bkc::trader::send(const bkc::trans &t) const
{
	json j = {
		{"code", 305},
		{"data", t.serialize()},
		{"user", this->_key.printablePub()}
	};

	const_cast<blc::network::Socket &>(this->_sock) << j.dump() << blc::endl << blc::endl;
	std::string tmp = this->_sock.read();
	this->_sock.read();
	j = json::parse(tmp);

	bkc::trans parity(j["data"]["parity"].get<std::string>());

	parity.setSign(bkc::trans::sign(parity, this->_key));
	this->send(j["data"]["transaction"].get<std::string>(), parity);
}

void bkc::trader::send(const bkc::trans &t, const bkc::trans &parity) const
{
	json data = {
		{"transaction", t.serialize()},
		{"parity", parity.serialize()}
	};
	std::string tmp = data.dump();
	json j = {
		{"code", 310},
		{"data", data.dump()},
		{"user", this->_key.printablePub()}
	};

	if (t.getProof() != "" && parity.getProof() != "" && t.getProof() == parity.getProof() && t.check() && parity.check()){
		std::cout << "transaction send to network" << std::endl;
		const_cast<blc::network::Socket &>(this->_sock) << j.dump() << blc::endl << blc::endl;
	} else {
		std::cout << "not enough found" << std::endl;
	}
}

void bkc::trader::message(const std::string &str) const
{
	json j = {
		{"code", 301},
		{"data", str},
		{"user", this->_key.printablePub()},
	};

	const_cast<blc::network::Socket &>(this->_sock) << j.dump() << blc::endl << blc::endl;
}

// void bkc::trader::load(const std::map<std::string, bkc::rsaKey> &other)
// {
// 	this->_other_keys = other;
// }

// void bkc::trader::addOther(const std::string &alias, const std::string &pubKey)
// {
// 	bkc::rsaKey key;

// 	key.importPub(pubKey);
// 	this->_other_keys.emplace(alias, key);
// }

// void bkc::trader::addOther(const std::string &alias, const bkc::rsaKey &key)
// {
// 	this->_other_keys.emplace(alias, key);
// }

void bkc::trader::generateKey()
{
	this->_key = bkc::rsaKey::make();
}


std::string bkc::trader::getAlias() const
{
	return (this->_alias);
}

bkc::rsaKey bkc::trader::getKey() const
{
	return (this->_key);
}