#include "DeadEye.hpp"

DeadEye::DeadEye() : Enemy(355, "Dead Eye") { std::cout << "Death can see you..." << std::endl; }
DeadEye::DeadEye(const DeadEye &copy) { *this = copy; }
DeadEye::~DeadEye() { std::cout << "You killed the Dead Eye, but death still watching to you..." << std::endl; }

DeadEye &DeadEye::operator=(const DeadEye &copy) {
    if (this != &copy) { *this = copy; }
    return *this;
}

void    DeadEye::takeDamage(int damage) { Enemy::takeDamage(damage - 15); }
