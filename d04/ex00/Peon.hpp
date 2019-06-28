#pragma once

#include <iostream>

#include "Victim.hpp"

class Peon : public Victim {
public:
    Peon(const std::string &name);
    Peon(Peon const &copy);
    ~Peon();

    Peon &operator=(const Peon &copy);

    virtual void    getPolymorphed(void) const;
protected:
    Peon();
};

std::ostream    &operator<<(std::ostream &o, const Peon &c);
