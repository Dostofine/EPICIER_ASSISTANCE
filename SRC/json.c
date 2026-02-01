#include <stdio.h>
#include <stdlib.h>
#include <cJSON.h>
#include "json.h"

void saveProductsToJSON(Product *products, int n, const char *filename) {
    cJSON *jsonArray = cJSON_CreateArray();

    for (int i = 0; i < n; i++) {
        cJSON *product = cJSON_CreateObject();
        cJSON_AddStringToObject(product, "name", products[i].name);
        cJSON_AddNumberToObject(product, "price", products[i].price);
        cJSON_AddItemToArray(jsonArray, product);
    }

    char *jsonString = cJSON_Print(jsonArray);

    FILE *f = fopen(filename, "w");
    if (f) {
        fprintf(f, "%s", jsonString);
        fclose(f);
    }

    cJSON_Delete(jsonArray);
    free(jsonString);
}

int loadProductsFromJSON(Product **products_ptr, int *n_ptr, const char *filename) {
    FILE *f = fopen(filename, "r");
    if (!f) return 0;

    fseek(f, 0, SEEK_END);
    long len = ftell(f);
    fseek(f, 0, SEEK_SET);

    char *data = malloc(len + 1);
    fread(data, 1, len, f);
    data[len] = '\0';
    fclose(f);

    cJSON *jsonArray = cJSON_Parse(data);
    free(data);
    if (!jsonArray) return 0;

    int n = cJSON_GetArraySize(jsonArray);
    Product *list = malloc(sizeof(Product) * n);
    for (int i = 0; i < n; i++) {
        cJSON *item = cJSON_GetArrayItem(jsonArray, i);
        snprintf(list[i].name, sizeof(list[i].name), "%s",
                 cJSON_GetObjectItem(item, "name")->valuestring);
        list[i].price = (float)cJSON_GetObjectItem(item, "price")->valuedouble;
    }

    *products_ptr = list;
    *n_ptr = n;

    cJSON_Delete(jsonArray);
    return n;
}