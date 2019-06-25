#include "Logger.hpp"

Logger::Logger(const std::string &log_out_file) : _log_out_file(log_out_file) {}
Logger::Logger() {}
Logger::~Logger() {}

void    Logger::logToFile(const std::string &str) const {
    std::ofstream   out(this->_log_out_file, std::ios::app);

    out << str << std::endl;
    out.close();
}

void    Logger::logToConsole(const std::string &str) const { std::cout << str << std::endl; }

std::string Logger::makeLogEntry(const std::string &str) const {
    char    out[MAX_CANON];
    std::time_t time = std::time(nullptr);
    if (!std::strftime(out, sizeof(out), "[%Y%m%d_%H%M%S] ", std::localtime(&time)))
        return "[error_get_time]" + std::string(out);
    return out + str;
}

typedef void    (Logger::*fnptrLoggerOutput)(const std::string&) const;

void    Logger::log(std::string const &dest, std::string const &msg) {
    static const fnptrLoggerOutput  fnLogOuts[] = {&Logger::logToFile, &Logger::logToConsole};
    static const std::string        dstLogOuts[] = {"logToFile", "logToConsole"};

    size_t  i = ~0ULL;
    while (2 > ++i)
        if (dstLogOuts[i] == dest) {
            (this->*fnLogOuts[i])(msg);
            return ;
        }
    std::cout << "Unknown dest for log out" << std::endl;
}
