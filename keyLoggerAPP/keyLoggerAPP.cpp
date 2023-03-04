#include "KeyboardLogger.h"
#include <synchapi.h>

int main() {
    KeyboardLogger logger("log.txt");
    logger.startLogging();

    // Wait for some time while the logger is running
    Sleep(5000);

    logger.stopLogging();
    return 0;
}
