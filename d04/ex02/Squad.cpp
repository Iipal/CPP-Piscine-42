#include "Squad.hpp"

Squad::Squad() : _count(0) { }
Squad::Squad(const Squad &copy) { *this = copy; }
Squad::~Squad() {
    if (this->_count) {
        int i = -1;
        while (this->_count > ++i)
            delete this->_units[i];
    }
}

Squad &Squad::operator=(const Squad &copy) {
    if (this != &copy) {
        int i = -1;
        while (this->getCount() > ++i)
            delete this->_units[i];
        i = -1;
        while (copy.getCount() > ++i)
            this->_units[i] = copy.getUnit(i)->clone();
        this->_count = copy.getCount();
    }
    return *this;
}

int Squad::getCount(void) const { return this->_count; }
ISpaceMarine *Squad::getUnit(int n) const {
    return ((0 <= n) && (this->_count > n))
        ? this->_units[n] : NULL;
}
int Squad::push(ISpaceMarine *spaceMarine) {
    if (spaceMarine) {
        if (MAX_UNITS > this->_count) {
            this->_units[this->_count++] = spaceMarine;
        }
    }
    return this->_count;
}
