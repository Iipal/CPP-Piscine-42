#pragma once

#include <iostream>

class   Pony {
public:
    Pony();
    Pony(std::string name);
    ~Pony();

private:
    std::string _name;
};