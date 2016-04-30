#include "../Die/die_consts.hpp"
#include "IPrintable.hpp"

class IHistorical : public IPrintable {
public:
    IHistorical();

    void logRoll(int side);
    int getLastRoll();
    int getRollsForSide(int side);

    void Print();

private:
    int trackRolls[NUM_SIDES];
    int lastRoll;
};
