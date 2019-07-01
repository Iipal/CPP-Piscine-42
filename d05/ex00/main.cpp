#include "Bureaucrat.hpp"

int main(void) {
    Bureaucrat aa("aa", 1);
    std::cout << aa;
    Bureaucrat c = aa;
    std::cout << c;
    try {
        Bureaucrat b = Bureaucrat("Barby", 0);
        std::cout << b;
        b += 2;
        std::cout << b;
        b += 147;
        std::cout << b;
        b += 1;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}
