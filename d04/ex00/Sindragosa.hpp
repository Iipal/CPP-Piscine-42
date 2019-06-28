#pragma once

#include "Victim.hpp"

class Sindragosa : public Victim {
public:
    Sindragosa(const std::string &name);
    Sindragosa(Sindragosa const &copy);
    ~Sindragosa();

    Sindragosa &operator=(const Sindragosa &copy);

    virtual void    getPolymorphed(void) const;
protected:
    Sindragosa();
};

std::ostream    &operator<<(std::ostream &o, const Sindragosa &c);
