#include "Zombie.hpp"

Zombie::Zombie() : _name("Z-zombie"), _type("Z-zombie") { srand(time(NULL)); }
Zombie::~Zombie() {}

std::string Zombie::randomAnnounces[] = {"Braiiiiiiinnnssss...", "Die...", "Pie...",
    "Needs to done this project before deadline...", "OCalm-Piscine is the beast..."};

std::string Zombie::__announceGenerator() { return Zombie::randomAnnounces[rand() % 5]; }

std::string Zombie::getName(void) const { return this->_name; }
std::string Zombie::getType(void) const { return this->_type; }

void    Zombie::setName(std::string name) { this->_name = name; }
void    Zombie::setType(std::string type) { this->_type = type; }

void    Zombie::announce(void) {
    std::cout << "<" << this->getName() << " (" << this->getType() << ")> " << Zombie::__announceGenerator() << std::endl;
}
