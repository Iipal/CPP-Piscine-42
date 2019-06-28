#pragma once

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

#include <iostream>

class NinjaTrap : public ClapTrap {
public:
    NinjaTrap(std::string const &name);
    NinjaTrap(NinjaTrap const &copy);
    ~NinjaTrap();

    NinjaTrap &operator=(const NinjaTrap &copy);

    bool    ninjaShoebox(const NinjaTrap &nt);
    bool    ninjaShoebox(const FragTrap &ft);
    bool    ninjaShoebox(const ScavTrap &st);
};

std::ostream    &operator<<(std::ostream &o, const NinjaTrap &c);
