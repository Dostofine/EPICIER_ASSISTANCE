#include <stdio.h>
#include "colors.h"
#include <ctype.h>
char user_choice;
int menu(){
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
    scanf("% c",&user_choice);
    if(toupper(user_choice)=='E')
    {
        list();
    }
    else if(toupper(user_choice)=='N')
    {
        new_day();
    }
    else if (toupper(user_choice)=='E')
    {
       csv_GÉNÉRER();
    }
    return 0;
}