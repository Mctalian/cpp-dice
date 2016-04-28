#include <string>

class Die {
public:
    Die();
    Die(std::string n, int side=1, int amount=1);

    std::string getName();
    int getLoadedSide();
    int getLoadAmount();

    int roll();

private:
    static const int NUM_SIDES = 6;
    std::string name;
    int loadedSide;
    int loadAmount;
};
