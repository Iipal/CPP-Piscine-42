#pragma once

#include <iostream>

class Weapon
{
public:
    Weapon();
    Weapon(std::string _type);
    ~Weapon();

    std::string const   &getType(void);
    void    setType(const std::string &_type);

private:
    std::string type;
};
