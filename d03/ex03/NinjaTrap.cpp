#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(std::string const &name) {
    this->_name = name; this->_type = "NINJA-TP";
    this->_hitPoints = 60U; this->_energyPoints = 120U; this->_level = 1U;
    this->_maxHitPoints = 60U; this->_maxEnergyPoints = 120U;
    this->_linuxCoreAttackDamage = 25U; this->_rangedAttackDamage = 5U;
    this->_depressionAttackDamage = 1U; this->_fartAttackDamage = 1337U;
    this->_meleeAttackDamage = 60U; this->_armorDamageReduction = 0U;
    std::cout << this->_name << " getting ready for some " << this->_type << " face time!" << std::endl;
}
NinjaTrap::NinjaTrap(const NinjaTrap &copy) { *this = copy; }
NinjaTrap::~NinjaTrap() { std::cout << this->_name << " is deFRAGmenting..." << std::endl; }

NinjaTrap &NinjaTrap::operator=(const NinjaTrap &copy) {
    if (this != &copy) { *this = copy; }
    return *this;
}

void    NinjaTrap::ninjaShoebox(const NinjaTrap &nt) {
    std::cout << this->_type << " <" << this->_name <<
        "> It's not will be my first time when i fight with myself, <"
        << nt.getName() << ">." << std::endl;
}

void    NinjaTrap::ninjaShoebox(const FragTrap &ft) {
    std::cout << this->_type << " <" << this->_name <<
        "> It's will be fun, <" << ft.getName() << "> !110!" << std::endl;
}

void    NinjaTrap::ninjaShoebox(const ScavTrap &st) {
    std::cout << this->_type << " <" << this->_name <<
        "> Do you really want's to fight with me, <"
        << st.getName() << "> ?" << std::endl;
}

std::ostream &operator<<(std::ostream &o, const NinjaTrap &c) {
    o << c.getType() << " <" << c.getName() << "> short info:\t"
        << " HP: " << c.getHitPoints() << "; EP: " << c.getEnergyPoints()
        << "; level: " << c.getLevel() << std::endl;
    return o;
}
