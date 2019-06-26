#pragma once

#include <iostream>
#include <ostream>
#include <cmath>

class   Fixed {
public:
    Fixed();
    Fixed(const int &value);
    Fixed(const float &value);
    Fixed(Fixed const &src);
    ~Fixed();

    Fixed   &operator=(Fixed const &b);

    float   toFloat(void) const;
    int     toInt(void) const;

    void    setRawBits(int const raw);
    int     getRawBits(void) const;

    static Fixed        &min(Fixed &a, Fixed &b);
    static Fixed        &max(Fixed &a, Fixed &b);
    static Fixed const  &min(Fixed const &a, Fixed const &b);
    static Fixed const  &max(Fixed const &a, Fixed const &b);

    bool    operator>(Fixed const &b) const;
    bool    operator<(Fixed const &b) const;
    bool    operator>=(Fixed const &b) const;
    bool    operator<=(Fixed const &b) const;
    bool    operator==(Fixed const &b) const;
    bool    operator!=(Fixed const &b) const;

    Fixed   operator+(Fixed const &b) const;
    Fixed   operator-(Fixed const &b) const;
    Fixed   operator*(Fixed const &b) const;
    Fixed   operator/(Fixed const &b) const;

    Fixed   &operator++(void);
    Fixed   &operator--(void);
    Fixed   operator++(int);
    Fixed   operator--(int);
private:
    int _value;
    static const int _bits;

    float   _mypow(float, int) const;
};

std::ostream    &operator<<(std::ostream &o, Fixed const &f);
