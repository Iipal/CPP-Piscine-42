#pragma once

#include "ClapTrap.hpp"

class   FragTrap : public ClapTrap {
public:
    FragTrap(const std::string &name);
    FragTrap(const FragTrap &ft);
    ~FragTrap();

    FragTrap    &operator=(const FragTrap &ft);

    bool    vaulthunter_dot_exe(std::string const &target);
};

std::ostream &operator<<(std::ostream &o, FragTrap const &f);
