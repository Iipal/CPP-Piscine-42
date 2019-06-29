#pragma once

#include "AMateria.hpp"

class Ice : public AMateria {
public:
    Ice();
    Ice(Ice const &copy);
    virtual ~Ice();

    Ice &operator=(const Ice &copy);

    AMateria *clone(void) const;
    void use(ICharacter &target);
};
