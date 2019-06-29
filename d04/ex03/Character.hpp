#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"

#define MAX_SLOTS 4

class Character : public ICharacter {
public:
    Character(std::string const &name);
    Character(Character const &copy);
    virtual ~Character();

    Character &operator=(const Character &copy);

    std::string const &getName(void) const;

    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);
private:
    std::string name_;
    AMateria *items_[MAX_SLOTS];
};
