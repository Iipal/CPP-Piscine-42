#include "Bureaucrat.hpp"

int main(void) {
    try {
        Form f = Form("Test", 50, 50);
        Bureaucrat b = Bureaucrat("Barby", 50);
        b.signForm(f);
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}
