#ifndef DIE_HPP
#define DIE_HPP

#include "../Interfaces/INameable.hpp"
#include "../Interfaces/WeightableAndRollable.hpp"

class Die : public INameable, public WeightableAndRollable {
public:

    Die();
    Die(std::string n, int amount=1, int side=1);

};

#endif
