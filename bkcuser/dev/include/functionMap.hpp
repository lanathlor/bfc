#pragma once

#include <blc/blc.hpp>
#include <nlohmann/json.hpp>
#include "connectedFunction.hpp"

using json = nlohmann::json;

namespace bkc {
	namespace user {
		class functionMap : public blc::tools::protocolFactory<std::string, std::pair<json, bkc::trader &>>{
		public:
			functionMap();
			void call(bkc::trader &trader, json j);
		private:
		};
	}
}
