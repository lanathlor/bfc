#include "aliasMap.hpp"

bkc::user::aliasMap bkc::user::alias;

bkc::user::aliasMap::aliasMap()
{
}

bkc::user::aliasMap::aliasMap(const bkc::user::aliasMap &other)
{
	this->_map = other._map;
}

std::string bkc::user::aliasMap::serialize() const
{
	std::string str;

	for (auto it = this->_map.begin(); it != this->_map.end(); it++){
		str += it->first + ":" + it->second + ";";
	}
	return (str);
}

void bkc::user::aliasMap::unserialize(const std::string &str)
{
	std::string data = str;

	for (auto tmp = this->cut(data, ';'); data != ""; tmp = this->cut(data, ';')){
		std::string alias = this->cut(tmp, ':');
		this->add(alias, tmp);
	}
}

void bkc::user::aliasMap::add(const std::string &alias, const std::string &key)
{
	this->_map.emplace(alias, key);
}

std::string bkc::user::aliasMap::pub(const std::string &alias)
{
	if (this->_map.count(alias) == 0)
		throw blc::error::exception(std::string("no known user alias: ") + alias);
	return (this->_map[alias]);
}

bkc::rsaKey bkc::user::aliasMap::key(const std::string &alias)
{
	if (this->_map.count(alias) == 0)
		throw blc::error::exception(std::string("no known user alias: ") + alias);
	bkc::rsaKey key;

	key.importPub(this->_map[alias]);
	return (key);
}


void bkc::user::aliasMap::load(std::istream &stream)
{
	std::string str;

	for (std::getline(stream, str); str != ""; std::getline(stream, str)){
		std::string alias = this->cut(str, ':');
		this->add(alias, str);
	}
}

void bkc::user::aliasMap::dump(std::ostream &stream)
{
	for (auto it = this->_map.begin(); it != this->_map.end(); it++){
		stream << it->first << ":" << it->second << std::endl;
	}
}


bkc::user::aliasMap &bkc::user::aliasMap::operator=(const bkc::user::aliasMap &other)
{
	this->_map = other._map;
}

bkc::user::aliasMap &bkc::user::aliasMap::operator+(const std::pair<std::string, std::string> &alias)
{
	this->_map.emplace(alias);
}
