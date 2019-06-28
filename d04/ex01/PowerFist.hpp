#pragma once

#include "AWeapon.hpp"

class PowerFist : public AWeapon {
public:
    PowerFist();
    PowerFist(PowerFist const &copy);
    ~PowerFist();

    PowerFist &operator=(const PowerFist &copy);

    virtual void attack(void) const;
};
