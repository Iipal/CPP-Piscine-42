#include <iostream>
#include <fstream>

int main(int argc, char *argv[]) {
    --argc; ++argv;
    if (!argc) {
        std::string readTmp;
        while (std::getline(std::cin, readTmp))
            std::cout << readTmp << std::endl;
    } else {
        int i = -1;
        while (argc > ++i) {
            std::fstream    fileStream(argv[i]);

            if (!fileStream.is_open()) {
                std::string exec_ = "cat09tails: ";
                perror(std::string(exec_ + std::string(argv[i])).c_str()); continue ;
            }

            std::string readTmp;
            while (std::getline(fileStream, readTmp))
                std::cout << readTmp << std::endl;
        }
    }
}
