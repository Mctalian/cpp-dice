#include "sequencer.hpp"
#include "gtest/gtest.h"

// Tests Sequencer().

// Should default to 1 throw
TEST(SequencerTest, DefaultInitialization) {
    Sequencer s;

    ASSERT_EQ(s.getCurrentThrow(), 0);
    ASSERT_EQ(s.getNumToThrow(), 1);
}

// Should set number of throws
TEST(SequencerTest, SetThrows) {
    Sequencer s(5);

    ASSERT_EQ(s.getCurrentThrow(), 0);
    ASSERT_EQ(s.getNumToThrow(), 5);

    s.setNumToThrow(6);
    ASSERT_EQ(s.getNumToThrow(), 6);
}

// Should add a die
TEST(SequencerTest, AddDie) {
    Sequencer s;

    s.addDie("TestDie1", 1, 1);

    ASSERT_EQ(s.getNumDie(), 1);
}

// Should execute all rolls
TEST(SequencerTest, Execute) {
    Sequencer s;

    ASSERT_EQ(s.getCurrentThrow(), 0);

    s.addDie("TestDie2", 1, 1);
    s.execute();

    ASSERT_EQ(s.getCurrentThrow(), 1);
}
