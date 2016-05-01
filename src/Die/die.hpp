#ifndef DIE_HPP
#define DIE_HPP

#include "../Interfaces/DieInterfaces.hpp"

class Die : public DieInterfaces {
public:

    Die();
    Die(std::string n, int amount=1, int side=1);

};

#endif
