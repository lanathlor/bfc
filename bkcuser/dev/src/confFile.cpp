#include "confFile.hpp"

#include <blc/blc.hpp>
#include <bfc/bfc.hpp>

#include "identity.hpp"

#include "handleKeyParam.hpp"
#include "identity.hpp"

#include "rsaKey.hpp"

#include <stdio.h>
#include <ios>
#include <iomanip>

using json = nlohmann::json;

static void launch(std::string addr, int port)
{

}

json bkc::readConfFile(const std::string &fileName)
{
	std::ifstream file;
	std::string tmp;

	try {
		file.open(fileName);
		long file_size = blc::tools::fileSize(file);
		char *data = new char [file_size];
		file.read(data, file_size);
		file.close();
		tmp = std::string(data, data + file_size);
		delete [] data;
	} catch (blc::error::exception &e) {
		std::cerr << e.what() << std::endl;
		throw blc::error::exception(assertError("error with \"" + fileName + "\" file"));
	}

	nlohmann::json j;
	std::string addr;
	int port;

	try {
		j = nlohmann::json::parse(tmp);
	} catch (blc::error::exception &e) {
		std::cerr << e.what() << std::endl;
		throw blc::error::exception(assertError("error parsing conf file"));
	} catch (nlohmann::detail::parse_error &e) {
		std::cerr << e.what() << std::endl;
		throw blc::error::exception(assertError("error parsing conf file"));
	}

	return (j);
}