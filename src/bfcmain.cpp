#include <vector>
#include <string>
#include <blc/blcmain.hpp>
#include "bfc/bfcmain.hpp"
#include "bfc/flag.hpp"
#include "bfc/masterThread.hpp"
#include "bfc/exit.hpp"

#include <tomcrypt.h>

int blc::main(int ac, std::vector<std::string> av, std::vector<std::string> env)
{
	int ret = 0;
	ltc_mp = ltm_desc;

	bfc::masterThread &master = bfc::masterThread::init();

	if (bfc::_exit == true)
		return (ret);

	try {
		bfc::flags::init(av);
	} catch (blc::error::exception &e) {
		std::cerr << "bfc: error in initialisation : " << e.what() << std::endl;
	}

	if (bfc::ReqFlags){
		try {
			std::vector<std::string> req = bfc::ReqFlags();
			if (bfc::flags::check(req) == false)
				throw blc::error::exception(assertError("Bad flags"));
		} catch (blc::error::exception &e) {
			std::cerr << e.what() << std::endl;
			throw blc::error::exception(assertError(""));
		}
	}

	if (bfc::_exit == true)
		return (ret);

	if (bfc::initActor){
		try {
			bfc::initActor();
		} catch (blc::error::exception &e) {
			std::cerr << e.what() << std::endl;
			throw blc::error::exception(assertError("bfc: error in initActor or below"));
		}
	}

	if (bfc::_exit == true)
		return (ret);

	try {
		ret = bfc::main();
	} catch (blc::error::exception &e) {
		std::cerr << e.what() << std::endl;
		throw blc::error::exception(assertError("bfc: error in main or below"));
	}

	if (bfc::_exit == true)
		return (ret);

	try {
		master.lifeCycle();
	} catch (blc::error::exception &e) {
		std::cerr << e.what() << std::endl;
		throw blc::error::exception(assertError("bfc: error in master.lifeCycle or below"));
	}

	return (ret);
}