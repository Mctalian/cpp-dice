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

int Die::Roll() {
    int rollVal = roll(NUM_SIDES + loadAmount - 1);
    if (rollVal > 6) {
        rollVal = loadedSide;
    }
    return rollVal;
}
