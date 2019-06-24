#pragma once

# include <iomanip>
# include <iostream>

# define MAX_PHONE_BOOK_CONTACTS 8
# define SHORT_OUTPUT_WRAP 10

struct  PhoneBookContact {
    PhoneBookContact();
    ~PhoneBookContact();

    void    printShortWrappedInfo(int index);
    void    printAllInfo(int index);

    std::string firstName, lastName, nickname, login,
            postalAddress, emailAddress, phoneNumber,
            birthdayDate, favoriteMeal, underwearColor, darkestSecret;
};
