#include "PowerFist.hpp"

PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50) { }
PowerFist::PowerFist(const PowerFist &copy) { *this = copy; }
PowerFist::~PowerFist() { }

PowerFist &PowerFist::operator=(const PowerFist &copy) {
    if (this != &copy) { *this = copy; }
    return *this;
}

void    PowerFist::attack(void) const { std::cout << "* pschhh... SBAM! *" << std::endl; }
