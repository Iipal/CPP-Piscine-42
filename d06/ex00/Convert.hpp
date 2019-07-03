#pragma once

#include <iostream>
#include <string.h>
#include <ctype.h>

class Convert {
public:
    Convert();
    Convert(std::string const &str);
    Convert(Convert const &copy);
    virtual ~Convert();

    Convert &operator=(Convert const &copy);

    void parseString(void);

    void printChar(void) const;

private:
    enum eCharType { dislpayableChar,
                    nonDislpayableChar,
                impossibleDisplayableChar } _charType;

    std::string _str;
    double _summaryMaxValue;
    char _toPrintCh;
};
