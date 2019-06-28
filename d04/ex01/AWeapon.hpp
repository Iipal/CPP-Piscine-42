#pragma once

#include <iostream>

class AWeapon {
public:
    AWeapon();
    AWeapon(std::string const &name, int apcost, int damage);
    AWeapon(AWeapon const &copy);
    virtual ~AWeapon();

    AWeapon &operator=(const AWeapon &copy);

    std::string const &getName(void) const;
    int getAPCost(void) const;
    int getDamage(void) const;

    virtual void attack(void) const = 0;
private:
    std::string _name;
    int _apcost, _damage;
};
