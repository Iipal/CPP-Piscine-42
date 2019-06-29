#include "Cure.hpp"

Cure::Cure() : AMateria("cure") { }
Cure::Cure(const Cure &copy) : AMateria("cure") { *this = copy; }
Cure::~Cure() { }

Cure &Cure::operator=(const Cure &copy) {
    if (this != &copy) { *this = copy; }
    return *this;
}

AMateria *Cure::clone(void) const { return new Cure; }

void Cure::use(ICharacter &target) {
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
    AMateria::use(target);
}
