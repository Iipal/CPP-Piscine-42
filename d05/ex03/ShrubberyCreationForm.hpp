#pragma once

#include "Form.hpp"

class Form;

class ShrubberyCreationForm : public Form {
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string const &target);
    ShrubberyCreationForm(ShrubberyCreationForm const &copy);
    virtual ~ShrubberyCreationForm();

    ShrubberyCreationForm &operator=(ShrubberyCreationForm const &copy);

    void action(void) const;
    void execute(Bureaucrat const &executor) const;
};
