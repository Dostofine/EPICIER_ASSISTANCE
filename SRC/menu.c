#include <stdio.h>
#include "colors.h"
#include <stdlib.h>
#include <ctype.h>
#include "new_day.h"
#include "menu.h"
#include "list.h"
#include "clear.h"
int menu(){
    char user_choice;
    printf(BLUE
        "──────────────────────────────────────────────────────────"
        "                                                          "
        "[ COMMANDES DISPONIBLES ]"
        "                                                          "
        "(L)  ACCÉDER À LA LISTE DES PRODUITS"
        "    Consulter l'inventaire complet, les prix et stocks."
        "                                                          "
        "(N)  CRÉER LE TABLEAU DES VENTES DU JOUR"
        "    Initialiser une nouvelle feuille de calcul pour aujourd'hui."
        "                                                          "
        "(E) GÉNÉRER LES FICHIERS .CSV"
        "    Extraire les données vers le dossier 'export'."
        "                                                          "
        "──────────────────────────────────────────────────────────" RESET
        GREEN "   tapez une lettre ou une commande ci-dessous :\n" RESET
    );
    scanf(" %c",&user_choice);
    if(toupper(user_choice)=='L')
    {
        clear_cmd();
        create_and_print_the_list();
    }
    else if(toupper(user_choice)=='N')
    {
        clear_cmd();
        hello();
        float PRICES[1000];
        inter_new_day(PRICES);
    }
    else if (toupper(user_choice)=='E')
    {
        clear_cmd();
        printf("good");
    }
    else if (toupper(user_choice)=='Q'){
        clear_cmd();
        exit(0);
    }
    return 0;
}