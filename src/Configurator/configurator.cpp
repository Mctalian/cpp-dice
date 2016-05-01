#include "configurator.hpp"
#include <cstdlib>
#include <sstream>
#include <string>

Configurator::Configurator() :
    infile("data.conf"),
    s(Sequencer())
{

}

Configurator::Configurator(const char* fname) :
    infile(fname),
    s(Sequencer())
{

}

void Configurator::parse() {
    std::string line;
    std::string dieName = "";
    int amnt = 0;
    int side = 0;
    while (std::getline(infile, line))
    {
        int delimiter = line.find('=');
        std::string key = line.substr(0, delimiter);
        std::string val = line.substr(delimiter + 1, line.length() - delimiter + 1);

        // process key/value pair
        if (key == "NumRolls") {
            s.setNumToThrow(atoi(val.c_str()));
        }
        else if (key == "Die") {
            dieName = val;
        }
        else if (key == "LoadAmount") {
            amnt = atoi(val.c_str());
        }
        else if (key == "LoadedSide") {
            side = atoi(val.c_str());
        }
        else {
            // Do nothing, unrecognized config option
        }

        if (dieName != "" && side > 0 && amnt > 0) {
            s.addDie(dieName, amnt, side);
            dieName = "";
            amnt = 0;
            side = 0;
        }
    }
}

Sequencer& Configurator::getSequencer() {
    return s;
}
