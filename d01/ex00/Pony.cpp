#include "Pony.hpp"

Pony::Pony() {}

Pony::Pony(std::string ponyName) {
    this->_name = ponyName;
    std::cout << "Congrats, new pony in stack was created with name: " << this->_name << std::endl
        << " ," << std::endl
        << "/,`\\" << std::endl
        << "` | \\____\\\\" << std::endl
        << " _(      ) \\" << std::endl
        << " \\-\\~~~_|\\  \\" << std::endl
        << "    \\ `   \\  `" << std::endl
        << "    `     `" << std::endl
        << "Such a good name for this little pretty *-*" << std::endl;
}

Pony::~Pony() {}