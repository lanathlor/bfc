#pragma once

#include <blc/blc.hpp>
#include <bfc/bfc.hpp>

namespace bkc {
	class chain : public bfc::actor<bkc::chain>, public blc::tools::serializable {
	public:
		chain() = delete;
		chain(blc::tools::pipe &pipe, std::string name);

		void masterProto();

		void readMaster();
		void thick();

		std::string 	serialize() const;
		void		unserialize(const std::string &str);
	protected:
		void load(std::string);
		void load(std::vector<std::string> data);

		bool check(std::string data) const;

		void save(std::string data);

		void del(std::string data);

		std::vector<std::string> dump();
	private:
		unsigned char				_admLvl;
		std::map<int, std::string>		_book;
		std::mutex				_access;
	};
}