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
        "──────────────────────────────────────────────────────────\n"
        "\n            [ COMMANDES DISPONIBLES ]\n"
        "                                                          "
        "\n(L)  VOIR LE TABLEAU DES PRIX VOUS GAGNER À UNE JOUR.\n"
        "                                                          "
        "\n(N)  CRÉER LE TABLEAU DES VENTES DU JOUR\n"
        "    Initialiser une nouvelle feuille de calcul pour aujourd'hui.\n"
        "                                                          "
        "\n(E) GÉNÉRER LES FICHIERS .CSV\n"
        "    Extraire les données vers le dossier 'export'.\n"
        "                                                          "
        "\n(Q)  QUITTER\n"
        "    Sortir du programme.\n"
        "\n──────────────────────────────────────────────────────────\n" RESET
        GREEN ">tapez une lettre ou une commande ci-dessous : " RESET
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