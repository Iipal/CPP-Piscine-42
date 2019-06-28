#pragma once

#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon {
public:
    PlasmaRifle();
    PlasmaRifle(PlasmaRifle const &copy);
    ~PlasmaRifle();

    PlasmaRifle &operator=(const PlasmaRifle &copy);

    virtual void attack(void) const;
};
