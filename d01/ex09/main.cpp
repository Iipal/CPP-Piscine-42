#include "Logger.hpp"

int main(int argc, char *argv[]) {
    --argc; ++argv;

    if (!argc) {
        std::cout << "Usage: ./logger msg" << std::endl;
        return 0;
    }
    Logger  logger("out.log");
    logger.log("logToFile", "logToFile: test 1.");
    logger.log("logToConsole", "logToConsole test 2");
    logger.log("logToFile", logger.makeLogEntry("test3"));
    logger.log("logToConsole", logger.makeLogEntry("test4"));
}
