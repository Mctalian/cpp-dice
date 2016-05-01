#include "../Die/die_consts.hpp"
#include "DieInterfaces.hpp"

DieInterfaces::DieInterfaces() :
    INameable(),
    IWeightable()
{

}

DieInterfaces::DieInterfaces(std::string name, int amnt, int side) :
    INameable(name),
    IWeightable(amnt, side)
{

}

int DieInterfaces::roll() {
    int rollVal = IRollable::roll(NUM_SIDES + getLoadAmount() - 1);
    if (rollVal > 6) {
        rollVal = getLoadedSide();
    }
    logRoll(rollVal);
    return rollVal;
}

void DieInterfaces::Print() {
    printf("%s Statistics for %d rolls:\n", getName().c_str(), getNumRolls());
    for (int side = 1; side <= NUM_SIDES; side++) {
        int percentage = static_cast<double>(getRollsForSide(side)) / static_cast<double>(getNumRolls()) * 100;
        printf("Side %d: %d%%\n", side, percentage);
    }
    printf("\n");
}
