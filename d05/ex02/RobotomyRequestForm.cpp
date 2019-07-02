#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() { }
RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : Form(target, 72, 45) { }
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) { *this = copy; }
RobotomyRequestForm::~RobotomyRequestForm() { }

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &copy) { (void)copy; return *this; }

void RobotomyRequestForm::action(void) const {
    std::cout << "* bi-bu-bip brrrr bu bi-bi bu * " << this->getName();
    if (rand() % 2) {
        std::cout << " has been robotomized." << std::endl;
    } else {
        std::cout << " has been not robotomized." << std::endl;
    }
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    if (executor.getGrade() > this->getGradeToExecute()) {
        throw Form::GradeTooLowException();
    } else if (!this->getIsSign()) {
        throw Form::FormIsntSigned();
    }
    this->action();
}
