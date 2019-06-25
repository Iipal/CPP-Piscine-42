#include "ZombieHorde.hpp"

std::string ZombieHorde::randomHordeNames[] = {"Luicy", "Barak Obema", "Justin", "Merlin Monro", "Yakuza"};
std::string ZombieHorde::randomHordeTypes[] = {"Women", "President", "People", "Illuminati", "Killer"};

ZombieHorde::ZombieHorde(int amount) {
    this->_hordeAmount = amount;
    if (0 >= amount) {
        std::cout << "Hmm, 0 or less than 0 Zombies ? I don't understand your plan to take over the world " << std::endl;
    } else {
        this->_horde = new Zombie[amount];
        int i = -1;
        while (amount > ++i) {
            this->_horde[i].setName(ZombieHorde::_randomizeName());
            this->_horde[i].setType(ZombieHorde::_randomizeType());
        }
    }
    std::srand(std::time(nullptr));
}

ZombieHorde::~ZombieHorde() {}

void    ZombieHorde::announce(void) {
    int i = -1;

    while (this->_hordeAmount > ++i)
        this->_horde[i].announce();
}

std::string ZombieHorde::_randomizeName(void) { return ZombieHorde::randomHordeNames[std::rand() % 5]; }

std::string ZombieHorde::_randomizeType(void) { return ZombieHorde::randomHordeTypes[std::rand() % 5]; }
