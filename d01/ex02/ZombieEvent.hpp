#pragma once

#include "Zombie.hpp"

class   ZombieEvent{
public:
    ZombieEvent();
    ~ZombieEvent();

    void        setZombieType(std::string type);
    void        setZombieRandomType(void);
    Zombie      *newZombie(std::string name);
    Zombie      *randomChump(void);

private:
    std::string _type;

    static std::string randomNames[];
    static std::string randomTypes[];
    static std::string __nameGenerator();
    static std::string __typeGenerator();
};
