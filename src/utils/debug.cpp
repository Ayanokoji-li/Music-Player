#include "utils/debug.h"
#include <iostream>

DebugLogger::DebugLogger(std::string file_name) {
    logFile.open(file_name, std::ios::out);
    if (!logFile.is_open()) {
        std::cerr << "Failed to open log file " << file_name << std::endl;
        std::cerr << "Use default log file " << DEFAULT_LOG_FILE << std::endl;
        logFile.open(DEFAULT_LOG_FILE, std::ios::out);
        if (!logFile.is_open()) {
            std::cerr << "Failed to open default log file " << DEFAULT_LOG_FILE
                      << std::endl;
        }
    }
}

DebugLogger::~DebugLogger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

std::string DebugLogger::Level2string(Level level) {
    switch (level) {
        case INFO:
            return "[INFO]: ";
        case WARNING:
            return "[WARNING !]: ";
        case ERROR:
            return "[ERROR !!!]: ";
        default:
            return "[UNKNOWN]: ";
    }
}

void DebugLogger::Log(const std::string& message, DebugLogger::Level level) {
    auto msg = DebugLogger::Level2string(level) + message + "\n";
    logFile << msg;
}

namespace Debug {

static DebugLogger* logger = nullptr;

void initLog(std::string file_name) {
    logger = new DebugLogger{file_name};
}

void Log(const std::string& message, DebugLogger::Level level) {
#ifdef DEBUG
    if (!logger) {
        initLog();
    }
    logger->Log(message, level);
#endif
}

void closeLog() {
    delete logger;
}

}  // namespace Debug
