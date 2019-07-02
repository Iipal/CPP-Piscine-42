#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void) {
    srand(time(NULL));
    Form *f[3];
    f[0] = new ShrubberyCreationForm;
    f[1] = new PresidentialPardonForm;
    f[2] = new RobotomyRequestForm;

    size_t i = ~0ULL;
    while (3 > ++i) {
        try {
            Bureaucrat b = Bureaucrat("Barby", 51);
            b.executeForm(*f[0]);
        } catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
}
