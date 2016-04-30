#include "../Interfaces/INameable.hpp"
#include "../Interfaces/IPrintable.hpp"
#include "../Interfaces/IRollable.hpp"
#include "../Interfaces/IWeightable.hpp"

class Die : public INameable, public IPrintable, public IRollable, public IWeightable {
public:
    static const int NUM_SIDES = 6;

    Die();
    Die(std::string n, int side=1, int amount=1);

    int Roll();

    void Print();

private:
    int lastRoll;
};
