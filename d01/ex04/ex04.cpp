#include <iostream>
#include <iomanip>

int main(void) {
   	std::string str = "HI THIS IS BRAIN";

    std::string *ptr = &str;
    std::string &ref = str;

    std::cout << *ptr << std::endl << ref << std::endl;
}
