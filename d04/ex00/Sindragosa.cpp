#include "Sindragosa.hpp"
#include "Victim.hpp"

Sindragosa::Sindragosa() { }
Sindragosa::Sindragosa(const std::string &name) : Victim(name) { std::cout << "Argh. I'm the dragon MZFK." << std::endl;  }
Sindragosa::Sindragosa(const Sindragosa &copy) : Victim(copy) { *this = copy; }
Sindragosa::~Sindragosa() { std::cout << "Dragons can't die, i'm just fly away." << std::endl;  }

Sindragosa &Sindragosa::operator=(const Sindragosa &copy) {
    if (this != &copy) { *this = copy; }
    return *this;
}

void    Sindragosa::getPolymorphed(void) const {
    std::cout << this->getName() << " hsa been turned into a black crow !" << std::endl;
}

std::ostream &operator<<(std::ostream &o, const Sindragosa &c) {
    o << "I'm " << c.getName() << " and I like mouses !" << std::endl;
    return o;
}
