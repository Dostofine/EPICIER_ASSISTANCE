#include <stdio.h>
#include <stdlib.h>
#include "colors.h"
#include <time.h>
#include "new_day.h"
#include <sys/types.h> 
#include <errno.h>
#include "menu.h"
#include "clear.h"
int hello()
{
    time_t now;
    time(&now);
    printf(BLUE "============== %s =================\n" RESET,ctime(&now));
    printf(RED "==============WELCOME!===============\n" RESET);
    printf(GREEN "hello in today list i hope you good luck \n" RESET);
    printf(GREEN "inter the prices and 0 to stop.\n" RESET);
    return 0;
}
int inter_new_day(float PRICES[1000])
{
    //take the prices to the day
    int size;
    size=0;
    for(int i=0;i<1000;i++){
        printf("enter the price %d : ",i+1);
        scanf("%f",&PRICES[i]);
        if(PRICES[i]==0){
            break;
        }
        size=i+1;
    }
    // Create the json file with timestamp in filename
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    // Create filename: data_YYYY-MM-DD_HH-MM-SS.json
    char filename[500];
    snprintf(filename, sizeof(filename), 
            "data/data_%04d-%02d-%02d_%02d-%02d-%02d.json",
            t->tm_year + 1900, t->tm_mon + 1, t->tm_mday,
            t->tm_hour, t->tm_min, t->tm_sec);

    FILE *f = fopen(filename, "w");
    if (f == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Get datetime string for JSON content
    char datetime_str[64];
    strftime(datetime_str, sizeof(datetime_str), "%Y-%m-%d %H:%M:%S", t);

    fprintf(f, "{\n");  
    fprintf(f, "  \"datetime\": \"%s\",\n", datetime_str);
    fprintf(f, "  \"prices\": [");
    for (int i = 0; i < size; i++) {
        fprintf(f, "%f", PRICES[i]);
        if (i != size - 1) fprintf(f, ",");
    }
    fprintf(f, "]\n");
    fprintf(f, "}\n");
    fclose(f);

    printf("File created: %s\n", filename);
    clear_cmd();
    menu();
    return 0;
}