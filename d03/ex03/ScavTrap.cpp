#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name) {
    this->_name = name; this->_type = "SCAV-TP";
    this->_hitPoints = 100U; this->_energyPoints = 50U; this->_level = 1U;
    this->_maxHitPoints = 100U; this->_maxEnergyPoints = 50U;
    this->_linuxCoreAttackDamage = 42U; this->_rangedAttackDamage = 15U;
    this->_depressionAttackDamage = 1U; this->_fartAttackDamage = 1337U;
    this->_meleeAttackDamage = 20U; this->_armorDamageReduction = 3U;
    std::cout << this->_name << " getting ready for some " << this->_type << " face time!" << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap &st) { *this = st; }
ScavTrap::~ScavTrap() { std::cout << this->_name << " is deFRAGmenting..." << std::endl; }

ScavTrap    &ScavTrap::operator=(const ScavTrap &st) {
    if (this != &st) { *this = st; }
    return *this;
}

bool    ScavTrap::challengeNewcomer(std::string const &target) {
    if (this->_energyPoints >= 5) {
        this->_energyPoints -= 5;
        this->_callRandomAttack(target);
        return true;
    } else {
        std::cout << "SCAV-TP <" << this->_name
            << "> Wow-wow-wow stop trying to rape me... but for 5EP..." << std::endl;
    }
    return false;
}

std::ostream    &operator<<(std::ostream &o, ScavTrap const &f) {
    o << f.getType() << " <" << f.getName() << "> short info:\t"
        << " HP: " << f.getHitPoints() << "; EP: " << f.getEnergyPoints()
        << "; level: " << f.getLevel() << std::endl;
    return o;
}
