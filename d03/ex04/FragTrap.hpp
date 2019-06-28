#pragma once

#include "ClapTrap.hpp"

class   FragTrap : public virtual ClapTrap {
public:
    FragTrap();
    FragTrap(const std::string &name);
    FragTrap(const FragTrap &ft);
    virtual ~FragTrap();

    FragTrap    &operator=(const FragTrap &ft);

    bool    vaulthunter_dot_exe(std::string const &target);
};

std::ostream &operator<<(std::ostream &o, FragTrap const &f);
