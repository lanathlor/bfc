#include "chain.hpp"

void bkc::chain::masterProto()
{
	this->_masterProto.add(280, [=](std::string str){
		bfc::masterThread::remove(str);
		return (280);
	});
	this->_masterProto.add(305, [=](std::string str){
		bkc::trans t(str);

		if (t.getProof() == "")
			t.setProof(this->searchProof(t));
		std::cout << this->verify(t) << std::endl;
		if (this->verify(t) == true){
			this->_book.add(t);
			this->consum(t.getProof());
		}
		return (1);
	});
}
