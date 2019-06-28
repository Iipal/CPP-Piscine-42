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

    void    ninjaShoebox(const NinjaTrap &nt);
    void    ninjaShoebox(const FragTrap &ft);
    void    ninjaShoebox(const ScavTrap &st);
};

std::ostream    &operator<<(std::ostream &o, const NinjaTrap &c);
