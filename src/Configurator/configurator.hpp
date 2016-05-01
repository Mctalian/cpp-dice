#ifndef CONFIGURATOR_HPP
#define CONFIGURATOR_HPP

#include <fstream>
#include "../Sequencer/sequencer.hpp"


class Configurator {
public:
    Configurator();
    Configurator(const char* fname);

    void parse();
    Sequencer& getSequencer();
private:
    std::ifstream infile;
    Sequencer s;
};

#endif
