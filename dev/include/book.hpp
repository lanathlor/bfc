#pragma once

#include <blc/blc.hpp>
#include "trans.hpp"

namespace bkc {
	class book : bkc::tools::serializable {
	public:
		book();
		book(std::string filename);
		book(const book &other);

		void	add(const bkc::trans &t);
		void	remove(const bkc::trans &t);
		bool	find(const bkc::trans &t);

		std::vector<bkc::trans>	getBySender(const std::string &key);
		std::vector<bkc::trans>	getByReceiver(const std::string &key);
		std::vector<bkc::trans>	getBySign(const std::string &key);
		std::vector<bkc::trans>	getByProof(const std::string &key);
		std::vector<bkc::trans>	getByAmount(int time);
		std::vector<bkc::trans>	getByTime(double amount);

		std::string 	serialize() const;
		void		unserialize(const std::string &str);

		book operator=(const book &other);
	private:
		std::map<std::string, std::vector<bkc::trans *>> _bySender;
		std::map<std::string, std::vector<bkc::trans *>> _byReceiver;
		std::map<std::string, bkc::trans> _bySign;
		std::map<std::string, std::vector<bkc::trans *>> _byProof;
		std::map<double, std::vector<bkc::trans *>> _byAmount;
		std::map<int, std::vector<bkc::trans *>> _byTime;
	};
}