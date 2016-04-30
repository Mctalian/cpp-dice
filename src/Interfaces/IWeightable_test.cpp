#include "IWeightable.hpp"
#include "gtest/gtest.h"

// Tests IWeightable.

// Should initialize unweighted
TEST(IWeightableTest, Unweighted) {
    IWeightable w1;
    int amnt;
    int side;

    amnt = w1.getLoadAmount();
    ASSERT_EQ(amnt, 1);

    side = w1.getLoadedSide();
    ASSERT_EQ(side, 1);
}

// Should disallow invalid weights
TEST(IWeightableTest, InvalidWeight) {
    IWeightable w2;
    int amnt;

    w2.setLoadAmount(0);
    amnt = w2.getLoadAmount();
    ASSERT_NE(amnt, 0);
    ASSERT_EQ(amnt, 1);
}

// Should disallow invalid sides
TEST(IWeightableTest, InvalidSide) {
    IWeightable w3;
    int side;

    w3.setLoadedSide(0);
    side = w3.getLoadedSide();
    ASSERT_NE(side, 0);
    ASSERT_EQ(side, 1);

    w3.setLoadedSide(7);
    side = w3.getLoadedSide();
    ASSERT_NE(side, 7);
    ASSERT_EQ(side, 1);
}
