#pragma once

#include <iostream>

#include "AWeapon.hpp"

class Flamer : public AWeapon {
public:
    Flamer();
    Flamer(Flamer const &copy);
    ~Flamer();

    Flamer &operator=(const Flamer &copy);

    virtual void attack(void) const;
};
