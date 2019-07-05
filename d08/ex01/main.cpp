#include "span.hpp"

#define _MAX 42

int main(void) {
    srand(time(NULL));

    Span sp = Span(_MAX);

    size_t i = ~0ULL;
    while (_MAX > ++i) {
        sp.addNumber(rand() % 42);
    }

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
}
