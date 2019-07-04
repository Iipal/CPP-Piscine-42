#include "Array.hpp"

Array::Array() { }
Array::Array(size_t n) {
    size_t i = ~0ULL;

    while (n > ++i) {

    }
}
Array::Array(Array const &copy) { *this = copy; }
Array::~Array() { }

Array &Array::operator=(Array const &copy) {
    if (this != &copy) {

    }
    return *this;
}

std::ostream &operator<<(std::ostream &o, Array const &c) {
    o << "Hello, my name is Array";
    return o;
}
