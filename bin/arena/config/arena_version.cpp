#include <functional>

#include "arena/common/log.hpp"
#include "arena/config/version.hpp"

int main(int argc, char const **argv) {
    arena::logger_init(argv[0]);

    const std::string_view version = arena::config::version();
    spdlog::info("Project Version: {}", version);
    spdlog::info("Project Version hash: {}", std::hash<std::string_view>{}(version));

    return EXIT_SUCCESS;
}
