#include <cstdlib>
#include "die.hpp"

Die::Die() :
    name(""),
    lastRoll(0)
{
    setLoadedSide(1);
    setLoadAmount(1);
}

Die::Die(std::string name, int side, int amount) :
    name(name),
    lastRoll(0)
{
    setLoadedSide(side);
    setLoadAmount(amount);
}

std::string Die::getName() {
    return name;
}

void Die::Print() {
    printf("%s: %d\n", name.c_str(), lastRoll);
}

int Die::Roll() {
    int rollVal = roll(NUM_SIDES + getLoadAmount() - 1);
    if (rollVal > 6) {
        rollVal = getLoadedSide();
    }
    lastRoll = rollVal;
    return rollVal;
}
