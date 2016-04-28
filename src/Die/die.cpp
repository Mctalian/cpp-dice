#include <cstdlib>
#include "die.hpp"

Die::Die() {
    name = "";
    loadedSide = 1;
    loadAmount = 1;
}

Die::Die(std::string name, int side, int amount) {
    name = name;
    loadedSide = side;
    loadAmount = amount;
}

std::string Die::getName() {
    return name;
}

int Die::getLoadedSide() {
    return loadedSide;
}

int Die::getLoadAmount() {
    return loadAmount;
}

int Die::roll() {
    int rollVal = std::rand() % NUM_SIDES + loadAmount; // 1 thru 6 plus weighted
    if (rollVal > 6) {
        rollVal = loadedSide;
    }
    return rollVal;
}
