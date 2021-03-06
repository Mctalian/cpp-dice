# A sample Makefile for building Google Test and using it in user
# tests.  Please tweak it to suit your environment and project.  You
# may want to move it to your project's root directory.
#
# SYNOPSIS:
#
#   make [all]  - makes everything.
#   make TARGET - makes the given target.
#   make clean  - removes all files generated by make.

# Please tweak the following variable definitions as needed by your
# project, except GTEST_HEADERS, which you can use in your own targets
# but shouldn't modify.

# Points to the root of Google Test, relative to where this file is.
# Remember to tweak this if you move this file.
GTEST_DIR = /usr/local/include/gtest

# Where to find user code.
USER_DIR = .

OUT_DIR = ./output
OBJ_DIR = ./objs

# Flags passed to the preprocessor.
# Set Google Test's header directory as a system directory, such that
# the compiler doesn't generate warnings in Google Test headers.
CPPFLAGS += -std=c++0x -isystem $(GTEST_DIR)/include

# Flags passed to the C++ compiler.
CXXFLAGS += -g -Wall -Wextra -pthread

# All tests produced by this Makefile.  Remember to add new tests you
# created to the list.
TESTS = all_tests \
        configurator_test \
        die_test \
        sequencer_test \
        CircularLinkedList_test \
        IHistorical_test \
        INameable_test \
        IRollable_test \
        IWeightable_test \
        DieInterfaces_test

IFACE_HEADERS = $(USER_DIR)/Interfaces/*.hpp

STRUCT_HEADERS = $(USER_DIR)/Structs/*.hpp

# All Google Test headers.  Usually you shouldn't change this
# definition.
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

# House-keeping build targets.

all : $(TESTS)

clean :
	rm -f $(TESTS) gtest.a gtest_main.a *.o $(OUT_DIR)/* test*.conf

# Builds gtest.a and gtest_main.a.

# Usually you shouldn't tweak such internal variables, indicated by a
# trailing _.
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

# For simplicity and to avoid depending on Google Test's
# implementation details, the dependencies specified below are
# conservative and not optimized.  This is fine as Google Test
# compiles fast and for ordinary users its source rarely changes.
gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

# Builds a sample test.  A test should link with either gtest.a or
# gtest_main.a, depending on whether it defines its own main()
# function.

# To create the executable file main we need the object files
# main.o:
#
main:  main.o die.o IHistorical.o INameable.o IRollable.o IWeightable.o DieInterfaces.o sequencer.o configurator.o
	mkdir -p $(OUT_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $(OUT_DIR)/$@

# To create the object file main.o, we need the source
# files main.cpp:
#
main.o :  main.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/main.cpp

configurator.o : $(USER_DIR)/Configurator/configurator.cpp $(USER_DIR)/Configurator/configurator.hpp $(IFACE_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/Configurator/configurator.cpp

configurator_test.o : $(USER_DIR)/Configurator/configurator_test.cpp $(IFACE_HEADERS) $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/Configurator/configurator_test.cpp

configurator_test : configurator.o sequencer.o die.o DieInterfaces.o IHistorical.o IRollable.o IWeightable.o INameable.o configurator_test.o gtest_main.a
	mkdir -p $(OUT_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $(OUT_DIR)/$@

die.o : $(USER_DIR)/Die/die.cpp $(USER_DIR)/Die/die.hpp $(IFACE_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/Die/die.cpp

die_test.o : $(USER_DIR)/Die/die_test.cpp $(IFACE_HEADERS) $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/Die/die_test.cpp

die_test : die.o DieInterfaces.o IHistorical.o IRollable.o IWeightable.o INameable.o die_test.o gtest_main.a
	mkdir -p $(OUT_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $(OUT_DIR)/$@

sequencer.o : $(USER_DIR)/Sequencer/sequencer.cpp $(USER_DIR)/Sequencer/sequencer.hpp $(IFACE_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/Sequencer/sequencer.cpp

sequencer_test.o : $(USER_DIR)/Sequencer/sequencer_test.cpp $(IFACE_HEADERS) $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/Sequencer/sequencer_test.cpp

sequencer_test : sequencer.o die.o DieInterfaces.o IHistorical.o IRollable.o IWeightable.o INameable.o sequencer_test.o gtest_main.a
	mkdir -p $(OUT_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $(OUT_DIR)/$@

CircularLinkedList_test.o : $(USER_DIR)/Structs/CircularLinkedList_test.cpp $(STRUCT_HEADERS) $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/Structs/CircularLinkedList_test.cpp

CircularLinkedList_test : CircularLinkedList_test.o gtest_main.a
	mkdir -p $(OUT_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $(OUT_DIR)/$@

IHistorical.o : $(USER_DIR)/Interfaces/IHistorical.cpp $(IFACE_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/Interfaces/IHistorical.cpp

IHistorical_test.o : $(USER_DIR)/Interfaces/IHistorical_test.cpp $(IFACE_HEADERS) $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/Interfaces/IHistorical_test.cpp

IHistorical_test : IHistorical.o IHistorical_test.o gtest_main.a
	mkdir -p $(OUT_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $(OUT_DIR)/$@

INameable.o : $(USER_DIR)/Interfaces/INameable.cpp $(IFACE_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/Interfaces/INameable.cpp

INameable_test.o : $(USER_DIR)/Interfaces/INameable_test.cpp $(IFACE_HEADERS) $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/Interfaces/INameable_test.cpp

INameable_test : INameable.o INameable_test.o gtest_main.a
	mkdir -p $(OUT_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $(OUT_DIR)/$@

IRollable.o: $(USER_DIR)/Interfaces/IRollable.cpp $(IFACE_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/Interfaces/IRollable.cpp

IRollable_test.o : $(USER_DIR)/Interfaces/IRollable_test.cpp $(IFACE_HEADERS) $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/Interfaces/IRollable_test.cpp

IRollable_test : IRollable.o IRollable_test.o gtest_main.a
	mkdir -p $(OUT_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $(OUT_DIR)/$@

IWeightable.o: $(USER_DIR)/Interfaces/IWeightable.cpp $(IFACE_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/Interfaces/IWeightable.cpp

IWeightable_test.o : $(USER_DIR)/Interfaces/IWeightable_test.cpp $(IFACE_HEADERS) $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/Interfaces/IWeightable_test.cpp

IWeightable_test : IWeightable.o IWeightable_test.o gtest_main.a
	mkdir -p $(OUT_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $(OUT_DIR)/$@

DieInterfaces.o: $(USER_DIR)/Interfaces/DieInterfaces.cpp $(IFACE_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/Interfaces/DieInterfaces.cpp

DieInterfaces_test.o : $(USER_DIR)/Interfaces/DieInterfaces_test.cpp $(IFACE_HEADERS) $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/Interfaces/DieInterfaces_test.cpp

DieInterfaces_test : DieInterfaces.o IHistorical.o IRollable.o IWeightable.o INameable.o DieInterfaces_test.o gtest_main.a
	mkdir -p $(OUT_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $(OUT_DIR)/$@

all_tests: die.o IHistorical.o INameable.o IRollable.o IWeightable.o DieInterfaces.o sequencer.o configurator.o \
           die_test.o IHistorical_test.o INameable_test.o IRollable_test.o IWeightable_test.o DieInterfaces_test.o sequencer_test.o configurator_test.o \
           gtest_main.a
	mkdir -p $(OUT_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $(OUT_DIR)/$@
