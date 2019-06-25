#include <iostream>
#include <iomanip>

int main(void) {
    std::string *str = new std::string("Hello World!");
    std::string &ref = *str;

    std::cout << "string on heap: " << std::setw(34) << *str << std::endl
        << "reference to string on heap on stack: " << ref << std::endl;
    delete str;
}
