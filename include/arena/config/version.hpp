#ifndef _ARENA_CONFIG_VERSION_H_
#define _ARENA_CONFIG_VERSION_H_

#include <string_view>

#include "arena/config/project_version.hpp"

namespace arena {

namespace config {

static std::string_view constexpr version() {return PROJECT_VERSION; }

}  // namespace config

}  // namespace arena

#endif  // _ARENA_CONFIG_VERSION_H_
