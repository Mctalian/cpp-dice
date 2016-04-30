#include "IWeightable.hpp"

IWeightable::IWeightable() {
    setLoadAmount(1);
    setLoadedSide(1);
}

IWeightable::IWeightable(int amnt, int side) {
    setLoadAmount(amnt);
    setLoadedSide(side);
}

void IWeightable::setLoadAmount(int amnt) {
    if (amnt > 0) {
        loadAmount = amnt;
    }
    else {
        loadAmount = 1;
    }
}

int IWeightable::getLoadAmount() {
    return loadAmount;
}

void IWeightable::setLoadedSide(int side) {
    if (side > 0 && side <= 6) {
        loadedSide = side;
    }
    else {
        loadedSide = 1;
    }
}

int IWeightable::getLoadedSide() {
    return loadedSide;
}
