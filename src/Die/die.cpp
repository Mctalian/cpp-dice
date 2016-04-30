#include "die.hpp"

Die::Die() :
    INameable(""),
    WeightableAndRollable(1,1)
{
}

Die::Die(std::string name, int amount, int side) :
    INameable(name),
    WeightableAndRollable(amount, side)
{
}
