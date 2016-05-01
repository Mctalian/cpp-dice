#ifndef WEIGHTABLE_AND_ROLLABLE_HPP
#define WEIGHTABLE_AND_ROLLABLE_HPP

#include "IHistorical.hpp"
#include "INameable.hpp"
#include "IPrintable.hpp"
#include "IRollable.hpp"
#include "IWeightable.hpp"

class DieInterfaces : public IHistorical, public INameable, public IPrintable, public IRollable, public IWeightable {
public:
    DieInterfaces();
    DieInterfaces(std::string name, int amnt, int side);

    int roll();
    void Print();
};

#endif
