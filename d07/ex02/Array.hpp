#pragma once

#include <iostream>

class Array {
public:
    Array();
    Array(size_t n);
    Array(Array const &copy);
    virtual ~Array();

    Array &operator=(Array const &copy);

private:

};

std::ostream    &operator<<(std::ostream &o, Array const &c);
