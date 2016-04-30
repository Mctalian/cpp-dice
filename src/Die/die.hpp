#include <string>
#include "../Interfaces/IPrintable.hpp"
#include "../Interfaces/IRollable.hpp"
#include "../Interfaces/IWeightable.hpp"

class Die :  public IPrintable, public IRollable, public IWeightable {
public:
    static const int NUM_SIDES = 6;

    Die();
    Die(std::string n, int side=1, int amount=1);

    std::string getName();

    int Roll();

    void Print();

private:
    std::string name;
    int lastRoll;
};
