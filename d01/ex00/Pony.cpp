#include "Pony.hpp"

Pony::Pony() {}

Pony::Pony(std::string ponyName) {
    this->_name = ponyName;
    std::cout << "Congrats, new pony was born, she name is: " << this->_name << std::endl
        << " ," << std::endl
        << "/,`\\" << std::endl
        << "` | \\____\\\\" << std::endl
        << " _(      ) \\" << std::endl
        << " \\-\\~~~_|\\  \\" << std::endl
        << "    \\ `   \\  `" << std::endl
        << "    `     `" << std::endl
        << "Ah, " << this->_name << ", such a good name for this little pretty *-*" << std::endl;
}

Pony::~Pony() {
    std::cout << "Oh no, this little pretty " << this->_name << " run away from u ... " << std::endl
        << ",~~_" << std::endl
        << "|/\\ =_ _ ~" << std::endl
        << " _( )_( )\\~~" << std::endl
        << " \\,\\  _|\\ \\~~~" << std::endl
        << "    \\`   \\" << std::endl
        << "    `    `" << std::endl
        << "What you done with her, bastard ... ? T.T" << std::endl;
}
