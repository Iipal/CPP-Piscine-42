#include "ClapTrap.hpp"

const ClapTrap::fnptrAttack ClapTrap::fnAttacks[]  = {
    &ClapTrap::linuxCoreAttack, &ClapTrap::rangedAttack,
    &ClapTrap::meleeAttack, &ClapTrap::depressionAttack,
    &ClapTrap::fartAttack
};

ClapTrap::ClapTrap()
 : _hitPoints(100U), _energyPoints(100U), _level(1U),
    _maxHitPoints(100U), _maxEnergyPoints(100U), _linuxCoreAttackDamage(55U),
    _rangedAttackDamage(20U), _meleeAttackDamage(30U), _depressionAttackDamage(1U),
    _fartAttackDamage(1337U), _armorDamageReduction(5U), _name("ClapTrap"), _type("CLAP_TP") {
    srand(time(NULL));
}
ClapTrap::ClapTrap(const std::string &name)
 : _hitPoints(100U), _energyPoints(100U), _level(1U),
    _maxHitPoints(100U), _maxEnergyPoints(100U), _linuxCoreAttackDamage(55U),
    _rangedAttackDamage(20U), _meleeAttackDamage(30U), _depressionAttackDamage(1U),
    _fartAttackDamage(1337U), _armorDamageReduction(5U), _name(name), _type("CLAP_TP") {
    srand(time(NULL));
}

ClapTrap::ClapTrap(const ClapTrap &ft) { *this = ft; }
ClapTrap::~ClapTrap() { }

ClapTrap    &ClapTrap::operator=(const ClapTrap &ft) {
    if (this != &ft) { *this = ft; }
    return *this;
}

void    ClapTrap::linuxCoreAttack(std::string const &target) const {
    std::cout << this->_type << " <" << this->_name << "> attacks <"
        << target << "> by refactoring his core code <" << this->_linuxCoreAttackDamage
        << "> points of damage ! Torvald is our god !" << std::endl;
}

void    ClapTrap::rangedAttack(std::string const &target) const {
    std::cout << this->_type << " <" << this->_name << "> attacks <"
        << target << "> at range, causing <" << this->_rangedAttackDamage
        << "> points of damage ! Oh god I can't stop !" << std::endl;
}

void    ClapTrap::meleeAttack(std::string const &target) const {
    std::cout << this->_type << " <" << this->_name << "> attacks <"
        << target << "> in melee <" << this->_meleeAttackDamage
        << "> point of damage ! It's the only way to stop the voices !" << std::endl;
}

void    ClapTrap::depressionAttack(std::string const &target) const {
    std::cout << this->_type << " <" << this->_name << "> attacks <"
        << target << "> from bed by throwing a Coca-Cola bottle <" << this->_depressionAttackDamage
        << "> point of damage ! Argmh... leavemealone !" << std::endl;
}

void    ClapTrap::fartAttack(std::string const &target) const {
    std::cout << this->_type << " <" << this->_name << "> attacks <"
        << target << "> farting in your face <" << this->_fartAttackDamage
        << "> point of damage ! Trauben, Angriff !!! " << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount) {
    amount = this->_attackDamageInRange(amount);
    if (static_cast<long>(this->_hitPoints) - static_cast<long>(amount) >= 0L) {
        this->_hitPoints -= amount;
    } else {
        this->_hitPoints = 0;
    }

    std::cout << this->_type << " <" << this->_name << "> taking <" << amount
            << "> damage points, now he has <" << this->_hitPoints << "> HP. ";
    if (0 < this->_hitPoints) {
        std::cout << "Why do I even feel pain ?!" << std::endl;
    } else {
        std::cout << "I'm already dead, what are you more want from me ... ???" << std::endl;
    }
}

void    ClapTrap::beRapired(unsigned int amount) {
    unsigned int _HPAmount = amount, _EPAmount = amount,
        _toFillFullHP = this->_maxHitPoints - this->_hitPoints,
        _toFillFullEP = this->_maxEnergyPoints - this->_energyPoints;

    if (amount > _toFillFullHP)
        _HPAmount = _toFillFullHP;
    this->_hitPoints += _HPAmount;

    if (amount > _toFillFullEP)
        _EPAmount = _toFillFullEP;
    this->_energyPoints += _EPAmount;

    std::cout << this->_type << " <" << this->_name << "> now HP is <"
        << this->_hitPoints << "> and EP is <" << this->_energyPoints
        << ">. I feel the live in my ass !" << std::endl;
}

unsigned int    ClapTrap::getHitPoints(void) const { return this->_hitPoints; }
unsigned int    ClapTrap::getEnergyPoints(void) const { return this->_energyPoints; }
unsigned int    ClapTrap::getLevel(void) const { return this->_level; }
std::string     ClapTrap::getName(void) const { return this->_name; }
std::string     ClapTrap::getType(void) const { return this->_type; }

void    ClapTrap::_callRandomAttack(std::string const &target) {
    (this->*fnAttacks[rand() % MAX_FN_ATTACKS])(target);
}

unsigned int    ClapTrap::_attackDamageInRange(unsigned int amount) const {
    const long    out_amout = static_cast<long>(amount) - static_cast<long>(this->_armorDamageReduction);

    if (static_cast<long>(this->_maxHitPoints) < out_amout)
        return this->_maxHitPoints;
    else if (0 >= out_amout)
        return 0U;
    return static_cast<unsigned int>(out_amout);
}

std::ostream    &operator<<(std::ostream &o, ClapTrap const &f) {
    o << f.getType() << " <" << f.getName() << "> short info:\t"
        << " HP: " << f.getHitPoints() << "; EP: " << f.getEnergyPoints()
        << "; level: " << f.getLevel() << std::endl;
    return o;
}
