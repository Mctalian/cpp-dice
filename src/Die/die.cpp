#include "die.hpp"

Die::Die() :
    INameable(""),
    IWeightable(1,1)
{
}

Die::Die(std::string name, int side, int amount) :
    INameable(name),
    IWeightable(amount, side)
{
}

int Die::Roll() {
    int rollVal = roll(NUM_SIDES + getLoadAmount() - 1);
    if (rollVal > 6) {
        rollVal = getLoadedSide();
    }
    return rollVal;
}
