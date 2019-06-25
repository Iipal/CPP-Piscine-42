#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(void) {}
ZombieEvent::~ZombieEvent(void) {}

std::string ZombieEvent::randomNames[] = {"Luicy", "Barak Obema", "Justin", "Merlin Monro", "Yakuza"};
std::string ZombieEvent::randomTypes[] = {"Women", "President", "People", "Illuminati", "Killer"};

Zombie  *ZombieEvent::newZombie(std::string name) {
    Zombie  *out = new Zombie();

    out->setName(name);
    out->setType(this->_type);
    return out;
}

Zombie  *ZombieEvent::randomChump(void) {
    Zombie  *out = new Zombie();

    out->setName(this->__nameGenerator());
    out->setType(this->_type);
    out->announce();
    return out;
}

void    ZombieEvent::setZombieType(std::string type) { this->_type = type; }
void    ZombieEvent::setZombieRandomType(void) { this->_type = this->__typeGenerator(); }

std::string ZombieEvent::__nameGenerator(void) {
    srand(time(NULL));
    return ZombieEvent::randomNames[rand() % 5];
}

std::string ZombieEvent::__typeGenerator(void) {
    srand(time(NULL));
    return ZombieEvent::randomTypes[rand() % 5];
}
