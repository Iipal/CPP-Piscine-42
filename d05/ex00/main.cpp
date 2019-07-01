#include "Bureaucrat.hpp"

int main(void) {
    try {
        Bureaucrat b("Barby", 150);
        std::cout << b;
        b += 2;
        std::cout << b;
        b += 147;
        std::cout << b;
    } catch (std::exception &e) {
        std::cout << "meh" << std::endl;
    }
}
