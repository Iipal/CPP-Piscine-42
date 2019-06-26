#include "Fixed.class.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed() : _value(0.0f) { }
Fixed::Fixed(const int &value) { this->_value = value << this->_bits; }
Fixed::Fixed(const float &value) { this->_value = roundf(value * this->_mypow(2, this->_bits)); }
Fixed::Fixed(Fixed const &src) { *this = src; }

Fixed::~Fixed() {}

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

float   Fixed::toFloat(void) const { return static_cast<float>(this->_value) * this->_mypow(2, -this->_bits); }
int     Fixed::toInt(void) const { return this->_value / this->_mypow(2, this->_bits); }

void    Fixed::setRawBits(int const raw) { this->_value = raw; }
int     Fixed::getRawBits(void) const { return this->_value; }

Fixed       &Fixed::min(Fixed &a, Fixed &b) { return a > b ? b : a; }
Fixed       &Fixed::max(Fixed &a, Fixed &b) { return a < b ? b : a; }
Fixed const &Fixed::min(Fixed const &a, Fixed const &b) { return a > b ? b : a; }
Fixed const &Fixed::max(Fixed const &a, Fixed const &b) { return a < b ? b : a; }

Fixed   &Fixed::operator=(Fixed const &b) {
    if (this != &b)
        this->setRawBits(b.getRawBits());
    return *this;
}

bool    Fixed::operator>(Fixed const &b) const { return b._value < this->_value; }
bool    Fixed::operator<(Fixed const &b) const { return b._value > this->_value; }
bool    Fixed::operator>=(Fixed const &b) const { return b._value <= this->_value; }
bool    Fixed::operator<=(Fixed const &b) const { return b._value >= this->_value; }
bool    Fixed::operator==(Fixed const &b) const { return b._value == this->_value; }
bool    Fixed::operator!=(Fixed const &b) const { return !(b._value == this->_value); }

Fixed   Fixed::operator+(Fixed const &b) const { return Fixed(this->toFloat() + b.toFloat()); };
Fixed   Fixed::operator-(Fixed const &b) const { return Fixed(this->toFloat() - b.toFloat()); };
Fixed   Fixed::operator*(Fixed const &b) const { return Fixed(this->toFloat() * b.toFloat()); };
Fixed   Fixed::operator/(Fixed const &b) const { return Fixed(this->toFloat() / b.toFloat()); };

Fixed   &Fixed::operator++(void) { ++this->_value; return *this; }
Fixed   &Fixed::operator--(void) { --this->_value; return *this; }
Fixed   Fixed::operator++(int) { Fixed out = *this; ++*this; return out; }
Fixed   Fixed::operator--(int) { Fixed out = *this; --*this; return out; }

std::ostream    &operator<<(std::ostream &o, Fixed const &f) { o << f.toFloat(); return o; }
