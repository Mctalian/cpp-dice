#include "IWeightable.hpp"
#include "gtest/gtest.h"

// Tests IWeightable.

// Should initialize unweighted
TEST(IWeightableTest, Unweighted) {
    IWeightable w;
    int amnt;
    int side;

    amnt = w.getLoadAmount();
    ASSERT_EQ(amnt, 1);

    side = w.getLoadedSide();
    ASSERT_EQ(side, 1);
}

// Should initialize Weighted
TEST(IWeightableTest, Weighted) {
    IWeightable w(2, 6);
    int amnt;
    int side;

    amnt = w.getLoadAmount();
    ASSERT_EQ(amnt, 2);

    side = w.getLoadedSide();
    ASSERT_EQ(side, 6);
}

// Should disallow invalid weights
TEST(IWeightableTest, InvalidWeight) {
    IWeightable w;
    int amnt;

    w.setLoadAmount(0);
    amnt = w.getLoadAmount();
    ASSERT_NE(amnt, 0);
    ASSERT_EQ(amnt, 1);
}

// Should disallow invalid sides
TEST(IWeightableTest, InvalidSide) {
    IWeightable w;
    int side;

    w.setLoadedSide(0);
    side = w.getLoadedSide();
    ASSERT_NE(side, 0);
    ASSERT_EQ(side, 1);

    w.setLoadedSide(7);
    side = w.getLoadedSide();
    ASSERT_NE(side, 7);
    ASSERT_EQ(side, 1);
}
