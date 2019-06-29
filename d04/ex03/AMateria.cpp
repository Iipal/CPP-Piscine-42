#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : type_(type), xp_(0) {}
AMateria::AMateria(const AMateria &copy) { *this = copy; }
AMateria::~AMateria() { }

AMateria &AMateria::operator=(const AMateria &copy) {
    if (this != &copy) { *this = copy; }
    return *this;
}

std::string const &AMateria::getType(void) const { return this->type_; }
unsigned int AMateria::getXP(void) const { return this->xp_; }
void AMateria::use(ICharacter &target) {
    this->xp_ += 10;
    (void)target;
}
