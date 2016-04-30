#include "IWeightable.hpp"
#include "gtest/gtest.h"

// Tests IWeightable.

// Checks default initialization
TEST(IWeightableTest, Unweighted) {
    IWeightable w1;
    int amnt = w1.getLoadAmount();
    ASSERT_EQ(amnt, 1);

    int side = w1.getLoadedSide();
    ASSERT_EQ(side, 1);
}
