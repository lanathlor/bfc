#include <bfc/bfc.hpp>

void bfc::masterThread::servProto()
{
	this->_serv.add(301, [](std::string str){
		std::cout << str << std::endl;
		return (0);
	});
}
