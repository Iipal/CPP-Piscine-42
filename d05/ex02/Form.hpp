#pragma once

#include <iostream>
#include <fstream>

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

    void execute(Bureaucrat const &executor) const;
    virtual void action(void) const = 0;
    virtual void execute(Bureaucrat const &executor) const = 0;

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

    class FormIsntSigned : public std::exception {
    public:
        FormIsntSigned();
        FormIsntSigned(FormIsntSigned const&);
        virtual ~FormIsntSigned() throw();

        FormIsntSigned &operator=(FormIsntSigned const &copy);

        virtual const char *what(void) const throw();
    };

private:
    std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;
};

std::ostream    &operator<<(std::ostream &o, Form const &c);
