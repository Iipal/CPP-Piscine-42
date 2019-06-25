#include "Human.hpp"

int main(void) {
    Human   bob;

    std::cout << bob.indentify() << std::endl;
    std::cout << bob.getBrain().indetify() << std::endl;
}
