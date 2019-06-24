#include "phonebook.hpp"

# define MAX_COMMANDS 5

static const std::string gCommandsQueue[MAX_COMMANDS] = { "EXIT", "HELP", "CLEAR", "ADD", "SEARCH" };

typedef void (*fnptrProcessCommand)(PhoneBookContact*);
void    fnptrExit(PhoneBookContact *pb);
void    fnptrHelp(PhoneBookContact *pb);

void    fnptrClear(PhoneBookContact *pb);

void    fnptrAdd(PhoneBookContact *pb);
void    fnptrSeach(PhoneBookContact *pb);

static const fnptrProcessCommand gCommandsQueueFunctions[MAX_COMMANDS] = { fnptrExit, fnptrHelp, fnptrClear, fnptrAdd, fnptrSeach };

static void processCurrentCommand(const std::string currCommand, PhoneBookContact *phoneBook) {
    size_t  i = ~0ULL;

    while (MAX_COMMANDS > ++i)
        if (gCommandsQueue[i] == currCommand)
            gCommandsQueueFunctions[i](phoneBook);
}

void    fnptrExit(PhoneBookContact *pb) { (void)pb; exit(EXIT_SUCCESS); }
void    fnptrHelp(PhoneBookContact *pb) { (void)pb; std::cout << "HELP: EXIT | CLEAR | ADD | SEARCH" << std::endl; }
void    fnptrClear(PhoneBookContact *pb) { (void)pb; PhoneBookContact::_maxCurrentlyAddedContacts = 0;}

void    fnptrAdd(PhoneBookContact *pb) {
    std::string temp;

    if (MAX_PHONE_BOOK_CONTACTS <= PhoneBookContact::_maxCurrentlyAddedContacts) {
        std::cout << "Phone book is full. Cannot add new contact." << std::endl;
        return ;
    }
    pb[PhoneBookContact::_maxCurrentlyAddedContacts].addNewContactData();
}

static void printAllContacts(PhoneBookContact *pb) {
    size_t  i = ~0ULL;

    std::cout << std::setw(SHORT_OUTPUT_WRAP) << "index" << '|'
        << std::setw(SHORT_OUTPUT_WRAP) << "First name" << '|'
        << std::setw(SHORT_OUTPUT_WRAP) << "Last name" << '|'
        << std::setw(SHORT_OUTPUT_WRAP) << "Nickname" << '|' << std::endl;
    while (PhoneBookContact::_maxCurrentlyAddedContacts > ++i)
        pb[i].printShortWrappedInfo(i + 1);
}

void    fnptrSeach(PhoneBookContact *pb) {
    if (!PhoneBookContact::_maxCurrentlyAddedContacts) {
        std::cout << "No contacts currently exists in your phone book" << std::endl;
        return ;
    }
    printAllContacts(pb);

    std::string temp_index;
    std::cout << "Enter index: "; std::getline(std::cin, temp_index);
    int index = atoi(temp_index.c_str());

    if (PhoneBookContact::_maxCurrentlyAddedContacts < (size_t)index || 1 > index) {
        std::cout << "Invalid index" << std::endl;
        return ;
    }
    pb[index - 1].printAllInfo(index);
}

int main(void) {
    PhoneBookContact phoneBook[MAX_PHONE_BOOK_CONTACTS];
    std::string currCommand;
    bool quit = false;

    while (!quit) {
        std::cout << "@phonebook: "; std::getline(std::cin, currCommand);
        if (std::cin.bad() || std::cin.eof()) {
            std::cout << "error in stream input" << std::endl;
            exit(EXIT_SUCCESS);
        }
        processCurrentCommand(currCommand, phoneBook);
    }
}
