#pragma once

#include <iostream>

class   Human{
public:
    Human();
    ~Human();

    void    action(std::string const &action_name, std::string const &target);

 private:
    void    meleeAttack(std::string const &target);
    void    rangedAttack(std::string const &target);
    void    intimidatingShout(std::string const &target);

};
