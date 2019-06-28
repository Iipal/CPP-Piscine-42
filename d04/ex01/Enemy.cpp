#include "Enemy.hpp"

Enemy::Enemy() { }
Enemy::Enemy(int hp, std::string const &type) : _hp(hp), _type(type) { }
Enemy::Enemy(const Enemy &copy) { *this = copy; }
Enemy::~Enemy() { }

Enemy &Enemy::operator=(const Enemy &copy) {
    if (this != &copy) { *this = copy; }
    return *this;
}

std::string const &Enemy::getType(void) const { return this->_type; }
int Enemy::getHP(void) const { return this->_hp; }

void    Enemy::takeDamage(int damage) {
    if (0 <= damage)
        this->_hp -= damage;
}
