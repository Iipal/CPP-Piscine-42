#include "SuperMutant.hpp"

SuperMutant::SuperMutant() : Enemy(170, "Super Mutant") { std::cout << "Gaaah. Me want smash heads !" << std::endl; }
SuperMutant::SuperMutant(const SuperMutant &copy) { *this = copy; }
SuperMutant::~SuperMutant() { std::cout << "Aaargh ..." << std::endl; }

SuperMutant &SuperMutant::operator=(const SuperMutant &copy) {
    if (this != &copy) { *this = copy; }
    return *this;
}

void    SuperMutant::takeDamage(int damage) { Enemy::takeDamage(damage - 3); }
