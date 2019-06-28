#pragma once

#include <iostream>

#include "Enemy.hpp"

class DeadEye : public Enemy {
public:
    DeadEye();
    DeadEye(DeadEye const &copy);
    ~DeadEye();

    DeadEye &operator=(const DeadEye &copy);

    virtual void takeDamage(int);
};
