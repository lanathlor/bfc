#pragma once

#include <string>
#include "identity.hpp"
#include "trans.hpp"

namespace bkc {
	class trader : public blc::tools::nonCopyable {
	public:
		trader() = delete;
		trader(const std::string &pubKey, const std::string &privKey, const std::string &add, int port);
		trader(const bkc::rsaKey &key, const std::string &add, int port);
		~trader();

		double 	getBalance(const bkc::rsaKey &key) const;
		double	getBalance() const;
		bool	send(const bkc::rsaKey &to, double amount) const;
		void	send(const bkc::trans &t) const;
		void	send(const bkc::trans &t, const bkc::trans &parity) const;
		void	message(const std::string &str) const;
		bool	init(const std::string &addr, int port);
		void	generateKey();

		std::string	getAlias() const;
		bkc::rsaKey	getKey() const;
	protected:
	private:
		std::string				_alias;
		bkc::rsaKey				_key;
		blc::network::Socket			_sock;
			// std::map<std::string, bkc::rsaKey>	_other_keys;
	};
}