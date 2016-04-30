#include "IHistorical.hpp"
#include "gtest/gtest.h"

// Tests IHistorical.

// Should initialize an empty array
TEST(IHistoricalTest, DefaultInit) {
    IHistorical h;

    ASSERT_EQ(h.getRollsForSide(1), 0);
    ASSERT_EQ(h.getRollsForSide(2), 0);
    ASSERT_EQ(h.getRollsForSide(3), 0);
    ASSERT_EQ(h.getRollsForSide(4), 0);
    ASSERT_EQ(h.getRollsForSide(5), 0);
    ASSERT_EQ(h.getRollsForSide(6), 0);
}

// Should log a roll
TEST(IHistoricalTest, LogRoll) {
    IHistorical h;

    int rollVal = 3;
    h.logRoll(rollVal);

    ASSERT_EQ(h.getLastRoll(), 3);
    ASSERT_EQ(h.getRollsForSide(3), 1);
}
