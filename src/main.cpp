#include <iostream> // cout
#include <cstddef>  // NULL
#include <cstdlib>  // srand
#include <time.h>   // time
#include "Configurator/configurator.hpp"
using namespace std;

int main(int argc, char* argv[]) {
    if (argc == 1) {
        cout << "Please supply a filename!" << endl;
    }
    else if (argc >= 3) {
        cout << "Too many args!" << endl;
    }
    else {
        // Make the rolls pseudo-random by seeding rand
        srand(time(NULL));

        cout << "Time to roll some dice!..." << endl;
        cout << "Looking at configuration in " << argv[1] << endl;
        Configurator c(argv[1]);

        // Parse Configuration File
        c.parse();

        // Get Sequencer so we can start rolling
        Sequencer s = c.getSequencer();

        // Print What we're going to do
        cout << s.getNumToThrow() << " Throws incoming... ";
        cout << "and " << s.getNumDie() << " dice" << endl;

        // Start rolling
        cout << "Let's begin!" << endl;
        s.execute();
    }
    return 0;
}
