#pragma once

#include "Brain.hpp"

class   Human{
public:
    Human();
    ~Human();

    std::string indentify(void) const;
    Brain const &getBrain(void) const;

private:
    Brain const _brain;
};
