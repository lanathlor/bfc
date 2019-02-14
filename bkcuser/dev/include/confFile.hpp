#pragma once

#include <nlohmann/json.hpp>

namespace bkc {
	nlohmann::json readConfFile(const std::string &fileName);
}