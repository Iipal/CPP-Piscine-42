#include <iostream>
#include <fstream>

int main(int argc, char *argv[]) {
    --argc; ++argv;

    if (3 != argc) {
        std::cout << "Usage ./replace filename string1 string2" << std::endl;
        return 0;
    }
    std::string     tmp_file = *argv++;
    std::string     s1 = *argv++;
    std::string     s2 = *argv;

    std::ifstream   _rStream(tmp_file);

    if (!_rStream.is_open() || _rStream.fail()) {
        std::cout << "Cannot open " << tmp_file << std::endl;
        return -1;
    }
    std::ofstream   _wStream(tmp_file += ".replace");
    if (!_wStream.is_open() || _wStream.fail()) {
        _rStream.close();
        std::cout << "Cannot open " << tmp_file << std::endl;
        return -1;
    }
    std::string temp_read;
    while (std::getline(_rStream, temp_read))
        if (temp_read == s1)
            _wStream << s2 << std::endl;
        else
            _wStream << temp_read << std::endl;
    _rStream.close();
    _wStream.close();
}
