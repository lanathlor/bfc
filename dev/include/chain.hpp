#pragma once

#include <blc/blc.hpp>
#include <bfc/bfc.hpp>

#include "book.hpp"
#include "trans.hpp"
#include "rsaKey.hpp"

namespace bkc {
	class chain : public bfc::actor<bkc::chain>, public blc::tools::serializable {
	public:
		chain() = delete;
		chain(blc::tools::pipe &pipe, std::string name, bkc::rsaKey key, unsigned char admLvl);

		void masterProto();

		void readMaster();
		void thick();

		std::string 	serialize() const;
		void		unserialize(const std::string &str);
		void		getBalance(std::string key) const;
		bkc::trans	searchProof(const bkc::trans &t) const;
	protected:
		bool		verify(const bkc::trans &t);
		void		add(const bkc::trans &t);
		void		remove(const bkc::trans &t);
		void		dump();
		void		load();
	private:
		unsigned char				_admLvl;
		bkc::rsaKey				_admKey;
		bkc::book				_book;
		std::mutex				_access;
	};
}