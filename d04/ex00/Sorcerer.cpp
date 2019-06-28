#include "Sorcerer.hpp"

Sorcerer::Sorcerer(const std::string &name, const std::string &title) : _name(name), _title(title) {
    std::cout << this->getNameTitle() << ", is born !" << std::endl;
}
Sorcerer::Sorcerer(const Sorcerer &copy) { *this = copy; }
Sorcerer::~Sorcerer() {
    std::cout << this->getNameTitle() << ", is dead. Consequences will never be the same !" << std::endl;
}

Sorcerer &Sorcerer::operator=(const Sorcerer &copy) {
    if (this != &copy) { *this = copy; }
    return *this;
}

void    Sorcerer::polymorph(Victim const &v) const { v.getPolymorphed(); }

std::string Sorcerer::getNameTitle(void) const { return this->_name + ", " + this->_title ; }

std::ostream &operator<<(std::ostream &o, const Sorcerer &c) {
    o << "I am " << c.getNameTitle() << ", and I like ponies !" << std::endl;
    return o;
}
