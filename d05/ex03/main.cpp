#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main(void) {
    Intern  i;
    Form *f;

    f = i.makeForm("robotomy", "Bender");
    std::cout << *f;
    delete f;
    f = i.makeForm("trash", "Meh");
    std::cout << f;
}
