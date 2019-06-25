#include "HumanA.hpp"

HumanA::HumanA(const std::string &_name, Weapon &_wpn) : name(_name), wpn(&_wpn) {}
HumanA::~HumanA() {}

void    HumanA::attack() const {
    std::cout << this->name << " attacks with his " << this->wpn->getType() << std::endl;
}
