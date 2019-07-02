#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() { }
ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : Form(target, 145, 137) { }
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) { *this = copy; }
ShrubberyCreationForm::~ShrubberyCreationForm() { }

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &copy) { (void)copy; return *this; }

void ShrubberyCreationForm::action(void) const {
    std::ofstream out(this->getName() + "_shrubbery");

    if (out.is_open()) {
        out << "       _-_" << std::endl        /*        _-_        */
            << "    /~~   ~~\\" << std::endl    /*     /~~   ~~\     */
            << " /~~         ~~\\" << std::endl /*  /~~         ~~\  */
            << "{               }" << std::endl /* {               } */
            << " \\  _-     -_  /" << std::endl /*  \  _-     -_  /  */
            << "   ~  \\\\ //  ~" << std::endl  /*    ~  \\ //  ~    */
            << "_- -   | | _- _" << std::endl   /* _- -   | | _- _   */
            << "  _ -  | |   -_" << std::endl   /*   _ -  | |   -_   */
            << "      // \\\\"<< std::endl;     /*       // \\       */
    }
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    if (executor.getGrade() > this->getGradeToExecute()) {
        throw Form::GradeTooLowException();
    } else if (!this->getIsSign()) {
        throw Form::FormIsntSigned();
    }
    this->action();
}
