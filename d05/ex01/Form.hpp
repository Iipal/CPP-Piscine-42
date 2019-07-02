#pragma once

// #include "Bureaucrat.hpp"
class Bureaucrat;

class Form : public Bureaucrat {
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
private:
    std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;
};

std::ostream    &operator<<(std::ostream &o, Form const &c);
