#include "Squad.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"

int main(void) {
    ISpaceMarine *bob = new TacticalMarine;
    ISpaceMarine *jim = new AssaultTerminator;
    ISpaceMarine *tom = new TacticalMarine;

    ISquad* vlc = new Squad;
    vlc->push(bob);
    vlc->push(jim);
    vlc->push(tom);
    for (int i = 0; vlc->getCount() > i; ++i) {
        ISpaceMarine *cur = vlc->getUnit(i);
        cur->battleCry();
        cur->rangedAttack();
        cur->meleeAttack();
    }

    ISquad *vlc_copy = vlc;
    std::cout << std::endl << "After copy(=):" << std::endl;

    for (int i = 0; vlc_copy->getCount() > i; ++i) {
        ISpaceMarine *cur = vlc_copy->getUnit(i);
        cur->battleCry();
        cur->rangedAttack();
        cur->meleeAttack();
    }

    Squad empty;
    vlc_copy = new Squad(empty);

    delete vlc;
    delete vlc_copy;
}
