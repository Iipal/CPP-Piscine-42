#pragma once

#include "Enemy.hpp"

class RadScorpion : public Enemy {
public:
    RadScorpion();
    RadScorpion(RadScorpion const &copy);
    ~RadScorpion();

    RadScorpion &operator=(const RadScorpion &copy);
};
