#pragma once

#include "phoneBookContact.class.hpp"

namespace   commandsQueue {
    #define MAX_COMMANDS 7
    #define ERR_NO_CONTACTS "No contacts currently exists in your phone book"

    static const std::string commandsQueue[MAX_COMMANDS] = {
        "EXIT", "HELP", "CLEAR", "DELETE", "ADD", "LIST", "SEARCH" };

    typedef void (*fnptrProcessCommand)(PhoneBookContact*);
    void    fnptrExit(PhoneBookContact *pb);
    void    fnptrHelp(PhoneBookContact *pb);

    void    fnptrClear(PhoneBookContact *pb);
    void    fnptrDelete(PhoneBookContact *pb);

    void    fnptrAdd(PhoneBookContact *pb);
    void    fnptrList(PhoneBookContact *pb);
    void    fnptrSearch(PhoneBookContact *pb);

    static const fnptrProcessCommand commandsQueueFunctions[MAX_COMMANDS] = {
        fnptrExit, fnptrHelp, fnptrClear, fnptrDelete, fnptrAdd, fnptrList, fnptrSearch };

    void processCurrentCommand(const std::string currCommand, PhoneBookContact *phoneBook);
}
