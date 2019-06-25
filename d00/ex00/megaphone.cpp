#include <iostream>

namespace   megaphone {
    static char *strupr(char *src) {
        size_t  i = ~0ULL;

        while (src[++i])
            src[i] = toupper(src[i]);
        return (src);
    }
}

int main(int ac, char *av[]) {
    --ac; ++av;

    if (!ac)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else {
        int i = -1;

        while (ac > ++i)
            std::cout << megaphone::strupr(av[i]);
        std::cout << std::endl;
    }
}
