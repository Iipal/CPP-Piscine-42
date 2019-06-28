#include "Character.hpp"

#include <iostream>

Character::Character() { }
Character::Character(std::string const &name)
    : _name(name), _actionPoints(DEF_CHARACTER_AP),
    _maxActionPoints(DEF_CHARACTER_AP), _currentWeapon(NULL) { }
Character::Character(const Character &copy) { *this = copy; }
Character::~Character() { }

Character &Character::operator=(const Character &copy) {
    if (this != &copy) { *this = copy; }
    return *this;
}

void    Character::recoverAP(void) {
    int _toFillAP = this->_maxActionPoints - this->_actionPoints;

    if (DEF_CHARACTER_AP >= this->_actionPoints)
        this->_actionPoints += ((RECOVER_AP_AT_TIME >= _toFillAP)
                            ? _toFillAP : RECOVER_AP_AT_TIME);
}

void    Character::equip(AWeapon *weapon) {
    if (weapon)
        this->_currentWeapon = weapon;
}

void    Character::attack(Enemy *enemy) {
    if (this->_currentWeapon) {
        if (enemy && 0 < enemy->getHP()) {
            if (0 <= this->_actionPoints - this->_currentWeapon->getAPCost()) {
                this->_actionPoints -= this->_currentWeapon->getAPCost();

                std::cout << this->_name << " attacks " << enemy->getType()
                    << " with a " << this->_currentWeapon->getName() << std::endl;
                this->_currentWeapon->attack();

                enemy->takeDamage(this->_currentWeapon->getDamage());
                if (0 >= enemy->getHP()) {
                    delete enemy;
                }
            }
        }
    }
}

std::string const &Character::getName(void) const { return this->_name; }
int Character::getAP(void) const { return this->_actionPoints; }
AWeapon const *Character::getWeapon(void) const { return this->_currentWeapon; }

std::ostream    &operator<<(std::ostream &o, const Character &c) {
    o << c.getName() << " has " << c.getAP() << " AP and ";

    AWeapon const *characterWeapon = c.getWeapon();
    if (characterWeapon)
        o << "wields a " << characterWeapon->getName() << std::endl;
    else
        o << "is unarmed" << std::endl;
    return o;
}
