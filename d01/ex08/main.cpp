#include "Human.hpp"

int main(int argc, char *argv[]) {
    --argc; ++argv;
    if (2 == argc) {
        Human   h;
        h.action(*argv, *(argv + 1));
    }
    else
        std::cout << "Usage: ./a.out <actionName> <target>" << std::endl;
}
