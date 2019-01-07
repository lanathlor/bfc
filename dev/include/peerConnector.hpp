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
			blc::tools::pipe				_pipe;
			blc::tools::protocolFactory<int, std::string>	_peerProto;
			blc::tools::protocolFactory<int, std::string>	_masterProto;
			blc::network::Socket				_client;
			bool						_live;
		};
	}
}