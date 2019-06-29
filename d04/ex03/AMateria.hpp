#pragma once

#include <iostream>

#include "ICharacter.hpp"

class   AMateria {
public:
    AMateria(std::string const &type);
    AMateria(const AMateria &copy);
    virtual ~AMateria();

    AMateria &operator=(const AMateria &copy);
    std::string const &getType(void) const;
    unsigned int getXP(void) const;

    virtual AMateria* clone(void) const = 0;
    virtual void use(ICharacter &target);
private:
    std::string type_;
    unsigned int xp_;
};
