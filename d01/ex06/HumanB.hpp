#pragma once

#include "Weapon.hpp"

class HumanB
{
public:
    HumanB(const std::string &_name);
    ~HumanB();

    void    attack() const;
    void    setWeapon(Weapon &wpn);
private:
    std::string name;
    Weapon      *wpn;
};
