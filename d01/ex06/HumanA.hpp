#pragma once

#include "Weapon.hpp"

class HumanA
{
public:
    HumanA(const std::string &_name, Weapon &wpn);
    ~HumanA();

    void    attack() const;
private:
    std::string name;
    Weapon      *wpn;
};
