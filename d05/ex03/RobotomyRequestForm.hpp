#pragma once

#include "Form.hpp"

class Form;

class RobotomyRequestForm : public Form {
public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string const &target);
    RobotomyRequestForm(RobotomyRequestForm const &copy);
    virtual ~RobotomyRequestForm();

    RobotomyRequestForm &operator=(RobotomyRequestForm const &copy);

    void action(void) const;
    void execute(Bureaucrat const &executor) const;
};
