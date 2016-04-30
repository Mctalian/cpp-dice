#include "die.hpp"

Die::Die() :
    INameable(""),
    IWeightable(1,1),
    lastRoll(0)
{
}

Die::Die(std::string name, int side, int amount) :
    INameable(name),
    IWeightable(amount, side),
    lastRoll(0)
{
}

void Die::Print() {
    printf("%s: %d\n", getName().c_str(), lastRoll);
}

int Die::Roll() {
    int rollVal = roll(NUM_SIDES + getLoadAmount() - 1);
    if (rollVal > 6) {
        rollVal = getLoadedSide();
    }
    lastRoll = rollVal;
    return rollVal;
}
