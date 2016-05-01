#ifndef IHISTORICAL_HPP
#define IHISTORICAL_HPP

#include "../Die/die_consts.hpp"

class IHistorical {
public:
    IHistorical();

    void logRoll(int side);
    int getNumRolls();
    int getLastRoll();
    int getRollsForSide(int side);

private:
    int trackRolls[NUM_SIDES];
    int numRolls;
    int lastRoll;
};

#endif
