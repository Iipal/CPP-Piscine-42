#include "Victim.hpp"

Victim::Victim() { }
Victim::Victim(const std::string &name) : _name(name) {
    std::cout << "Some random victim called " << this->getName() << " just propped !" << std::endl;
}
Victim::Victim(const Victim &copy) { *this = copy; }
Victim::~Victim() {
    std::cout << "Victim " << this->getName() << " just died for no apparent reason !" << std::endl;
}

Victim &Victim::operator=(const Victim &copy) {
    if (this != &copy) { *this = copy; }
    return *this;
}

void    Victim::getPolymorphed(void) const {
    std::cout << this->getName() << " has been turned into a cute little sheep !" << std::endl;
}

std::string Victim::getName(void) const { return this->_name; }

std::ostream &operator<<(std::ostream &o, const Victim &c) {
    o << "I'm " << c.getName() << " and I like otters !" << std::endl;
    return o;
}
