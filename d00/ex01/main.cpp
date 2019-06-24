#include "phonebook.hpp"

# define MAX_COMMANDS 3

static size_t   gMaxCurrentlyAddedContacts;

void    fnptr_exit(PhoneBookContact *pb) { (void)pb; exit(EXIT_SUCCESS); }
void    fnptr_add(PhoneBookContact *pb) {
    std::string temp;

    if (MAX_PHONE_BOOK_CONTACTS <= gMaxCurrentlyAddedContacts) {
        std::cout << "Phone book is full. Cannot add new contact." << std::endl;
        return ;
    }
    std::cout << "Enter first name: "; std::getline(std::cin, temp); pb[gMaxCurrentlyAddedContacts].firstName = *new std::string(temp);
    std::cout << "Enter last name: "; std::getline(std::cin, temp); pb[gMaxCurrentlyAddedContacts].lastName = *new std::string(temp);
    std::cout << "Enter nickname: "; std::getline(std::cin, temp); pb[gMaxCurrentlyAddedContacts].nickname = *new std::string(temp);
    std::cout << "Enter login: "; std::getline(std::cin, temp); pb[gMaxCurrentlyAddedContacts].login = *new std::string(temp);
    std::cout << "Enter postal address: "; std::getline(std::cin, temp); pb[gMaxCurrentlyAddedContacts].postalAddress = *new std::string(temp);
    std::cout << "Enter email address: "; std::getline(std::cin, temp); pb[gMaxCurrentlyAddedContacts].emailAddress = *new std::string(temp);
    std::cout << "Enter phone number: "; std::getline(std::cin, temp); pb[gMaxCurrentlyAddedContacts].phoneNumber = *new std::string(temp);
    std::cout << "Enter birthday date: "; std::getline(std::cin, temp); pb[gMaxCurrentlyAddedContacts].birthdayDate = *new std::string(temp);
    std::cout << "Enter favorite meal: "; std::getline(std::cin, temp); pb[gMaxCurrentlyAddedContacts].favoriteMeal = *new std::string(temp);
    std::cout << "Enter underwear color: "; std::getline(std::cin, temp); pb[gMaxCurrentlyAddedContacts].underwearColor = *new std::string(temp);
    std::cout << "Enter darkest secret: "; std::getline(std::cin, temp); pb[gMaxCurrentlyAddedContacts].darkestSecret = *new std::string(temp);
    std::cout << "\tSuccessfully added new contact" << std::endl;
    ++gMaxCurrentlyAddedContacts;
}

static void printAllContacts(PhoneBookContact *pb) {
    size_t  i = ~0ULL;

    while (gMaxCurrentlyAddedContacts > ++i)
        pb[i].printShortWrappedInfo(i + 1);
}

void    fnptr_seach(PhoneBookContact *pb) {
    if (!gMaxCurrentlyAddedContacts) {
        std::cout << "No contacts currently exists in your phone book" << std::endl;
        return ;
    }
    printAllContacts(pb);

    std::string temp_index;
    std::cout << "Enter index: "; std::getline(std::cin, temp_index);
    int index = atoi(temp_index.c_str());
    if (gMaxCurrentlyAddedContacts < (size_t)index || 1 > index) {
        std::cout << "Invalid index" << std::endl;
        return ;
    }
    pb[index - 1].printAllInfo(index);
}

typedef void (*fnptrProcessCommand)(PhoneBookContact*);

static const std::string gCommandsQueue[MAX_COMMANDS] = { "EXIT", "ADD", "SEARCH" };
static const fnptrProcessCommand gCommandsQueueFunctions[MAX_COMMANDS] = { fnptr_exit,
                                                                            fnptr_add,
                                                                            fnptr_seach };

static void processCurrentCommand(const std::string currCommand, PhoneBookContact *phoneBook) {
    size_t  i = ~0ULL;

    while (MAX_COMMANDS > ++i)
        if (gCommandsQueue[i] == currCommand)
            gCommandsQueueFunctions[i](phoneBook);
}

int main(void) {
    PhoneBookContact phoneBook[MAX_PHONE_BOOK_CONTACTS];
    std::string currCommand;
    bool quit = false;

    gMaxCurrentlyAddedContacts = 0;
    std::cout << "ADD | SEARCH | EXIT" << std::endl;
    while (!quit) {
        std::cout << "@phonebook: "; std::getline(std::cin, currCommand);
        processCurrentCommand(currCommand, phoneBook);
    }
}
