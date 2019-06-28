#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name)
 : _hitPoints(100U), _energyPoints(50U), _level(1U),
    _maxHitPoints(50U), _maxEnergyPoints(50U),
    _rangedAttackDamage(15U), _meleeAttackDamage(20U),
     _armorDamageReduction(3U), _name(name) {
    std::srand(std::time(NULL));
    std::cout << this->_name << " getting ready for some ScavTrap face time!" << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap &st) { *this = st; }
ScavTrap::~ScavTrap() { }

ScavTrap    &ScavTrap::operator=(const ScavTrap &st) {
    if (this != &st) {
        *this = st;
    }
    return *this;
}

bool    ScavTrap::challengeNewcomer(std::string const &target) {
    if (this->_energyPoints >= 5) {
        static const fnptrAttack fnAttacks[] = { &ScavTrap::meleeAttack, &ScavTrap::rangedAttack };

        this->_energyPoints -= 5;
        (this->*fnAttacks[rand() % 2])(target);
        return true;
    } else {
        std::cout << "SCAV-TP <" << this->_name
            << "> Wow-wow-wow stop trying to rape me... but for 5EP..." << std::endl;
    }
    return false;
}

void    ScavTrap::rangedAttack(std::string const &target) const {
    std::cout << "SCAV-TP <" << this->_name << "> attacks <"
        << target << "> at range, causing <" << this->_rangedAttackDamage
        << "> points of damage ! Oh god I can't stop !" << std::endl;
}

void    ScavTrap::meleeAttack(std::string const &target) const {
    std::cout << "SCAV-TP <" << this->_name << "> attacks <"
        << target << "> in melee <" << this->_meleeAttackDamage
        << "> point of damage ! It's the only way to stop the voices !" << std::endl;
}

void    ScavTrap::takeDamage(unsigned int amount) {
    amount = this->_attackDamageInRange(amount);
    if (static_cast<long>(this->_hitPoints) - static_cast<long>(amount) >= 0L) {
        this->_hitPoints -= amount;
    } else {
        this->_hitPoints = 0L;
    }

    std::cout << "SCAV-TP <" << this->_name << "> taking <" << amount
            << "> damage points, now he has <" << this->_hitPoints << "> HP. ";
    if (0L < this->_hitPoints) {
        std::cout << "Why do I even feel pain ?!" << std::endl;
    } else {
        std::cout << "I'm already dead, what are you more want from me ... ???" << std::endl;
    }
}

void    ScavTrap::beRapired(unsigned int amount) {
    unsigned int _HPAmount = amount, _EPAmount = amount,
        _toFillFullHP = this->_maxHitPoints - this->_hitPoints,
        _toFillFullEP = this->_maxEnergyPoints - this->_energyPoints;

    if (amount > _toFillFullHP)
        _HPAmount = _toFillFullHP;
    this->_hitPoints += _HPAmount;

    if (amount > _toFillFullEP)
        _EPAmount = _toFillFullEP;
    this->_energyPoints += _EPAmount;

    std::cout << "SCAV-TP <" << this->_name << "> HP is <"
        << this->_hitPoints << "> and EP is <" << this->_energyPoints
        << ">. I feel the live in my ass !" << std::endl;
}

unsigned int    ScavTrap::getHitPoints(void) const { return this->_hitPoints; }
unsigned int    ScavTrap::getEnergyPoints(void) const { return this->_energyPoints; }
unsigned int    ScavTrap::getLevel(void) const { return this->_level; }
std::string     ScavTrap::getName(void) const { return this->_name; }

unsigned int    ScavTrap::_attackDamageInRange(unsigned int amount) const {
    const long    out_amout = static_cast<long>(amount) - static_cast<long>(this->_armorDamageReduction);

    if (static_cast<long>(this->_maxHitPoints) < out_amout)
        return this->_maxHitPoints;
    else if (0 >= out_amout)
        return 0U;
    return static_cast<unsigned int>(out_amout);
}

std::ostream    &operator<<(std::ostream &o, ScavTrap const &f) {
    o << "SCAV-TP <" << f.getName() << "> short info:\t"
        << " HP: " << f.getHitPoints() << "; EP: " << f.getEnergyPoints()
        << "; level: " << f.getLevel() << std::endl;
    return o;
}
