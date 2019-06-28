#pragma once

#include <iostream>

#include "Victim.hpp"

class Peon : public virtual Victim {
public:
    Peon(const std::string &name);
    Peon(Peon const &copy);
    virtual ~Peon();

    Peon &operator=(const Peon &copy);

    virtual void    getPolymorphed(void) const;
private:
};

std::ostream    &operator<<(std::ostream &o, const Peon &c);
