#include "IRollable.hpp"
#include "gtest/gtest.h"

// Tests IRollable.

// Tests roll with 6 possible values
TEST(IRollableTest, Roll) {
    IRollable r1;
    int rVal = r1.roll(6);
    ASSERT_GT(rVal, 0);
    ASSERT_LE(rVal, 6);
}
