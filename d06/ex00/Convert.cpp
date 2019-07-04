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
    this->_charType = dislpayableChar;

    if (!isdigit(this->_str[0])) {
        this->_charType = impossibleDisplayableChar;
    } else {
        const int ch = atoi(this->_str.c_str());
        if (32 > ch || 127 < ch) {
            this->_charType = nonDislpayableChar;
        } else {
            this->_toPrintCh = static_cast<char>(ch);
        }
    }
}

void Convert::printChar(void) const {
    std::cout << "char: ";
    if (this->_charType == dislpayableChar) {
        std::cout << '\'' << _toPrintCh << '\'';
    } else if (this->_charType == nonDislpayableChar) {
        std::cout << "Non displayable";
    } else if (this->_charType == impossibleDisplayableChar) {
        std::cout << "impossible";
    }
    std::cout << std::endl;
}

void Convert::printInt(void) const {
    std::cout << "int: ";
    if (this->_charType == impossibleDisplayableChar) {
        std::cout << "impossible";
    } else {
        std::cout << static_cast<int>(this->_summaryMaxValue);
    }
    std::cout << std::endl;
}

void Convert::printFloat(void) const {
    std::cout << "float: ";
    if (this->_charType == impossibleDisplayableChar) {
        if (this->_str == "nan" || this->_str == "-inf" || this->_str == "+inf") {
            std::cout << this->_str;
        } else {
            std::cout << "impossible";
        }
    } else {
        const float f = static_cast<float>(this->_summaryMaxValue);

        std::cout << f;

        const int decF = static_cast<int>(f);
        if (!(decF - f)) { std::cout << ".0"; }
    }
    std::cout << 'f' << std::endl;
}

void Convert::printDouble(void) const {
    std::cout << "double: ";
    if (this->_charType == impossibleDisplayableChar) {
        if (this->_str == "nan" || this->_str == "-inf" || this->_str == "+inf") {
            std::cout << this->_str;
        } else {
            std::cout << "impossible";
        }
    } else {
        std::cout << this->_summaryMaxValue;

        const int decF = static_cast<int>(this->_summaryMaxValue);
        if (!(decF - this->_summaryMaxValue)) { std::cout << ".0"; }
    }
    std::cout << std::endl;
}
