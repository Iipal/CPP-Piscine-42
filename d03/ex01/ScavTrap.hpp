#pragma once

#include <iostream>

class   ScavTrap {
public:
    ScavTrap(const std::string &name);
    ScavTrap(const ScavTrap &st);
    ~ScavTrap();

    ScavTrap    &operator=(const ScavTrap &ft);

    bool    challengeNewcomer(std::string const &target);

    void    rangedAttack(std::string const &target) const;
    void    meleeAttack(std::string const &target) const;

    void    takeDamage(unsigned int amount);
    void    beRapired(unsigned int amount);

    unsigned int    getHitPoints(void) const;
    unsigned int    getEnergyPoints(void) const;
    unsigned int    getLevel(void) const;
    std::string     getName(void) const;
private:
    unsigned int _hitPoints, _energyPoints, _level,
                _maxHitPoints, _maxEnergyPoints,
                _rangedAttackDamage, _meleeAttackDamage,
                _armorDamageReduction;
    std::string _name;

    unsigned int    _attackDamageInRange(unsigned int) const;

    typedef void (ScavTrap::*fnptrAttack)(std::string const&) const;
};

std::ostream &operator<<(std::ostream &o, ScavTrap const &f);
