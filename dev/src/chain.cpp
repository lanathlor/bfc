#include "chain.hpp"

bkc::chain::chain(blc::tools::pipe &pipe, std::string name, bkc::rsaKey key, unsigned char admLvl) : actor(pipe, name)
{
	this->load();
}

std::string bkc::chain::serialize() const
{
	return (this->_book.serialize());
}

void bkc::chain::unserialize(const std::string &str)
{
	this->_book.unserialize(str);
}

void bkc::chain::getBalance(std::string key) const
{
}

bkc::trans bkc::chain::searchProof(const bkc::trans &t) const
{
	std::vector<bkc::trans> v = this->_book.getBySender(t.getSender());

	for (auto it : v){
		if (it.getAmount() >= t.getAmount())
			return (it);
	}
	return (bkc::trans());
}

bool bkc::chain::verify(const bkc::trans &t)
{
	if (t.check() == false)
		return (false);
	if (this->_book.find(t) == false)
		return (false);
	return (true);
}

void bkc::chain::add(const bkc::trans &t)
{
	if (this->verify(t)){
		this->_book.add(t);
		bkc::trans tmp = t.getLeftOver();
		this->_book.add(tmp);
	}
}

void bkc::chain::remove(const bkc::trans &t)
{
	this->_book.remove(t);
}

void bkc::chain::dump()
{
	this->_book.dump(bfc::output);
	bfc::output.seekp(0);
}

void bkc::chain::load()
{
	bfc::input.seekg(0);
	this->_book.load(bfc::input);
}

void bkc::chain::readMaster()
{
	int code = std::stoi(this->_pipe.read());
	std::string tmp = this->_pipe.read();

	if (this->_masterProto.activate(code, tmp) == 280)
		this->kill();
}

void bkc::chain::thick()
{
	if (this->_pipe.readable()) {
		this->readMaster();
	}
	this->dump();
}
