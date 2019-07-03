#include <iostream>
#include <ctype.h>

int main(int argc, char *argv[]) {
    --argc; ++argv;

    if (1 == argc) {
        const std::string str = *argv;
        const double totalRes = atof(str.c_str());
        {
            std::cout << "char: ";
            int ch = static_cast<int>(totalRes);
            if (ch >= 32 && ch <= 12)
                std::cout << ch;
            else
                std::cout << "Non displayable";
            std::cout << std::endl;
        }
        {
            std::cout << "int: " << static_cast<int>(totalRes) << std::endl;
        }

    }
}
