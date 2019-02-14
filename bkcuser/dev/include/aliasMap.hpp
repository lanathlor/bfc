#pragma once

#include <blc/blc.hpp>
#include "rsaKey.hpp"

namespace bkc {
	namespace user {
		class aliasMap : public blc::tools::serializable {
		public:
			aliasMap();
			aliasMap(const aliasMap &other);

			std::string 	serialize() const;
			void		unserialize(const std::string &str);
			void		add(const std::string &alias, const std::string &key);
			std::string	pub(const std::string &alias);
			bkc::rsaKey	key(const std::string &alias);

			void		load(std::istream &stream);
			void		dump(std::ostream &stream);

			aliasMap	&operator=(const aliasMap &other);
			aliasMap	&operator+(const std::pair<std::string, std::string> &alias);
		private:
			std::map<std::string, std::string>	_map;
		};
		extern aliasMap alias;
	}
}