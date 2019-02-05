#include "book.hpp"

book()
{
}

book(std::string filename)
{
}

book(const book &other)
{
}

void	add(const bkc::trans &t)
{
}

void	remove(const bkc::trans &t)
{
}

bool	find(const bkc::trans &t)
{
}

std::vector<bkc::trans>	getBySender(const std::string &key)
{
}

std::vector<bkc::trans>	getByReceiver(const std::string &key)
{
}

std::vector<bkc::trans>	getBySign(const std::string &key)
{
}

std::vector<bkc::trans>	getByProof(const std::string &key)
{
}

std::vector<bkc::trans>	getByAmount(int time)
{
}

std::vector<bkc::trans>	getByTime(double amount)
{
}

std::string 	serialize() const
{
}

void		unserialize(const std::string &str)
{
}

book operator=(const book &other);