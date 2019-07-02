#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() { }
PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : Form(target, 25, 5) { }
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy) { *this = copy; }
PresidentialPardonForm::~PresidentialPardonForm() { }

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &copy) { (void)copy; return *this; }

void PresidentialPardonForm::action(void) const {
    std::cout << this->getName() << " has been pardnoned by Zaphod Beeblebrox." << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    if (executor.getGrade() > this->getGradeToExecute()) {
        throw Form::GradeTooLowException();
    } else if (!this->getIsSign()) {
        throw Form::FormIsntSigned();
    }
    this->action();
}
