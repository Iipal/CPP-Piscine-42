#include "phoneBookContact.class.hpp"

PhoneBookContact::PhoneBookContact(){}
PhoneBookContact::~PhoneBookContact(){}

size_t  PhoneBookContact::_maxCurrentlyAddedContacts = 0;

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
        << " Email address: " << this->emailAddress << std::endl
        << " Phone Number: " << this->phoneNumber << std::endl
        << " Birthday date: " << this->birthdayDate << std::endl
        << " Favorite meal: " << this->favoriteMeal << std::endl
        << " Underwear color: " << this->underwearColor << std::endl
        << " Darkest secret: " << this->darkestSecret << std::endl;

}

void    PhoneBookContact::addNewContactData(void) {
    std::string temp;

    std::cout << "Enter first name: "; this->firstName = this->_pbc_getline(&temp);
    std::cout << "Enter last name: "; this->lastName = this->_pbc_getline(&temp);
    std::cout << "Enter nickname: "; this->nickname = this->_pbc_getline(&temp);
    std::cout << "Enter login: "; this->login = this->_pbc_getline(&temp);
    std::cout << "Enter postal address: "; this->postalAddress = this->_pbc_getline(&temp);
    std::cout << "Enter email address: "; this->emailAddress = this->_pbc_getline(&temp);
    std::cout << "Enter phone number: "; this->phoneNumber = this->_pbc_getline(&temp);
    std::cout << "Enter birthday date: "; this->birthdayDate = this->_pbc_getline(&temp);
    std::cout << "Enter favorite meal: "; this->favoriteMeal = this->_pbc_getline(&temp);
    std::cout << "Enter underwear color: "; this->underwearColor = this->_pbc_getline(&temp);
    std::cout << "Enter darkest secret: "; this->darkestSecret = this->_pbc_getline(&temp);
    std::cout << "\tSuccessfully added new contact." << std::endl;

    ++PhoneBookContact::_maxCurrentlyAddedContacts;
}
