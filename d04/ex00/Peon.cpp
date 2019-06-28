#include "Peon.hpp"
#include "Victim.hpp"

Peon::Peon() { }
Peon::Peon(const std::string &name) : Victim(name) { std::cout << "Zog-zog." << std::endl; }
Peon::Peon(const Peon &copy) : Victim(copy) { *this = copy; }
Peon::~Peon() { std::cout << "Bleuark..." << std::endl; }

Peon &Peon::operator=(const Peon &copy) {
    if (this != &copy) { *this = copy; }
    return *this;
}

void    Peon::getPolymorphed(void) const {
    std::cout << this->getName() << " hsa been turned into a pink pony !" << std::endl;
}

std::ostream &operator<<(std::ostream &o, const Peon &c) {
    o << "I'm " << c.getName() << " and I like otters !" << std::endl;
    return o;
}
