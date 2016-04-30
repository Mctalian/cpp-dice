#ifndef WEIGHTABLE_AND_ROLLABLE_HPP
#define WEIGHTABLE_AND_ROLLABLE_HPP

#include "IRollable.hpp"
#include "IWeightable.hpp"

class WeightableAndRollable : public IRollable, public IWeightable {
public:
    WeightableAndRollable();
    WeightableAndRollable(int amnt, int side);

    int roll();
};

#endif
