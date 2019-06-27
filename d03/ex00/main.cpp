#include "FragTrap.hpp"

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
}
