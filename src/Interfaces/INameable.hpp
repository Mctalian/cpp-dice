#ifndef INAMEABLE_HPP
#define INAMEABLE_HPP

#include <string>

class INameable {
public:
    INameable();
    INameable(std::string n);

    void setName(std::string n);
    std::string getName();
private:
    std::string name;
};

#endif
