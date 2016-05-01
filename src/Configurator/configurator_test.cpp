#include <iostream>
#include <fstream>
#include "configurator.hpp"
#include "gtest/gtest.h"

// Tests Configurator().

// Should set number of rolls
TEST(ConfiguratorTest, SetNumRolls) {
    // Create Test Configuration File
    std::ofstream testFile;
    testFile.open("testNumRolls.conf");
    testFile << "NumRolls=100\n";
    testFile.close();

    Configurator c("testNumRolls.conf");

    c.parse();
    Sequencer s = c.getSequencer();

    ASSERT_EQ(s.getNumToThrow(), 100);
}

// Should set number of dice
TEST(ConfiguratorTest, SetNumDice) {
    // Create Test Configuration File
    std::ofstream testFile;
    testFile.open("test2Dice.conf");
    testFile << "Die=Die1\n";
    testFile << "LoadedSide=3\n";
    testFile << "LoadAmount=2\n";
    testFile << "Die=Die2\n";
    testFile << "LoadedSide=6\n";
    testFile << "LoadAmount=10\n";
    testFile.close();

    Configurator c("test2Dice.conf");

    c.parse();
    Sequencer s = c.getSequencer();

    ASSERT_EQ(s.getNumDie(), 2);
}
