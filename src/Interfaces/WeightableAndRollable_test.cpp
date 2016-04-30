#include "WeightableAndRollable.hpp"
#include "gtest/gtest.h"

// Tests WeightableAndRollable.

// Should roll within 1 and the max value
TEST(WeightableAndRollableTest, Roll) {
    WeightableAndRollable wr;
    int rVal = wr.roll();
    ASSERT_GT(rVal, 0);
    ASSERT_LE(rVal, 6);
}

// Should roll a 3 almost always
TEST(WeightableAndRollableTest, WeightedRoll) {
    WeightableAndRollable wr(1000000000, 3);
    int rVal = wr.roll();
    EXPECT_EQ(rVal, 3);

    rVal = wr.roll();
    EXPECT_EQ(rVal, 3);
}
