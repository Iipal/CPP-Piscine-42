#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 5, 21) { }
PlasmaRifle::PlasmaRifle(const PlasmaRifle &copy) { *this = copy; }
PlasmaRifle::~PlasmaRifle() { }

PlasmaRifle &PlasmaRifle::operator=(const PlasmaRifle &copy) {
    if (this != &copy) { *this = copy; }
    return *this;
}

void    PlasmaRifle::attack(void) const { std::cout << "* piouuu piouuu piouuu *" << std::endl; }
