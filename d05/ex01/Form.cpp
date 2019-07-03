#include "Form.hpp"

Form::Form() : _name("Form"), _isSigned(false), _gradeToSign(0), _gradeToExecute(0) { }
Form::Form(std::string const &name, int const gradeToSign, int const gradeToExecute)
 : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (150 < this->_gradeToSign || 150 < this->_gradeToExecute) {
        Form::GradeTooLowException();
    } else if (1 > this->_gradeToSign || 1 > this->_gradeToExecute) {
        Form::GradeTooHighException();
    }
}
Form::Form(Form const &copy) : _gradeToSign(0), _gradeToExecute(0) { *this = copy; }
Form::~Form() { }

Form &Form::operator=(Form const &copy) {
    if (this != &copy) { *this = copy; }
    return *this;
}

bool Form::getIsSign(void) const { return this->_isSigned; }
int Form::getGradeToSign(void) const { return this->_gradeToSign; }
int Form::getGradeToExecute(void) const { return this->_gradeToExecute; }
std::string const &Form::getName(void) const { return this->_name; }

void Form::beSigned(Bureaucrat const &b){
    if (b.getGrade() > _gradeToSign) {
        throw Form::GradeTooLowException();
    } else {
        this->_isSigned = true;
    }
}

std::ostream &operator<<(std::ostream &o, Form const &c) {
    o << c.getName() << " form, for sign needs grade: " << c.getGradeToSign()
        << ", for execute needs grade: " << c.getGradeToExecute()
        << ". Currently " << (c.getIsSign() ? "IS" : "NOT") << " signed." << std::endl;
    return o;
}

Form::GradeTooLowException::GradeTooLowException(void) {}
Form::GradeTooLowException::GradeTooLowException(GradeTooLowException const&) {}
Form::GradeTooLowException::~GradeTooLowException(void) throw() {}

Form::GradeTooLowException &Form::GradeTooLowException::operator=(Form::GradeTooLowException const &copy) { (void)copy; return *this;}

const char *Form::GradeTooLowException::what(void) const throw() { return "Exception: Too low grade for sign this form."; }

Form::GradeTooHighException::GradeTooHighException(void) {}
Form::GradeTooHighException::GradeTooHighException(GradeTooHighException const&) {}
Form::GradeTooHighException::~GradeTooHighException(void) throw() {}

Form::GradeTooHighException &Form::GradeTooHighException::operator=(Form::GradeTooHighException const &copy) { (void)copy; return *this; }

const char *Form::GradeTooHighException::what(void) const throw() { return "Exception: Too high grade for sign this form."; }
