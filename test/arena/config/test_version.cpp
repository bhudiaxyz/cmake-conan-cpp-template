#include <fmt/core.h>
#include <gtest/gtest.h>

#include "arena/config/project_version.hpp"
#include "arena/config/version.hpp"

// Demonstrate some basic assertions.
TEST(ArenaVersionTest, BasicAssertions) {
    // Expect equality.
    EXPECT_STREQ(arena::config::version().data(), PROJECT_VERSION);

    // Expect equality.
    EXPECT_EQ(arena::config::version(), fmt::format("{}.{}.{}", PROJECT_VERSION_MAJOR, PROJECT_VERSION_MINOR, PROJECT_VERSION_PATCH));

    // Expect equality.
    EXPECT_EQ(7 * 6, 42);
}
