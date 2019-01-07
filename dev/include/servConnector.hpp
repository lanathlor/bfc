#pragma once

#include <blc/blc.hpp>
#include <bfc/bfc.hpp>

namespace bkc {
	namespace node {
		class servCon : public bfc::actor<servCon> {
		public:
			servCon() = delete;
			servCon(blc::tools::pipe pipe, std::string name, int sock, struct sockaddr client);

			void peerProto();
			void masterProto();

			void readMaster();
			void readPeer();

			void serviceLoop(blc::network::Client &cient, blc::network::Client &data);
			void thick();
		private:
			blc::tools::protocolFactory<int, std::string>	_peerProto;
			bool						_live;

			blc::network::Client				_client;
			blc::network::Client				*_data;
		};
	}
}