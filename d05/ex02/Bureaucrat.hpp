#pragma once

#include <iostream>
#include <exception>

#include "Form.hpp"

class Form;

class Bureaucrat {
public:
    Bureaucrat();
    Bureaucrat(std::string const &name, int);
    Bureaucrat(Bureaucrat const &copy);
    virtual ~Bureaucrat();

    Bureaucrat &operator=(const Bureaucrat &copy);

    std::string const &getName(void) const;
    int getGrade(void) const;

    void signForm(Form &f) const;
    void executeForm(Form const &f) const;

    void operator+=(int const i);
    void operator-=(int const i);

    class GradeTooHighException : public std::exception {
    public:
        GradeTooHighException();
        GradeTooHighException(GradeTooHighException const &copy);
        virtual ~GradeTooHighException() throw();

        GradeTooHighException &operator=(const GradeTooHighException &copy);

        virtual const char* what(void) const throw();
    };
    class GradeTooLowException : public std::exception {
    public:
        GradeTooLowException();
        GradeTooLowException(GradeTooLowException const &copy);
        virtual ~GradeTooLowException() throw();

        GradeTooLowException &operator=(const GradeTooLowException &copy);

        virtual const char* what(void) const throw();
    };
private:
    std::string _name;
    int _grade;
};

std::ostream    &operator<<(std::ostream &o, const Bureaucrat &c);
