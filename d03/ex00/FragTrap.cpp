#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &name)
 : _hitPoints(100U), _energyPoints(100U), _level(1U),
    _maxHitPoints(100U), _maxEnergyPoints(100U), _linuxCoreAttackDamage(55U),
    _rangedAttackDamage(20U), _meleeAttackDamage(30U), _depressionAttackDamage(1U),
    _fartAttackDamage(1337U), _armorDamageReduction(5U), _name(name) {
    std::srand(std::time(NULL));
    std::cout << this->_name << " getting ready for some Fragtrap face time!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &ft) { *this = ft; }
FragTrap::~FragTrap() { std::cout << this->_name << " is deFRAGmenting..." << std::endl; }

FragTrap    &FragTrap::operator=(const FragTrap &ft) {
    if (this != &ft) {
        *this = ft;
    }
    return *this;
}

void    FragTrap::linuxCoreAttack(std::string const &target) const {
    std::cout << "FR4G-TP <" << this->_name << "> attacks <"
        << target << "> by refactoring his core code <" << this->_linuxCoreAttackDamage
        << "> points of damage ! Torvald if our god !" << std::endl;
}

void    FragTrap::rangedAttack(std::string const &target) const {
    std::cout << "FR4G-TP <" << this->_name << "> attacks <"
        << target << "> at range, causing <" << this->_rangedAttackDamage
        << "> points of damage ! Oh god I can't stop !" << std::endl;
}

void    FragTrap::meleeAttack(std::string const &target) const {
    std::cout << "FR4G-TP <" << this->_name << "> attacks <"
        << target << "> in melee <" << this->_meleeAttackDamage
        << "> point of damage ! It's the only way to stop the voices !" << std::endl;
}

void    FragTrap::depressionAttack(std::string const &target) const {
    std::cout << "FR4G-TP <" << this->_name << "> attacks <"
        << target << "> from bed by throwing a Coca-Cola bottle <" << this->_depressionAttackDamage
        << "> point of damage ! Argmh... leavemealone !" << std::endl;
}

void    FragTrap::fartAttack(std::string const &target) const {
    std::cout << "FR4G-TP <" << this->_name << "> attacks <"
        << target << "> from bed by throwing a Coca-Cola bottle <" << this->_fartAttackDamage
        << "> point of damage ! Trauben, Angriff !!! " << std::endl;
}

bool    FragTrap::vaulthunter_dot_exe(std::string const &target) {
    if (this->_energyPoints >= 25) {
        static const fnptrAttack fnAttacks[] = { &FragTrap::linuxCoreAttack, &FragTrap::rangedAttack,
            &FragTrap::meleeAttack, &FragTrap::depressionAttack, &FragTrap::fartAttack };

        this->_energyPoints -= 25;
        size_t  attacksQueue = 5;
        while (attacksQueue--)
            (this->*fnAttacks[rand() % sizeof(fnAttacks) / sizeof(*fnAttacks)])(target);
        return true;
    } else {
        std::cout << "FR4G-TP <" << this->_name
            << "> Wow-wow-wow stop trying to rape me... but for 25EP..." << std::endl;
    }
    return false;
}

void    FragTrap::takeDamage(unsigned int amount) {
    amount = this->_attackDamageInRange(amount);
    if (static_cast<long>(this->_hitPoints) - static_cast<long>(amount) >= 0L) {
        this->_hitPoints -= amount;
    } else {
        this->_hitPoints = 0;
    }

    std::cout << "FR4G-TP <" << this->_name << "> taking <" << amount
            << "> damage points, now he has <" << this->_hitPoints << "> HP. ";
    if (0 < this->_hitPoints) {
        std::cout << "Why do I even feel pain ?!" << std::endl;
    } else {
        std::cout << "I'm already dead, what are you more want from me ... ???" << std::endl;
    }
}

void    FragTrap::beRapired(unsigned int amount) {
    unsigned int _HPAmount = amount, _EPAmount = amount,
        _toFillFullHP = this->_hitPoints - this->_hitPoints,
        _toFillFullEP = this->_maxEnergyPoints - this->_energyPoints;

    if (amount > _toFillFullHP)
        _HPAmount = _toFillFullHP;
    this->_hitPoints += _HPAmount;

    if (amount > _toFillFullEP)
        _EPAmount = _toFillFullEP;
    this->_energyPoints += _EPAmount;

    std::cout << "FR4G-TP <" << this->_name << "> HP is <"
        << this->_hitPoints << "> and EP is <" << this->_energyPoints
        << ">. I feel the live in my ass !" << std::endl;
}

unsigned int    FragTrap::getHitPoints(void) const { return this->_hitPoints; }
unsigned int    FragTrap::getEnergyPoints(void) const { return this->_energyPoints; }
unsigned int    FragTrap::getLevel(void) const { return this->_level; }
std::string     FragTrap::getName(void) const { return this->_name; }

unsigned int    FragTrap::_attackDamageInRange(unsigned int amount) const {
    const long    out_amout = static_cast<long>(amount) - static_cast<long>(this->_armorDamageReduction);

    if (static_cast<long>(this->_maxHitPoints) < out_amout)
        return this->_maxHitPoints;
    else if (0 >= out_amout)
        return 0U;
    return static_cast<unsigned int>(out_amout);
}

std::ostream    &operator<<(std::ostream &o, FragTrap const &f) {
    o << "FR4G-TP <" << f.getName() << "> short info:\t"
        << " HP: " << f.getHitPoints() << "; EP: " << f.getEnergyPoints()
        << "; level: " << f.getLevel() << std::endl;
    return o;
}
