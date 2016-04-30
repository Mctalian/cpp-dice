#include "INameable.hpp"

INameable::INameable() :
    name("")
{

}

INameable::INameable(std::string n) :
    name(n)
{

}

void INameable::setName(std::string n) {
    name = n;
}

std::string INameable::getName() {
    return name;
}
