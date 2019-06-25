#include "ZombieEvent.hpp"

int main(void) {
    ZombieEvent    ze;

    ze.setZombieRandomType();
    Zombie  *zzz = ze.randomChump();
    delete zzz;

    ze.setZombieType("Doogy");
    Zombie  *zz = ze.newZombie("Petty");
    zz->announce();
    delete zz;
}
