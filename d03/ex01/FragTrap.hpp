#pragma once

#include <iostream>
#include <ctime>

class   FragTrap {
public:
    FragTrap(const std::string &name);
    FragTrap(const FragTrap &ft);
    ~FragTrap();

    FragTrap    &operator=(const FragTrap &ft);

    bool    vaulthunter_dot_exe(std::string const &target);

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

private:
    unsigned int _hitPoints, _energyPoints, _level,
                _maxHitPoints, _maxEnergyPoints,
                _linuxCoreAttackDamage, _rangedAttackDamage,
                _meleeAttackDamage, _depressionAttackDamage,
                _fartAttackDamage, _armorDamageReduction;
    std::string _name;

    unsigned int    _attackDamageInRange(unsigned int) const;

    typedef void (FragTrap::*fnptrAttack)(std::string const&) const;
};

std::ostream &operator<<(std::ostream &o, FragTrap const &f);
