#include "HumanB.hpp"

HumanB::HumanB(const std::string &_name) : name(_name), wpn() {}
HumanB::~HumanB() {}

void    HumanB::setWeapon(Weapon &wpn) { this->wpn = &wpn; }

void    HumanB::attack() const {
    std::cout << this->name << " attacks with his " << this->wpn->getType() << std::endl;
}
