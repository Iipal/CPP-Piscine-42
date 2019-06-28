#pragma once

#include "Enemy.hpp"

class SuperMutant : public Enemy {
public:
    SuperMutant();
    SuperMutant(SuperMutant const &copy);
    ~SuperMutant();

    SuperMutant &operator=(const SuperMutant &copy);

    virtual void takeDamage(int);
};
