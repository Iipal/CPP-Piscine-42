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

    this->_charType = dislpayableChar;
    while (this->_str[++i] && isblank(this->_str[i])) ;
    if (!isdigit(this->_str[i])) {
        this->_charType = impossibleDisplayableChar;
    } else {
        const int ch = static_cast<int>(_str[i]);
        if (32 > ch || 127 < ch) {
            this->_charType = nonDislpayableChar;
        }
    }

    if (dislpayableChar == this->_charType) {
        this->_toPrintCh = this->_str[i];
    }
    (void)this->_summaryMaxValue;
}

void Convert::printChar(void) const {
    std::cout << "char: ";
    if (this->_charType == dislpayableChar) {
        std::cout << static_cast<char>(this->_str[0]);
    } else if (this->_charType == nonDislpayableChar) {
        std::cout << "Non displayable";
    } else if (this->_charType == impossibleDisplayableChar) {
        std::cout << "impossible";
    }
    std::cout << std::endl;
}
