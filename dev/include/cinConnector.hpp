#pragma once

#include <blc/blc.hpp>
#include <bfc/bfc.hpp>

namespace bkc {
	namespace node {
		class cinCon : public bfc::actor<cinCon> {
		public:
			cinCon() = delete;
			cinCon(blc::tools::pipe &pipe, std::string name);

			void masterProto();
			void cinProto();

			void readCin();
			void readMaster();
			void thick();
		private:
			blc::tools::protocolFactory<std::string, std::string>	_cin;
		};
	}
}