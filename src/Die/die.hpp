#include <string>
#include "../Interfaces/IRollable.hpp"

class Die : IRollable {
public:
    static const int NUM_SIDES = 6;

    Die();
    Die(std::string n, int side=1, int amount=1);

    std::string getName();
    int getLoadedSide();
    int getLoadAmount();

    int Roll();

private:
    std::string name;
    int loadedSide;
    int loadAmount;
};
