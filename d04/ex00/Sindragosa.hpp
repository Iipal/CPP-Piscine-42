#pragma once

#include "Victim.hpp"

class Sindragosa : public virtual Victim {
public:
    Sindragosa(const std::string &name);
    Sindragosa(Sindragosa const &copy);
    virtual ~Sindragosa();

    Sindragosa &operator=(const Sindragosa &copy);

    virtual void    getPolymorphed(void) const;
private:
};

std::ostream    &operator<<(std::ostream &o, const Sindragosa &c);
