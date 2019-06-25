#include "Weapon.hpp"

Weapon::Weapon() {}
Weapon::Weapon(std::string _type) : type(_type) {}
Weapon::~Weapon() {}

std::string const   &Weapon::getType(void) { return this->type; }
void    Weapon::setType(const std::string &_type) { this->type = _type; }
