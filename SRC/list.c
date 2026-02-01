#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "colors.h"
#include "product.h"
#include "json.h"

int list() {
    Product *products = NULL;
    int n_products = 0;

    loadProductsFromJSON(&products, &n_products, "products.json");

    char choice;
    do {
        printf(BOLD "\n────────── [ MENU ] ──────────\n" RESET);
        printf("(E) Show products\n");
        printf("(A) Add product\n");
        printf("(D) Delete product\n");
        printf("(M) Modify product\n");
        printf("(Q) Quit\n");
        printf("Choice: ");
        scanf(" %c", &choice);
        getchar();

        switch(toupper(choice)) {
            case 'E': show_list(products, n_products); break;
            case 'A': add_list(&products, &n_products); break;
            case 'D': delete_list(products, &n_products); break;
            case 'M': modify_list(products, n_products); break;
            case 'Q': printf("Exiting...\n"); break;
            default: printf(RED "Invalid choice.\n" RESET);
        }
    } while(toupper(choice) != 'Q');

    free(products);
    return 0;
}
