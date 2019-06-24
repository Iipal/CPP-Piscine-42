#pragma once

# include <iomanip>
# include <iostream>
# include <stdlib.h>

# define MAX_PHONE_BOOK_CONTACTS 8
# define SHORT_OUTPUT_WRAP 10

class   PhoneBookContact {
    public:
    PhoneBookContact();
    ~PhoneBookContact();
    static size_t   _maxCurrentlyAddedContacts;

    void    printShortWrappedInfo(int index);
    void    printAllInfo(int index);

    void    addNewContactData(void);

    private:
    std::string _pbc_getline(std::string *cin_dst) {
        std::getline(std::cin, *cin_dst);
        if (std::cin.bad() || std::cin.eof()) {
            std::cout << "error in stream input" << std::endl;
            exit(EXIT_SUCCESS);
        }
        return *cin_dst;
    }

    std::string firstName, lastName, nickname, login,
            postalAddress, emailAddress, phoneNumber,
            birthdayDate, favoriteMeal, underwearColor, darkestSecret;
};
