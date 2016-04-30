#include <limits.h>
#include "die.hpp"
#include "gtest/gtest.h"

// Tests Die().

// Tests die with unweighted sides.
TEST(DieTest, Unweighted) {
    Die d0;
    ASSERT_EQ(1, d0.getLoadedSide());
    ASSERT_EQ(1, d0.getLoadAmount());
}

// Tests die with a weighted side.
TEST(DieTest, Weighted) {
    Die d1("TestDie1", 10, 3);
    ASSERT_EQ(10, d1.getLoadAmount());
    ASSERT_EQ(3, d1.getLoadedSide());
}

// Tests rolling a die
TEST(DieTest, Roll) {
    Die d2("TestDie2");
    int val = d2.roll();
    ASSERT_LT(0, val); // "0 is less than val"
    ASSERT_GE(6, val); // "6 is greater than or equal to val"
}

// Tests rolling a weighted die
TEST(DieTest, RollWeighted) {
    Die d3("TestDie3", 1000000000, 3);
    int val = d3.roll();
    EXPECT_EQ(3, val);
    val = d3.roll();
    EXPECT_EQ(3, val);
}
