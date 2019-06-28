#pragma once

#include "ClapTrap.hpp"

class   ScavTrap : public ClapTrap {
public:
    ScavTrap();
    ScavTrap(const std::string &name);
    ScavTrap(const ScavTrap &st);
    ~ScavTrap();

    ScavTrap    &operator=(const ScavTrap &ft);

    bool    challengeNewcomer(std::string const &target);
};

std::ostream    &operator<<(std::ostream &o, const ScavTrap &c);
