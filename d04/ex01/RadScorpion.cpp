#include "RadScorpion.hpp"

RadScorpion::RadScorpion() : Enemy(80, "Rad Scorpion") { std::cout << "* click click click *" << std::endl; }
RadScorpion::RadScorpion(const RadScorpion &copy) { *this = copy; }
RadScorpion::~RadScorpion() { std::cout << "* SPROTCH *" << std::endl; }

RadScorpion &RadScorpion::operator=(const RadScorpion &copy) {
    if (this != &copy) { *this = copy; }
    return *this;
}
