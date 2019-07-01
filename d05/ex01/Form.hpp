#pragma once

#include "Bureaucrat.hpp"

class Form {
public:
    Form();
    Form(std::string const &name, int const gradeToSign, int const gradeToExecute);
    Form(Form const &copy);
    virtual ~Form();

    Form &operator=(Form const &copy);

    std::string const &getName(void) const;
    bool getIsSign(void) const;
    int getGradeToSign(void) const;
    int getGradeToExecute(void) const;

    bool beSigned(Bureaucrat const&);

private:
    std::string const _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;
};

std::ostream    &operator<<(std::ostream &o, Form const &c);
