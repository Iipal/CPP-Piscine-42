#include "commandsQueue.namespace.hpp"

void    commandsQueue::fnptrExit(PhoneBookContact *pb) { (void)pb; exit(EXIT_SUCCESS); }
void    commandsQueue::fnptrHelp(PhoneBookContact *pb) {
    (void)pb;
    std::cout << "HELP: EXIT | CLEAR | DELETE | ADD | LIST | SEARCH" << std::endl;
}

void    commandsQueue::fnptrClear(PhoneBookContact *pb) {
    (void)pb;
    if (PhoneBookContact::_maxCurrentlyAddedContacts) {
        --PhoneBookContact::_maxCurrentlyAddedContacts;
        std::cout << "Last added contact was successful clear." << std::endl;
    }
    else
        std::cout << ERR_NO_CONTACTS << std::endl;
}

void    commandsQueue::fnptrDelete(PhoneBookContact *pb) {
    (void)pb;
    PhoneBookContact::_maxCurrentlyAddedContacts = 0;
    std::cout << "All contacts what was exist(or not) successful deleted." << std::endl;
}

void    commandsQueue::fnptrAdd(PhoneBookContact *pb) {
    std::string temp;

    if (MAX_PHONE_BOOK_CONTACTS <= PhoneBookContact::_maxCurrentlyAddedContacts) {
        std::cout << "Phone book is full. Cannot add new contact." << std::endl;
        return ;
    }
    pb[PhoneBookContact::_maxCurrentlyAddedContacts].addNewContactData();
}

void    commandsQueue::fnptrList(PhoneBookContact *pb) {
    if (!PhoneBookContact::_maxCurrentlyAddedContacts) {
        std::cout << ERR_NO_CONTACTS << std::endl;
        return ;
    }

    std::cout << std::setw(SHORT_OUTPUT_WRAP) << "index" << '|'
        << std::setw(SHORT_OUTPUT_WRAP) << "First name" << '|'
        << std::setw(SHORT_OUTPUT_WRAP) << "Last name" << '|'
        << std::setw(SHORT_OUTPUT_WRAP) << "Nickname" << '|' << std::endl;

    size_t  i = ~0ULL;
    while (PhoneBookContact::_maxCurrentlyAddedContacts > ++i)
        pb[i].printShortWrappedInfo(i + 1);
}

void    commandsQueue::fnptrSearch(PhoneBookContact *pb) {
    commandsQueue::fnptrList(pb);

    std::string temp_index;
    std::cout << "Enter index: "; std::getline(std::cin, temp_index);
    int index = atoi(temp_index.c_str());

    if (PhoneBookContact::_maxCurrentlyAddedContacts < (size_t)index || 1 > index) {
        std::cout << "Invalid index" << std::endl;
        return ;
    }

    pb[index - 1].printAllInfo(index);
}

void    commandsQueue::processCurrentCommand(const std::string currCommand, PhoneBookContact *phoneBook) {
    size_t  i = ~0ULL;

    while (MAX_COMMANDS > ++i)
        if (commandsQueue::commandsQueue[i] == currCommand)
            commandsQueue::commandsQueueFunctions[i](phoneBook);
}
