#ifndef DIE_HPP
#define DIE_HPP

#include "die_consts.hpp"
#include "../Interfaces/INameable.hpp"
#include "../Interfaces/IRollable.hpp"
#include "../Interfaces/IWeightable.hpp"

class Die : public INameable, public IRollable, public IWeightable {
public:

    Die();
    Die(std::string n, int side=1, int amount=1);

    int Roll();

};

#endif
