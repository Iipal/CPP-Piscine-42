#pragma once

#include <iostream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
public:
    Form();
    Form(std::string const &name, int const gradeToSign, int const gradeToExecute);
    Form(Form const &copy);
    virtual ~Form();

    Form &operator=(Form const &copy);

    bool getIsSign(void) const;
    int getGradeToSign(void) const;
    int getGradeToExecute(void) const;
    std::string const &getName(void) const;

    void beSigned(Bureaucrat const&);

    class GradeTooLowException : public std::exception {
    public:
        GradeTooLowException();
        GradeTooLowException(GradeTooLowException const&);
        virtual ~GradeTooLowException() throw();

        GradeTooLowException &operator=(GradeTooLowException const &copy);

        virtual const char *what(void) const throw();
    };

    class GradeTooHighException : public std::exception {
    public:
        GradeTooHighException();
        GradeTooHighException(GradeTooHighException const&);
        virtual ~GradeTooHighException() throw();

        GradeTooHighException &operator=(GradeTooHighException const &copy);

        virtual const char *what(void) const throw();
    };

private:
    std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;
};

std::ostream    &operator<<(std::ostream &o, Form const &c);
