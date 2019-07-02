#pragma once

#include "Form.hpp"

class Form;

class PresidentialPardonForm : public Form {
public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string const &target);
    PresidentialPardonForm(PresidentialPardonForm const &copy);
    virtual ~PresidentialPardonForm();

    PresidentialPardonForm &operator=(PresidentialPardonForm const &copy);

    void action(void) const;
    void execute(Bureaucrat const &executor) const;
};
