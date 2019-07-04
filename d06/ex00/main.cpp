#include <iostream>
#include "Convert.hpp"

int main(int argc, char *argv[]) {
    --argc; ++argv;
    if (1 == argc) {
        Convert c(*argv);
        c.parseString();

        c.printChar();
        c.printInt();
        c.printFloat();
        c.printDouble();
    }
}
