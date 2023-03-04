#pragma once
#ifndef KEYBOARD_LOGGER_H
#define KEYBOARD_LOGGER_H

#include <string>

class KeyboardLogger {
public:
    KeyboardLogger(const std::string& logFileName);
    void startLogging();
    void stopLogging();

private:
    std::string logFileName_;
    std::ofstream logFile_;
    bool isLogging_ = false;
};

#endif
