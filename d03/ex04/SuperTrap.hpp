#pragma once

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap {
public:
    SuperTrap();
    SuperTrap(std::string const &name);
    SuperTrap(SuperTrap const &copy);
    ~SuperTrap();

    SuperTrap &operator=(const SuperTrap &copy);

    void    rangedAttack(const std::string &target) const;
    void    meleeAttack(const std::string &target) const;
private:

};

std::ostream    &operator<<(std::ostream &o, const SuperTrap &c);
