#ifndef SEQUENCER_HPP
#define SEQUENCER_HPP

#include "../Die/die.hpp"
#include "../Interfaces/IPrintable.hpp"
#include "../Structs/CircularLinkedList.hpp"

class Sequencer : public IPrintable {
public:
    Sequencer();
    Sequencer(int numThrows);

    void addDie(std::string name, int amount, int side);

    void execute();

    void Print();
private:
    int numToThrow;
    int currentThrow;
    CircularLinkedList<Die> dieCLL;
};

#endif
