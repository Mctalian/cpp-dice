#ifndef SEQUENCER_HPP
#define SEQUENCER_HPP

#include "../Die/die.hpp"
#include "../Interfaces/IPrintable.hpp"
#include "../Structs/CircularLinkedList.hpp"

class Sequencer : public IPrintable {
public:
    Sequencer();
    Sequencer(int numThrows);

    int getCurrentThrow();
    void setNumToThrow(int numThrows);
    int getNumToThrow();
    void addDie(std::string name, int amount, int side);
    int getNumDie();
    void execute();

    void Print();
    void Print(Die* d);
private:
    int numToThrow;
    int currentThrow;
    CircularLinkedList<Die> dieCLL;
};

#endif
