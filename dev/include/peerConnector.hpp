#pragma once

#include <blc/blc.hpp>
#include <bfc/bfc.hpp>

namespace bkc {
	namespace node {
		class peerCon : public bfc::actor<peerCon> {
		public:
			peerCon() = delete;
			peerCon(blc::tools::pipe pipe, std::string name, std::string addr, int port);

			void peerProto();
			void masterProto();

			void readMaster();
			void readPeer();

			void thick();
		private:
			blc::tools::protocolFactory<int, std::string>	_peerProto;
			blc::network::Socket				_client;
		};
	}
}