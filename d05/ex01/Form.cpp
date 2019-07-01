#include "Form.hpp"

Form::Form() : _name("Form"), _isSigned(false), _gradeToSign(0), _gradeToExecute(0) { }
Form::Form(std::string const &name, int const gradeToSign, int const gradeToExecute)
 : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) { }
Form::Form(Form const &copy) : Form() { *this = copy; }
Form::~Form() { }

Form &Form::operator=(Form const &copy) {
    if (this != &copy) { *this = copy; }
    return *this;
}

std::string const &Form::getName(void) const { return this->_name; }
bool Form::getIsSign(void) const { return this->_isSigned; }
int Form::getGradeToSign(void) const { return this->_gradeToSign; }
int Form::getGradeToExecute(void) const { return this->_gradeToExecute; }

std::ostream &operator<<(std::ostream &o, Form const &c) {
    o << "Hello, my name is Form";
    return o;
}
