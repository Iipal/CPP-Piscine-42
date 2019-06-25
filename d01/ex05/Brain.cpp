#include "Brain.hpp"

Brain::Brain(){}
Brain::~Brain(){}

std::string Brain::indetify(void) const {
    const void  *brain_address = (const void*)this;

    std::stringstream   brain_address_ss;
    brain_address_ss << brain_address;

    return "0x" + brain_address_ss.str();
}
