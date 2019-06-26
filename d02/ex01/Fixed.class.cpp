#include "Fixed.class.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed() : _value(0) { std::cout << "Default constructor called" << std::endl; }
Fixed::Fixed(const int &value) {
    std::cout << "Int constructor called" << std::endl;
    this->_value = value << this->_bits;
}

Fixed::Fixed(const float &value) {
    std::cout << "Float constructor called" << std::endl;
    this->_value = roundf(value * this->_mypow(2, this->_bits));
}

Fixed::Fixed(Fixed const &src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed   &Fixed::operator=(Fixed const &b) {
    std::cout << "Assignation operator called" << std::endl;
    if (this != &b)
        this->setRawBits(b.getRawBits());
    return *this;
}

float   Fixed::_mypow(float base, int exp) const {
    float   temp;

    if (!exp) return 1.0f;
    temp = Fixed::_mypow(base, exp / 2);
    if (!(exp % 2)) {
        return temp * temp;
    } else {
        if (0 < exp) {
            return base * temp * temp;
        } else {
            return (temp * temp) / base;
        }
    }
}

float   Fixed::toFloat(void) const {
    return static_cast<float>(this->_value) * this->_mypow(2, -this->_bits);
}
int     Fixed::toInt(void) const {
    return this->_value / this->_mypow(2, this->_bits);
}

void    Fixed::setRawBits(int const raw) { this->_value = raw; }
int     Fixed::getRawBits(void) const { return this->_value; }

std::ostream    &operator<<(std::ostream &o, Fixed const &f) { o << f.toFloat(); return o; }
