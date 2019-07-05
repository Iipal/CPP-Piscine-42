#include "easyfind.hpp"
#include <iostream>
#include <list>

int main(void) {
    std::list<int>::iterator res;
    std::list<int> lst;

    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);

    res = easyfind(lst, 3);
    if (res != lst.end()) {
        std::cout << *res << " founded." << std::endl;
    } else {
        std::cout << "3 not found." << std::endl;
    }

    *res = -42;

    res = easyfind(lst, 3);
    if (res != lst.end()) {
        std::cout << *res << "founded." << std::endl;
    } else {
        std::cout << "3 not found." << std::endl;
    }
}
