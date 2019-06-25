#include "Human.hpp"

Human::Human() {}
Human::~Human() {}

std::string Human::indentify(void) const { return this->_brain.indetify(); }
Brain const &Human::getBrain(void) const { return this->_brain; }
