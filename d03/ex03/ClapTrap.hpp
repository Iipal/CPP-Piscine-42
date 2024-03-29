#pragma once

#include <iostream>
#include <ctime>
#include <cstdlib>

# define MAX_FN_ATTACKS 5

class ClapTrap {
public:
    ClapTrap();
    ClapTrap(std::string const &name);
    ClapTrap(ClapTrap const &copy);
    ~ClapTrap();

    ClapTrap &operator=(const ClapTrap &copy);

    void    linuxCoreAttack(std::string const &target) const;
    void    rangedAttack(std::string const &target) const;
    void    meleeAttack(std::string const &target) const;
    void    depressionAttack(std::string const &target) const;
    void    fartAttack(std::string const &target) const;

    void    takeDamage(unsigned int amount);
    void    beRapired(unsigned int amount);

    unsigned int    getHitPoints(void) const;
    unsigned int    getEnergyPoints(void) const;
    unsigned int    getLevel(void) const;
    std::string     getName(void) const;
    std::string     getType(void) const;

    typedef void (ClapTrap::*fnptrAttack)(std::string const&) const;
    static const fnptrAttack   fnAttacks[MAX_FN_ATTACKS];
protected:
    unsigned int _hitPoints, _energyPoints, _level,
                _maxHitPoints, _maxEnergyPoints,
                _linuxCoreAttackDamage, _rangedAttackDamage,
                _meleeAttackDamage, _depressionAttackDamage,
                _fartAttackDamage, _armorDamageReduction;
    std::string _name, _type;


    void    _callRandomAttack(std::string const &);

    unsigned int    _attackDamageInRange(unsigned int) const;
};

std::ostream    &operator<<(std::ostream &o, const ClapTrap &c);
