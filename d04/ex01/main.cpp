#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "Flamer.hpp"

#include "Character.hpp"

#include "RadScorpion.hpp"
#include "SuperMutant.hpp"
#include "DeadEye.hpp"

static void recoverZaz(Character *zaz) {
    std::cout << std::endl << *zaz;
    while (40 != zaz->getAP()) {
        zaz->recoverAP();
        std::cout << *zaz;
    }
}

int main(void) {
    Character   *zaz = new Character("zaz");

    std::cout << *zaz;

    Enemy   *scorpion = new RadScorpion();

    AWeapon *pr = new PlasmaRifle();
    AWeapon *pf = new PowerFist();

    zaz->equip(pr);
    std::cout << *zaz;
    zaz->equip(pf);

    zaz->attack(scorpion);
    std::cout << *zaz << std::endl;

    Enemy   *mutant = new SuperMutant();

    zaz->equip(pr);
    while (true) {
        if (0 >= mutant->getHP())
            break ;
        if (zaz->getWeapon()->getAPCost() > zaz->getAP() - zaz->getWeapon()->getAPCost())
            recoverZaz(zaz);
        else
            zaz->attack(mutant);
    }

    recoverZaz(zaz);

    std::cout << std::endl;
    zaz->equip(pf);
    std::cout << *zaz;
    zaz->attack(scorpion);

    if (0 < scorpion->getHP())
        delete scorpion;
    if (0 < mutant->getHP() )
        delete mutant;

    recoverZaz(zaz);

    Enemy   *death = new DeadEye();

    AWeapon *f = new Flamer();

    zaz->equip(f);

    zaz->attack(death);
    std::cout << *zaz;
    zaz->attack(death);
    std::cout << *zaz;
    zaz->attack(death);
    std::cout << *zaz;
    zaz->attack(death);
    std::cout << *zaz;

    recoverZaz(zaz);

    zaz->attack(death);
    std::cout << std::endl << *zaz;

    if (0 < death->getHP())
        delete death;
    delete pr; delete pf; delete f;
}
