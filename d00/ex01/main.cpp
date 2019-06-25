#include "phoneBookContact.class.hpp"
#include "commandsQueue.namespace.hpp"

int main(void) {
    PhoneBookContact phoneBook[MAX_PHONE_BOOK_CONTACTS];
    std::string currCommand;
    bool quit = false;

    while (!quit) {
        std::cout << "@phonebook: "; std::getline(std::cin, currCommand);
        if (std::cin.bad() || std::cin.eof()) {
            std::cout << "error in stream input" << std::endl;
            quit = true;
        }
        else
            commandsQueue::processCurrentCommand(currCommand, phoneBook);
    }
}
