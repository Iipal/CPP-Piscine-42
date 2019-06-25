#pragma once

#include "Zombie.hpp"

class   ZombieHorde{
public:
    ZombieHorde(int amount);
    ~ZombieHorde();

    void    announce(void);
private:
    int     _hordeAmount;
    Zombie  *_horde;

    static std::string  randomHordeNames[];
    static std::string  randomHordeTypes[];
    static std::string  _randomizeName();
    static std::string  _randomizeType();
};
