#pragma once

#include <ctime>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>

#define DEFAULT_LOG_FILE "./log.txt"

class DebugLogger {
   public:
    enum Level {
        INFO,
        WARNING,
        ERROR,
    };

    DebugLogger(std::string file_name);
    ~DebugLogger();

    void Log(const std::string& message, DebugLogger::Level level);

   private:
    std::ofstream logFile;
    std::string Level2string(Level level);
};

namespace Debug {

void initLog(std::string file_name = DEFAULT_LOG_FILE);

void Log(const std::string& message,
         DebugLogger::Level level = DebugLogger::Level::INFO);

void closeLog();
}  // namespace Debug