#include "phonebook.hpp"

PhoneBookContact::PhoneBookContact(){}
PhoneBookContact::~PhoneBookContact(){}

void    PhoneBookContact::printShortWrappedInfo(int index){
    std::string _firstName   = this->firstName,
                _lastName    = this->lastName,
                _nickname    = this->nickname;

    if (_firstName.length() > SHORT_OUTPUT_WRAP)
        _firstName.erase(SHORT_OUTPUT_WRAP, _firstName.length() - SHORT_OUTPUT_WRAP),
            _firstName[SHORT_OUTPUT_WRAP - 1] = '.';
    if (_lastName.length() > SHORT_OUTPUT_WRAP)
        _lastName.erase(SHORT_OUTPUT_WRAP, _lastName.length() - SHORT_OUTPUT_WRAP),
            _lastName[SHORT_OUTPUT_WRAP - 1] = '.';
    if (_nickname.length() > SHORT_OUTPUT_WRAP)
        _nickname.erase(SHORT_OUTPUT_WRAP, _nickname.length() - SHORT_OUTPUT_WRAP),
            _nickname[SHORT_OUTPUT_WRAP - 1] = '.';

    std::cout << std::setw(SHORT_OUTPUT_WRAP) << index << '|'
            << std::setw(SHORT_OUTPUT_WRAP) << _firstName << '|'
            << std::setw(SHORT_OUTPUT_WRAP) << _lastName << '|'
            << std::setw(SHORT_OUTPUT_WRAP) << _nickname << '|' << std::endl;
}

void    PhoneBookContact::printAllInfo(int index) {
    std::cout << "Info for contact on index " << index << ':' << std::endl
        << " First name: " << this->firstName << std::endl
        << " Last name: " << this->lastName << std::endl
        << " Nickname: " << this->nickname << std::endl
        << " Login: " << this->login << std::endl
        << " Postal address: " << this->postalAddress << std::endl
        << " Birthday date: " << this->birthdayDate << std::endl
        << " Favorite meal: " << this->favoriteMeal << std::endl
        << " Underwear color: " << this->underwearColor << std::endl
        << " Darkest secret: " << this->darkestSecret << std::endl;

}
