#include "Pony.hpp"

Pony    ponyOnTheStack(void) { return (Pony("Leyla")); }
Pony    *ponyOnTheHeap(void) { return (new Pony("Millie")); }

int main(void) {
    std::cout << "\tCreating pony on the stack: " << std::endl;
    Pony    __sPony = ponyOnTheStack();


    std::cout << "\n\n\tCreating pony on the heap: " << std::endl;
    Pony    *__hPony = ponyOnTheHeap();

    std::cout << "\n\n\tDeleting pony on the heap: " << std::endl;
    delete __hPony;

    std::cout << "\n\n\tDeleting pony on the stack: " << std::endl;
}
