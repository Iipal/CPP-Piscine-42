#include "FragTrap.hpp"

FragTrap::FragTrap() {
    this->_name = "FR4G-TP"; this->_type = "FR4G-TP";
    this->_hitPoints = 100U; this->_energyPoints = 100U; this->_level = 1U;
    this->_maxHitPoints = 100U; this->_maxEnergyPoints = 100U;
    this->_linuxCoreAttackDamage = 55U; this->_rangedAttackDamage = 20U;
    this->_depressionAttackDamage = 1U; this->_fartAttackDamage = 1337U;
    this->_meleeAttackDamage = 30U; this->_armorDamageReduction = 5U; }
FragTrap::FragTrap(const std::string &name) {
    this->_name = name; this->_type = "FR4G-TP";
    this->_hitPoints = 100U; this->_energyPoints = 100U; this->_level = 1U;
    this->_maxHitPoints = 100U; this->_maxEnergyPoints = 100U;
    this->_linuxCoreAttackDamage = 55U; this->_rangedAttackDamage = 20U;
    this->_depressionAttackDamage = 1U; this->_fartAttackDamage = 1337U;
    this->_meleeAttackDamage = 30U; this->_armorDamageReduction = 5U;
    std::cout << this->_name << " getting ready for some " << this->_type << " face time!" << std::endl; }
FragTrap::FragTrap(const FragTrap &ft) { *this = ft; }
FragTrap::~FragTrap() { std::cout << this->_name << " is deFRAGmenting..." << std::endl; }

FragTrap    &FragTrap::operator=(const FragTrap &ft) {
    if (this != &ft) { *this = ft; }
    return *this;
}

bool    FragTrap::vaulthunter_dot_exe(std::string const &target) {
    if (this->_energyPoints >= 25) {
        this->_energyPoints -= 25;
        size_t  attacksQueue = 5;
        while (attacksQueue--)
            ClapTrap::_callRandomAttack(target);
        return true;
    } else {
        std::cout << this->_type << " <" << this->_name
            << "> Wow-wow-wow stop trying to rape me... but for 25EP..." << std::endl;
    }
    return false;
}

std::ostream    &operator<<(std::ostream &o, FragTrap const &f) {
    o << f.getType() << " <" << f.getName() << "> short info:\t"
        << " HP: " << f.getHitPoints() << "; EP: " << f.getEnergyPoints()
        << "; level: " << f.getLevel() << std::endl;
    return o;
}
