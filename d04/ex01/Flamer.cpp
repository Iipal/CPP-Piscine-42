#include "Flamer.hpp"

Flamer::Flamer() : AWeapon("Flamer", 10, 100) { }
Flamer::Flamer(const Flamer &copy) { *this = copy; }
Flamer::~Flamer() { }

Flamer &Flamer::operator=(const Flamer &copy) {
    if (this != &copy) { *this = copy; }
    return *this;
}

void    Flamer::attack(void) const { std::cout << "* fire burning sound effects *" << std::endl; }
