#include "Victim.hpp"
#include "Sorcerer.hpp"
#include "Peon.hpp"
#include "Sindragosa.hpp"

int main(void) {
    {
        std::cout << "\tJUST A FEW MY TESTS:" << std::endl;
        Sorcerer    s("Maestro", "Never before was fagot");
        Victim      v("ex-girlfriend");
        Peon        p("Employee");

        std::cout << std::endl;
        s.polymorph(v);
        s.polymorph(p);
        std::cout << std::endl;
        std::cout << s << v << p << std::endl;

        std::cout << "IT'S THE END OF MY TESTS:" << std::endl;
    }
    {
        std::cout << "\tTESTS FROM SUBJECT:" << std::endl;
        Sorcerer robert("Robert", "the Mangificent");

        Victim jim("Jimmy");
        Peon joe("Joe");
        Sindragosa  victor("Victor");

        std::cout << robert << jim << joe << victor;

        robert.polymorph(jim);
        robert.polymorph(joe);
        robert.polymorph(victor);
    }
}
