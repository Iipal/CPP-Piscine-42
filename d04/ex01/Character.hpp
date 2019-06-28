#pragma once

#include <iostream>

#include "AWeapon.hpp"
#include "Enemy.hpp"

# define RECOVER_AP_AT_TIME 10
# define DEF_CHARACTER_AP   40

class Character {
public:
    Character(std::string const &name);
    Character(Character const &copy);
    ~Character();

    Character &operator=(const Character &copy);

    void    recoverAP(void);
    void    equip(AWeapon*);
    void    attack(Enemy*);

    std::string const &getName(void) const;
    int getAP(void) const;
    AWeapon const *getWeapon(void) const;
protected:
    Character();
private:
    std::string _name;
    int _actionPoints, _maxActionPoints;
    AWeapon *_currentWeapon;
};

std::ostream    &operator<<(std::ostream &o, const Character &c);
