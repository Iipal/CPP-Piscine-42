#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(std::string const &name) {
    this->_name = name; this->_type = "NINJA-TP";
    this->_hitPoints = 60U; this->_energyPoints = 120U; this->_level = 1U;
    this->_maxHitPoints = 60U; this->_maxEnergyPoints = 120U;
    this->_linuxCoreAttackDamage = 25U; this->_rangedAttackDamage = 5U;
    this->_depressionAttackDamage = 1U; this->_fartAttackDamage = 1337U;
    this->_meleeAttackDamage = 60U; this->_armorDamageReduction = 0U;
}
NinjaTrap::NinjaTrap(const NinjaTrap &copy) { *this = copy; }
NinjaTrap::~NinjaTrap() { }

NinjaTrap &NinjaTrap::operator=(const NinjaTrap &copy) {
    if (this != &copy) { *this = copy; }
    return *this;
}

bool    NinjaTrap::ninjaShoebox(NinjaTrap const &nt) {
    return true;
}

bool    NinjaTrap::ninjaShoebox(FragTrap const &ft) {
    return true;
}

bool    NinjaTrap::ninjaShoebox(ScavTrap const &st) {
    if (this->_energyPoints >= 5U) {
        return true;
    } else  {
        std::cout << this->_type << " <" << this->_name <<
            "> I cann't fight with this Scavenging trap <"
            << st.getName() << "> for free. Give me 5EP." << std::endl;
    }
    return false;
}

std::ostream &operator<<(std::ostream &o, const NinjaTrap &c) {
    o << "Hello, my name is NinjaTrap";
    return o;
}
