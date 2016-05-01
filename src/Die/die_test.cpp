#include <limits.h>
#include "die.hpp"
#include "gtest/gtest.h"

// Tests Die().

// Tests die with unweighted sides.
TEST(DieTest, Unweighted) {
    Die d;
    ASSERT_EQ(1, d.getLoadedSide());
    ASSERT_EQ(1, d.getLoadAmount());
}

// Tests die with a weighted side.
TEST(DieTest, Weighted) {
    Die d("TestDie1", 10, 3);
    ASSERT_EQ(10, d.getLoadAmount());
    ASSERT_EQ(3, d.getLoadedSide());
}

// Tests rolling a die
TEST(DieTest, Roll) {
    Die d("TestDie2");
    int val = d.roll();
    ASSERT_LT(0, val); // "0 is less than val"
    ASSERT_GE(6, val); // "6 is greater than or equal to val"
}

// Tests rolling a weighted die
TEST(DieTest, RollWeighted) {
    Die d("TestDie3", 1000000000, 3);
    int val = d.roll();
    EXPECT_EQ(3, val);
    val = d.roll();
    EXPECT_EQ(3, val);
}

// Should print summary
TEST(DieTest, PrintSummary) {
    Die d("TestDie4");

    d.roll();
    d.roll();
    d.roll();
    d.roll();
    d.roll();
    d.roll();

    d.Print();
}
