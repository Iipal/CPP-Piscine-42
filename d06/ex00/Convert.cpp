#include "Convert.hpp"

Convert::Convert() { }
Convert::Convert(std::string const &str) : _str(str), _summaryMaxValue(atof(str.c_str())) {
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
Convert::Convert(Convert const &copy) { *this = copy; }
Convert::~Convert() { }

Convert &Convert::operator=(Convert const &copy) {
    if (this != &copy) { *this = copy; }
    return *this;
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
        if (this->_isPseudoLiteral(this->_str.c_str())) {
            std::cout << this->_str;
            if (!this->_str.compare(this->_str.length() - 3, 3, "inf")) {
                std::cout << 'f';
            }
        } else {
            std::cout << "impossible";
        }
    } else {
        const float f = static_cast<float>(this->_summaryMaxValue);

        std::cout << f;

        const int decF = static_cast<int>(f);
        if (!(decF - f)) { std::cout << ".0"; }
        std::cout << 'f';
    }
    std::cout << std::endl;
}

void Convert::printDouble(void) const {
    std::cout << "double: ";
    if (this->_charType == impossibleDisplayableChar) {
        if (this->_isPseudoLiteral(this->_str.c_str())) {
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

bool Convert::_isPseudoLiteral(const char *l) const {
    static const std::string _validPseudoLiterals[] = { "nan", "+nan", "-nan", "inf", "+inf", "-inf",
                                                    "nanf", "+nanf", "-nanf", "inff", "+inff", "-inff" };
    const size_t _arrSize = sizeof(_validPseudoLiterals) / sizeof(*_validPseudoLiterals);
    size_t i = ~0ULL;

    while (_arrSize > ++i) {
        if (l == _validPseudoLiterals[i]) {
            return true;
        }
    }
    return false;
}
