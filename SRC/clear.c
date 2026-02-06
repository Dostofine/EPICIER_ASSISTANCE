#include <stdlib.h>
#include "clear.h"
int clear_cmd() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    return 0;
}