#pragma once

#include <tomcrypt.h>
#include <string>
#include <blc/blc.hpp>

const int bitsize = 2048;
#define MAX_RSA_SIZE 4096

namespace bkc {
	class rsaKey {
	public:
		rsaKey() = default;
		rsaKey(const std::string &pub, const std::string &priv);
		rsaKey(rsa_key key);
		rsaKey(const rsaKey &other);
		~rsaKey();

		rsaKey		&operator=(const rsaKey &other);

		void		setKey(rsa_key key);
		void		setPub(const std::string &pub);
		void		setPriv(const std::string &priv);
		rsa_key		getKey() const {return(_key);};
		std::string	getPub() const {return(_pub);};
		std::string	getPriv() const {return(_priv);};
		std::string	sign(const std::string &msg) const;
		bool		verify(const std::string &msg, const std::string &sign) const;
		static rsaKey	open(const std::string &pubFile, const std::string &privFile);
		static rsaKey	make();
	private:
		rsa_key			_key;
		std::string		_pub;
		std::string		_priv;
		static std::string	open(const std::string &keyFile);
	};
}