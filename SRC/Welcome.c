#include <stdio.h>
#include <string.h>
#include "colors.h"
#include "welcome.h"
int say_hi(){
    printf(GREEN BOLD "                 =================================\n" RESET);
    printf(GREEN BOLD "                |" RESET);
    printf(RED "     Welcome to My Program      " RESET);
    printf(GREEN BOLD "|\n" RESET);
    printf(GREEN BOLD "                 =================================\n" RESET);
    return 0;
}
int epicier_assistance_v(){
    printf(GREEN BOLD "============================================================\n"
  "     ______ _____ _____ _____ _____ ______ _____  \n"
 "     |  ____|  __ |_   _/ ____|_   _|  ____|  __ | \n"
 "     | |__  | |__) || || |      | | | |__  | |__) |\n"
 "     |  __| |  ___/ | || |      | | |  __| |  _  / \n"
 "     | |____| |    _| || |____ _| |_| |____| | | | \n"
 "     |______|_|   |_____|_____|_____|______|_|  |_| \n"
"\n              ASSISTANCE v1.0.0              \n"
"============================================================\n"RESET);
    return 0;
}