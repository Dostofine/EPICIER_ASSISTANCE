#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "menu.h"
int create_and_print_the_list() {
    char json_file[256];
    
    printf("Enter JSON filename: ");
    scanf("%s", json_file);
    
    char command[1024];  // Increase buffer size
    snprintf(command, sizeof(command), "jq '.' data/json_files/%s > data/txt_files/table_%s.txt", json_file, json_file);   
    system(command);
    
    printf("Table created!\n");
    //print it
    sprintf(command, "jq '.' data/json_files/%s", json_file);
    system(command);
    menu();
    return 0;
}