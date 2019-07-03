#include "Intern.hpp"

#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern() { }
Intern::Intern(Intern const &copy) { *this = copy; }
Intern::~Intern() { }

Intern &Intern::operator=(Intern const &copy) { (void)copy; return *this; }

Form *Intern::makePardon(std::string const &target) { return new PresidentialPardonForm(target); }
Form *Intern::makeShrubbery(std::string const &target) { return new ShrubberyCreationForm(target); }
Form *Intern::makeRobotomy(std::string const &target) { return new RobotomyRequestForm(target); }

Form *Intern::makeForm(std::string const &formRequestType, std::string const &formRequestTarget) {
    Form *out = NULL;

    const static fnptrValidFormTypes fnMakeFormTypes[] = { &Intern::makePardon, &Intern::makeShrubbery, &Intern::makeRobotomy };
    const static std::string _validRequestTypes[] = { "pardon", "robotomy", "shrubbery" };

    size_t _vrtSize = sizeof(_validRequestTypes) / sizeof(*_validRequestTypes);

    while (_vrtSize--) {
        if (_validRequestTypes[_vrtSize] == formRequestType) {
            out = (this->*fnMakeFormTypes[_vrtSize])(formRequestTarget); break ;
        }
    }

    try {
        if (!out) {
            throw InvalidRequestTypeException();
        }
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return out;
}

Intern::InvalidRequestTypeException::InvalidRequestTypeException() { }
Intern::InvalidRequestTypeException::InvalidRequestTypeException(InvalidRequestTypeException const &copy) { *this = copy; }
Intern::InvalidRequestTypeException::~InvalidRequestTypeException() throw() { }

Intern::InvalidRequestTypeException &Intern::InvalidRequestTypeException::operator=(Intern::InvalidRequestTypeException const &copy) { (void)copy; return *this; }

const char *Intern::InvalidRequestTypeException::what(void) const throw() { return "Exception: Invalid form request type."; }
