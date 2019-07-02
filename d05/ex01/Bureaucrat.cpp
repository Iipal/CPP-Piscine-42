#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() { }
Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name), _grade(grade) {
    if (1 > this->_grade) {
        throw Bureaucrat::GradeTooHighException();
    }
    if (150 < this->_grade) {
        throw Bureaucrat::GradeTooLowException();
    }
}
Bureaucrat::Bureaucrat(const Bureaucrat &copy) { *this = copy; }
Bureaucrat::~Bureaucrat() { }

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy) {
    if (this != &copy) {
        this->_grade = copy._grade;
        this->_name = copy._name;
    }
    return *this;
}

const std::string &Bureaucrat::getName(void) const { return this->_name; }
int Bureaucrat::getGrade(void) const { return this->_grade; }

void Bureaucrat::signForm(Form &f) const {
    try {
        f.beSigned(*this);
        std::cout << this->_name << " signs " << f.getName() << "." << std::endl;
    } catch (std::exception &e) {
        std::cout << this->_name << " cannot sign " << f.getName()
            << " because " << e.what() << std::endl;;
    }
}

void Bureaucrat::operator+=(int const i) {
    if (1 > this->_grade - i) {
        throw Bureaucrat::GradeTooHighException();
    } else {
        this->_grade -= i;
    }
}
void Bureaucrat::operator-=(int const i) {
    if (150 < this->_grade + i) {
        throw Bureaucrat::GradeTooLowException();
    } else {
        this->_grade += i;
    }
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &c) {
    o << c.getName() << ", bureaucrat grade " << c.getGrade() << std::endl;
    return o;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(void) { }
Bureaucrat::GradeTooHighException::GradeTooHighException(GradeTooHighException const &copy) { *this = copy; }
Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw () { }

Bureaucrat::GradeTooHighException &Bureaucrat::GradeTooHighException::operator=(GradeTooHighException const &copy) {
    if (this != &copy) {
        *this = copy;
    }
    return *this;
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw () { return "Exception: too high grade."; }

Bureaucrat::GradeTooLowException::GradeTooLowException(void) { }
Bureaucrat::GradeTooLowException::GradeTooLowException(GradeTooLowException const &copy) { *this = copy; }
Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw () { }

Bureaucrat::GradeTooLowException &Bureaucrat::GradeTooLowException::operator=(GradeTooLowException const &copy) {
    if (this != &copy) {
        *this = copy;
    }
    return *this;
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw () { return "Exception: too low grade."; }
