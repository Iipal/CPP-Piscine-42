#include "Convert.hpp"

Convert::Convert() { }
Convert::Convert(std::string const &str) : _str(str), _summaryMaxValue(atof(str.c_str())) { }
Convert::Convert(Convert const &copy) { *this = copy; }
Convert::~Convert() { }

Convert &Convert::operator=(Convert const &copy) {
    if (this != &copy) { *this = copy; }
    return *this;
}

void Convert::parseString(void) {
    size_t i = ~0ULL;

    this->charType = dislpayableChar;
    while (this->_str[++i] && isblank(this->_str[i])) ;
    if (!isnumber(this->_str[i])) {
        this->charType = impossibleDisplayableChar;
    } else {
        const int ch = static_cast<int>(_str[i]);
        if (32 > ch || 127 < ch) {
            this->charType = nonDislpayableChar;
        }
    }
}

void Convert::printChar(void) const {
    if (this->charType == dislpayableChar) {

    }
}
