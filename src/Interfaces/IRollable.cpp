#include <cstdlib>
#include "IRollable.hpp"

int IRollable::roll(int maxVal) {
    // RNG between 1 and `maxVal`
    return std::rand() % maxVal + 1;
}
