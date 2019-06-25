#pragma once

#include <iostream>
#include <fstream>

class   Logger {
public:
    Logger(const std::string &log_out);
    Logger();
    ~Logger();

    std::string makeLogEntry(const std::string &str) const;

    void    log(std::string const &dest, std::string const &msg);
private:
    std::string _log_out_file;

    void    logToFile(const std::string &str) const;
    void    logToConsole(const std::string &str) const;
};
