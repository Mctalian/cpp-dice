#include "IHistorical.hpp"

IHistorical::IHistorical() :
    trackRolls(),
    lastRoll(0)
{

}

void IHistorical::logRoll(int side) {
    if (side > 0 && side <= 6) {
        trackRolls[side-1]++;
        lastRoll = side;
    }
}

int IHistorical::getRollsForSide(int side) {
    if (side > 0 && side <= 6) {
        return trackRolls[side - 1];
    }
    else {
        return -1;
    }
}

int IHistorical::getLastRoll() {
    return lastRoll;
}

void IHistorical::Print() {

}
