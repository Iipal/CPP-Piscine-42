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
private:
    float   _mypow(float, int) const;
    int _value;
    static const int _bits;
};

std::ostream    &operator<<(std::ostream &o, Fixed const &f);
