#ifndef KEYBOARD_LOGGER_H
#define KEYBOARD_LOGGER_H

#include <string>
#include <unordered_map>
#include <WinUser.h>

class KeyboardLogger {
public:
    KeyboardLogger(const std::string& logFileName);
    void startLogging();
    void stopLogging();

private:
    std::string logFileName_;
    std::ofstream logFile_;
    bool isLogging_ = false;
    std::unordered_map<int, std::string> specialKeys_ = {
        {VK_BACK, "[BACKSPACE]"},
        {VK_TAB, "[TAB]"},
        {VK_RETURN, "[ENTER]"},
        {VK_SHIFT, "[SHIFT]"},
        {VK_CONTROL, "[CTRL]"},
        {VK_MENU, "[ALT]"},
        {VK_CAPITAL, "[CAPSLOCK]"},
        {VK_ESCAPE, "[ESC]"},
        {VK_SPACE, " "},
        {VK_PRIOR, "[PAGE UP]"},
        {VK_NEXT, "[PAGE DOWN]"},
        {VK_END, "[END]"},
        {VK_HOME, "[HOME]"},
        {VK_LEFT, "[LEFT]"},
        {VK_UP, "[UP]"},
        {VK_RIGHT, "[RIGHT]"},
        {VK_DOWN, "[DOWN]"},
        {VK_INSERT, "[INS]"},
        {VK_DELETE, "[DEL]"}
    };
};

#endif
