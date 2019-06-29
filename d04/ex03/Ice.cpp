#include "Ice.hpp"

Ice::Ice() : AMateria("ice") { }
Ice::Ice(const Ice &copy) : AMateria("ice") { *this = copy; }
Ice::~Ice() { }

Ice &Ice::operator=(const Ice &copy) {
    if (this != &copy) { *this = copy; }
    return *this;
}

AMateria *Ice::clone(void) const { return new Ice; }

void Ice::use(ICharacter &target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
    AMateria::use(target);
}
