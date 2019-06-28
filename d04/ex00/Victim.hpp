#pragma once

#include <iostream>

class Victim {
public:
    Victim(const std::string &name);
    Victim(Victim const &copy);
    ~Victim();

    Victim &operator=(const Victim &copy);

    virtual void    getPolymorphed(void) const;

    std::string getName(void) const;
protected:
    std::string _name;
};

std::ostream    &operator<<(std::ostream &o, const Victim &c);
