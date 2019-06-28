#pragma once

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

#include <iostream>

class NinjaTrap : public virtual ClapTrap {
public:
    NinjaTrap();
    NinjaTrap(std::string const &name);
    NinjaTrap(NinjaTrap const &copy);
    virtual ~NinjaTrap();

    NinjaTrap &operator=(const NinjaTrap &copy);

    void    ninjaShoebox(const NinjaTrap &nt);
    void    ninjaShoebox(const FragTrap &ft);
    void    ninjaShoebox(const ScavTrap &st);
};

std::ostream    &operator<<(std::ostream &o, const NinjaTrap &c);
