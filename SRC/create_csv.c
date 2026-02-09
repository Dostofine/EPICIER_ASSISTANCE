#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "create_csv.h"
#include "menu.h"
// Simple JSON to CSV converter for datetime and prices array
int createcsv() {
    FILE *jsonFile, *csvFile;
    char line[1024];
    char json_file[256];
    char filepath[500];
    char datetime[100] = "";
    char csvname[500];
    int firstPrice = 1;
    
    printf("Enter JSON filename: ");
    scanf("%s", json_file);
    
    // Open JSON file for reading
    snprintf(filepath, sizeof(filepath), "data/json_files/%s", json_file);
    jsonFile = fopen(filepath, "r");
    if (jsonFile == NULL) {
        printf("Error opening JSON file\n");
        return 1;
    }
    
    // Open CSV file for writing
    // Build CSV name from json_file 
    snprintf(csvname, sizeof(csvname), "data/csv_files/%s", json_file);
    // Replace .json with .csv
    char *dot = strrchr(csvname, '.');
    if (dot != NULL) {
        strcpy(dot, ".csv");
    }
    csvFile = fopen(csvname, "w");
    
    // Write CSV header
    fprintf(csvFile, "datetime,price\n");
    
    // Read JSON file line by line
    while (fgets(line, sizeof(line), jsonFile)) {
        // Extract datetime
        if (strstr(line, "datetime")) {
            char *start = strchr(line, '"');
            if (start) {
                start = strchr(start + 1, '"'); // Skip "datetime"
                if (start) {
                    start = strchr(start + 1, '"'); // Find value start
                    if (start) {
                        start++; // Move past opening quote
                        char *end = strchr(start, '"');
                        if (end) {
                            int len = end - start;
                            strncpy(datetime, start, len);
                            datetime[len] = '\0';
                        }
                    }
                }
            }
        }
        
        // Extract prices array
        if (strstr(line, "prices")) {
            char *start = strchr(line, '[');
            if (start) {
                start++; // Move past '['
                char *end = strchr(start, ']');
                if (end) {
                    *end = '\0'; // Terminate at ']'
                    
                    // Parse each price
                    char *token = strtok(start, ",");
                    while (token != NULL) {
                        double price = atof(token);
                        
                        if (firstPrice) {
                            fprintf(csvFile, "%s,%.2f\n", datetime, price);
                            firstPrice = 0;
                        } else {
                            fprintf(csvFile, ",%.2f\n", price);
                        }
                        
                        token = strtok(NULL, ",");
                    }
                }
            }
        }
    }
    
    fclose(jsonFile);
    fclose(csvFile);
    
    printf("CSV file created successfully!\n");
    menu();
    return 0;
}