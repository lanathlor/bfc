#include "initChain.hpp"
#include "getMyIp.hpp"

static bool isYes(const std::string &str)
{
	for (auto it : bkc::yes){
		if (it == str)
			return (true);
	}
	return (false);
}

static bool isNo(const std::string &str)
{
	for (auto it : bkc::no){
		if (it == str)
			return (true);
	}
	return (false);
}

static bool outDef(bool def)
{
	std::string tmp;

	if (!def)
		std::cout << "[y/N]: " << bkc::def;
	else
		std::cout << "[Y/n]: " << bkc::def;
	std::getline(std::cin, tmp);
	if (!def)
		return (isYes(tmp));
	return (!isNo(tmp));
}

static std::string outDefStr(const std::string &str)
{
	std::string tmp;

	std::cout << "default [" << str << "] : " << bkc::def;
	std::getline(std::cin, tmp);
	if (tmp == "")
		return (str);
	return (tmp);
}

std::string bkc::initChain()
{
	try {
		std::string chainName = bfc::flags::getValue("init");
		if (chainName == "init"){
			std::cout << red << "bad chain name : " << def << chainName << std::endl;
			std::cout << green << "enter a valid chain name. ";
			chainName = outDefStr("test");
		}
		std::cout << green << "enter name of configuration file. ";
		std::string filename = outDefStr("./conf.bkc");
		std::cout << green << "level of administation on the chain : 1-4. ";
		int adm = std::stoi(outDefStr("4"));
		std::ofstream o(filename);
		std::cout << green << "enter ip of admin host. " << def;
		std::string ip = outDefStr(bkc::getMyIp());
		std::cout << green << "enter port of admin host. ";
		int port = std::stoi(outDefStr("5000"));

		o << "{" << std::endl << "\t\"name\" : \"" << chainName << "\"," << std::endl << "\t\"ip\": \"" << ip << "\"," << std::endl << "\t\"port\": " << port << "," << std::endl << "\t\"adm_lvl\": " << adm << std::endl << "}";
		if (bfc::flags::isSet("use")){
			return (filename);
		}
	} catch (std::invalid_argument &e) {
		std::cerr << red << "bad number given" << std::endl;
	}
	bfc::exit();
	return ("");
}
