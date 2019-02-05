#include "book.hpp"

bkc::book::book()
{
}

bkc::book::book(std::string filename)
{
}

bkc::book::book(const bkc::book &other)
{
}

void bkc::book::add(const bkc::trans &t)
{
}

void bkc::book::remove(const bkc::trans &t)
{
}

bool bkc::book::find(const bkc::trans &t)
{
}

std::vector<bkc::trans> bkc::book::getBySender(const std::string &key)
{
}

std::vector<bkc::trans> bkc::book::getByReceiver(const std::string &key)
{
}

std::vector<bkc::trans> bkc::book::getBySign(const std::string &key)
{
}

std::vector<bkc::trans> bkc::book::getByProof(const std::string &key)
{
}

std::vector<bkc::trans> bkc::book::getByAmount(int time)
{
}

std::vector<bkc::trans> bkc::book::getByTime(double amount)
{
}

std::string bkc::book::serialize() const
{
}

void bkc::book::unserialize(const std::string &str)
{
}

bkc::book bkc::book::operator=(const bkc::book &other)
{
}