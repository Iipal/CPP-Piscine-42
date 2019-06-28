#pragma once

#include <iostream>

#include "Victim.hpp"

class Sorcerer {
public:
    Sorcerer(const std::string &name, const std::string &title);
    Sorcerer(Sorcerer const &copy);
    ~Sorcerer();

    Sorcerer &operator=(const Sorcerer &copy);

    void            polymorph(Victim const &) const;

    std::string getNameTitle(void) const;
private:
    std::string _name, _title;
};

std::ostream    &operator<<(std::ostream &o, const Sorcerer &c);
