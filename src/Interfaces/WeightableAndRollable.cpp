#include "../Die/die_consts.hpp"
#include "WeightableAndRollable.hpp"

WeightableAndRollable::WeightableAndRollable() :
    IWeightable()
{

}

WeightableAndRollable::WeightableAndRollable(int amnt, int side) :
    IWeightable(amnt, side)
{

}

int WeightableAndRollable::roll() {
    int rollVal = IRollable::roll(NUM_SIDES + getLoadAmount() - 1);
    if (rollVal > 6) {
        rollVal = getLoadedSide();
    }
    return rollVal;
}
