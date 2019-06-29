#pragma once

#include "AMateria.hpp"

class Cure : public AMateria {
public:
    Cure();
    Cure(Cure const &copy);
    virtual ~Cure();

    Cure &operator=(const Cure &copy);

    AMateria *clone(void) const;
    void use(ICharacter &target);
};
