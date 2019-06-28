#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"
#include "Character.hpp"

static void repairZaz(Character *zaz) {
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
            repairZaz(zaz);
        else
            zaz->attack(mutant);
    }

    repairZaz(zaz);

    std::cout << std::endl;
    zaz->equip(pf);
    std::cout << *zaz;
    zaz->attack(scorpion);

    std::cout << std::endl << *zaz;

    if (0 < scorpion->getHP())
        delete scorpion;
    if (0 < mutant->getHP() )
        delete mutant;
    delete pr; delete pf;
}
