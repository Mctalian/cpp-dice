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
    Die d(name, amount, side);
    dieCLL.append(d);
}

int Sequencer::getNumDie() {
    return dieCLL.getLength();
}

void Sequencer::execute() {
    // Execute Each Throw and Print Status
    for (int t = 1; t <= numToThrow; t++) {
        currentThrow = t;
        Print();
        Node<Die>* currentNode = dieCLL.getHead();
        do {
            if (currentNode != dieCLL.getHead()) {
                printf(", ");
            }
            Die* currentDie = &currentNode->data;
            currentDie->roll();
            currentNode = currentNode->next;
            Print(currentDie);
        } while (currentNode != dieCLL.getHead());
        printf("\n");
    }

    // Print each Die's Side Statistics
    Node<Die>* currentNode = dieCLL.getHead();
    do {
        Die* currentDie = &currentNode->data;
        currentDie->Print();
        currentNode = currentNode->next;
    } while (currentNode != dieCLL.getHead());
}

void Sequencer::Print() {
    printf("Throw %d: ", currentThrow);
}

void Sequencer::Print(Die* d) {
    printf("%s rolled a %d", d->getName().c_str(), d->getLastRoll());
}
