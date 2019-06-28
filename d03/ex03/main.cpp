#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

using std::cout;
using std::endl;

int main(void) {
    FragTrap    Bob("Bob");

    cout << Bob << endl;

    Bob.takeDamage(102);
    cout << Bob << endl;

    Bob.meleeAttack("neBob");
    Bob.rangedAttack("neBob");

    cout << Bob << endl;
    size_t  i = 6;
    while (i--) {
        if (!Bob.vaulthunter_dot_exe("noBob")) {
            cout << Bob << endl;
            Bob.beRapired(100);
        }
        cout << Bob << endl;
    }


    Bob.beRapired(100);
    cout << Bob << endl;
    Bob.beRapired(75);

    std::cout << "\n\t\tSCAV TESTS\n\n" << std::endl;

    ScavTrap    neBob("neBob");
    cout << neBob << endl;

    neBob.takeDamage(42);
    cout << neBob << Bob << endl;

    neBob.meleeAttack("Bob");
    neBob.rangedAttack("Bob");

    cout << neBob << endl;

    i = 11;
    while (i--) {
        if (!neBob.challengeNewcomer("Bob")) {
            cout << neBob << endl;
            neBob.beRapired(20);
        }
        cout << neBob << endl;
    }

    neBob.beRapired(100);
    cout << neBob << endl;
    neBob.beRapired(1245U);
}
