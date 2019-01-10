#include "initChain.hpp"

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

	std::cout << str << ": " << bkc::def;
	std::getline(std::cin, tmp);
	if (tmp == "")
		return (str);
	return (tmp);
}

bool bkc::initChain()
{
	std::cout << green << "create file ";
	std::string filename = outDefStr("./conf.bkc");
	std::ofstream o(filename);
	std::cout << green << "default ip is ";
	std::string ip = outDefStr("127.0.0.1");
	std::cout << green << "default port is ";
	int port = std::stoi(outDefStr("5000"));

	o << "{" << std::endl << "\t\"ip\": \"" << ip << "\"," << std::endl <<"\t\"port\": " << port << std::endl << "}";
	if (bfc::flags::isSet("use")){
		return (true);
	}
	bfc::exit();
	return (false);
}
