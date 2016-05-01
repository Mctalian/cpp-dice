#include "DieInterfaces.hpp"
#include "gtest/gtest.h"

// Tests DieInterfaces.

// Should roll within 1 and the max value
TEST(DieInterfacesTest, Roll) {
    DieInterfaces di;
    int rVal = di.roll();
    ASSERT_GT(rVal, 0);
    ASSERT_LE(rVal, 6);
}

// Should roll a 3 almost always
TEST(DieInterfacesTest, WeightedRoll) {
    DieInterfaces di("Die1", 1000000000, 3);
    int rVal = di.roll();
    EXPECT_EQ(rVal, 3);

    rVal = di.roll();
    EXPECT_EQ(rVal, 3);
}

// Should correctly log the roll
TEST(DieInterfacesTest, LogRoll) {
    DieInterfaces di;
    int rVal = di.roll();
    ASSERT_EQ(rVal, di.getLastRoll());
    ASSERT_EQ(di.getRollsForSide(rVal), 1);
    ASSERT_EQ(di.getNumRolls(), 1);
}
