#pragma once

#include <iostream>

class Enemy {
public:
    Enemy();
    Enemy(int hp, std::string const &type);
    Enemy(Enemy const &copy);
    virtual ~Enemy();

    Enemy &operator=(const Enemy &copy);

    std::string const &getType(void) const;
    int getHP(void) const;

    virtual void takeDamage(int);
private:
    int _hp;
    std::string _type;
};
