#include "die.hpp"

Die::Die() :
    DieInterfaces("", 1,1)
{
}

Die::Die(std::string name, int amount, int side) :
    DieInterfaces(name, amount, side)
{
}
