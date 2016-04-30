#include "INameable.hpp"
#include "gtest/gtest.h"

// Tests INameable.

// Should initialize to empty string
TEST(INameableTest, DefaultInit) {
    INameable n;
    ASSERT_STREQ(n.getName().c_str(), "");
}

// Should set name if provided
TEST(INameableTest, NamedInit) {
    INameable n("Test");
    ASSERT_STREQ(n.getName().c_str(), "Test");
}
