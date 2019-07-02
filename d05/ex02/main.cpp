#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void) {
    srand(time(NULL));
    Form *f[3];
    f[0] = new ShrubberyCreationForm("home");
    f[1] = new PresidentialPardonForm("Motherf****r");
    f[2] = new RobotomyRequestForm("Your ass");

    size_t i = ~0ULL;
    while (3 > ++i) {
        try {
            Bureaucrat b = Bureaucrat("Barby", 1);
            b.signForm(*f[i]);
            b.executeForm(*f[i]);
        } catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
}
