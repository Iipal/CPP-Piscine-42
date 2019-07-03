#pragma once

#include <iostream>

class Form;

class Intern {
public:
    Intern();
    Intern(Intern const &copy);
    virtual ~Intern();

    Intern &operator=(Intern const &copy);

    Form *makeForm(std::string const &formRequestType, std::string const &formRequestTarget);

    class InvalidRequestTypeException : public std::exception {
    public:
        InvalidRequestTypeException();
        InvalidRequestTypeException(InvalidRequestTypeException const &copy);
        virtual ~InvalidRequestTypeException() throw();

        InvalidRequestTypeException &operator=(InvalidRequestTypeException const &copy);

        const char *what(void) const throw();
    };

private:
    typedef Form *(Intern::*fnptrValidFormTypes)(std::string const&);
    Form *makePardon(std::string const&);
    Form *makeShrubbery(std::string const&);
    Form *makeRobotomy(std::string const&);
};
