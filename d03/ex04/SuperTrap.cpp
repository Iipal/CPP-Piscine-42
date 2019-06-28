#include "SuperTrap.hpp"

SuperTrap::SuperTrap() {}
SuperTrap::SuperTrap(std::string const &name) {
    this->_name = name; this->_type = "SUPER-TP";
    this->_hitPoints = 100U; this->_energyPoints = 120U; this->_level = 1U;
    this->_maxHitPoints = 100U; this->_energyPoints = 120U;
    this->_linuxCoreAttackDamage = 66U; this->_rangedAttackDamage = 20U;
    this->_depressionAttackDamage = 1U; this->_fartAttackDamage = 1377U;
    this->_meleeAttackDamage = 60U; this->_armorDamageReduction = 5U;
    std::cout << this->_name << " getting ready for some " << this->_type << " face time!" << std::endl;
}
SuperTrap::SuperTrap(const SuperTrap &copy) { *this = copy; }
SuperTrap::~SuperTrap() { std::cout << this->_name << " is deFRAGmenting..." << std::endl; }

SuperTrap &SuperTrap::operator=(const SuperTrap &copy) {
    if (this != &copy) { *this = copy; }
    return *this;
}

void    SuperTrap::meleeAttack(std::string const &target) const { NinjaTrap::meleeAttack(target); }
void    SuperTrap::rangedAttack(std::string const &target) const { FragTrap::rangedAttack(target); }

std::ostream    &operator<<(std::ostream &o, SuperTrap const &c) {
    o << c.getType() << " <" << c.getName() << "> short info:\t"
        << " HP: " << c.getHitPoints() << "; EP: " << c.getEnergyPoints()
        << "; level: " << c.getLevel() << std::endl;
    return o;
}
