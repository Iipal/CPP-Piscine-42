#include "AWeapon.hpp"

#include "AWeapon.hpp"

AWeapon::AWeapon() { }
AWeapon::AWeapon(std::string const &name, int apcost, int damage)
    : _name(name), _apcost(apcost), _damage(damage) { }
AWeapon::AWeapon(const AWeapon &copy) { *this = copy; }
AWeapon::~AWeapon() { }

AWeapon &AWeapon::operator=(const AWeapon &copy) {
    if (this != &copy) { *this = copy; }
    return *this;
}

std::string const   &AWeapon::getName(void) const { return this->_name; }
int AWeapon::getAPCost(void) const { return this->_apcost; }
int AWeapon::getDamage(void) const { return this->_damage; }
