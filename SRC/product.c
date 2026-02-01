#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "product.h"
#include "json.h"
#include "colors.h"

void show_list(Product *products, int n) {
    if (n == 0) {
        printf(RED "No products available.\n" RESET);
        return;
    }
    printf(BOLD CYAN "\n%-5s %-20s %-10s\n" RESET, "No.", "Name", "Price");
    printf(CYAN "-------------------------------------\n" RESET);
    for (int i = 0; i < n; i++) {
        printf("%-5d %-20s $%-9.2f\n", i + 1, products[i].name, products[i].price);
    }
}

void add_list(Product **products_ptr, int *n_ptr) {
    int n;
    printf("How many products to add? ");
    scanf("%d", &n);
    getchar();

    Product *new_list = realloc(*products_ptr, sizeof(Product) * (*n_ptr + n));
    if (!new_list) {
        printf(RED "Memory allocation failed!\n" RESET);
        return;
    }

    *products_ptr = new_list;
    for (int i = 0; i < n; i++) {
        printf("\nProduct %d name: ", *n_ptr + i + 1);
        fgets((*products_ptr)[*n_ptr + i].name, sizeof((*products_ptr)[*n_ptr + i].name), stdin);
        (*products_ptr)[*n_ptr + i].name[strcspn((*products_ptr)[*n_ptr + i].name, "\n")] = 0;

        printf("Price: ");
        scanf("%f", &(*products_ptr)[*n_ptr + i].price);
        getchar();
    }

    *n_ptr += n;

    saveProductsToJSON(*products_ptr, *n_ptr, "products.json");
    printf(GREEN "%d product(s) added successfully!\n" RESET, n);
}

void delete_list(Product *products, int *n_ptr) {
    if (*n_ptr == 0) { printf(RED "No products to delete.\n" RESET); return; }
    int index;
    show_list(products, *n_ptr);
    printf("Enter product number to delete: ");
    scanf("%d", &index);
    getchar();
    if (index < 1 || index > *n_ptr) { printf(RED "Invalid number.\n" RESET); return; }
    for (int i = index - 1; i < *n_ptr - 1; i++) {
        products[i] = products[i + 1];
    }
    (*n_ptr)--;
    saveProductsToJSON(products, *n_ptr, "products.json");
    printf(GREEN "Product deleted successfully!\n" RESET);
}

void modify_list(Product *products, int n) {
    if (n == 0) { printf(RED "No products to modify.\n" RESET); return; }
    int index;
    show_list(products, n);
    printf("Enter product number to modify: ");
    scanf("%d", &index);
    getchar();
    if (index < 1 || index > n) { printf(RED "Invalid number.\n" RESET); return; }

    printf("New name: ");
    fgets(products[index - 1].name, sizeof(products[index - 1].name), stdin);
    products[index - 1].name[strcspn(products[index - 1].name, "\n")] = 0;

    printf("New price: ");
    scanf("%f", &products[index - 1].price);
    getchar();

    saveProductsToJSON(products, n, "products.json");
    printf(GREEN "Product modified successfully!\n" RESET);
}
