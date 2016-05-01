#include "sequencer.hpp"

Sequencer::Sequencer() :
    numToThrow(1),
    currentThrow(0),
    dieCLL(CircularLinkedList<Die>())
{

}

Sequencer::Sequencer(int numThrows) :
    currentThrow(0),
    dieCLL(CircularLinkedList<Die>())
{
    setNumToThrow(numThrows);
}

int Sequencer::getCurrentThrow() {
    return currentThrow;
}

void Sequencer::setNumToThrow(int numThrows){
    if (numThrows > 0) {
        numToThrow = numThrows;
    }
    else {
        numToThrow = 1;
    }
}

int Sequencer::getNumToThrow() {
    return numToThrow;
}

void Sequencer::addDie(std::string name, int amount, int side) {
    dieCLL.append(Die(name, amount, side));
}

int Sequencer::getNumDie() {
    return dieCLL.getLength();
}

void Sequencer::execute() {
    for (currentThrow = 1; currentThrow < numToThrow; currentThrow++) {
        Print();
        Node<Die>* currentNode = dieCLL.getHead();
        do {
            Die currentDie = currentNode->data;
            if (currentNode != dieCLL.getHead()) {
                printf(", ");
            }
            currentDie.roll();
            Print(currentDie);
            currentNode = currentNode->next;
        } while (currentNode != dieCLL.getHead());
    }
}

void Sequencer::Print() {
    printf("Throw %d: ", currentThrow);
}

void Sequencer::Print(Die d) {
    printf("%s rolled a %d", d.getName().c_str(), d.getLastRoll());
}
