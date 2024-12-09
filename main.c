#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "taquin.h"


void afficherMenuPrincipal() {
    printf("\n");
    printf("=====================================\n");
    printf("    PROJET C 2 : TAQUIN\n");
    printf("=====================================\n\n");
    printf("1. Commencer une partie\n");
    printf("2. Charger une partie\n");
    printf("3. Historique des Joueurs \n");
    printf("4. Quitter\n\n");
    printf("Choisissez une option : ");
}
void affichierNiveau(){
    printf("\n");
    printf("=================\n");
    printf(" CHOISIR LE NIVEAU :\n");
    printf("1. Facile \n");
    printf("2. Moyen \n");
    printf("3. Difficile \n");
    printf("=================\n");
    printf("Choisissez un niveau : ");
}
void affichierCharger(){
    printf("\n");
    printf("=================\n");
    printf("CHOISIR LE NIVEAU A CHARGER\n");
    printf("1. Facile\n");
    printf("2. Moyen \n");
    printf("3. Difficile \n");
    printf("=================\n");
    printf("Choisissez un niveau : ");
}
void afficherHistorique() {
    printf("Historique des mouvements : ");
    for (int i = 0; i < compteurMouvements; i++) {
        printf("%c ", historiqueMouvements[i]);
    }
    printf("\n");
}


int grillePrecedente [TAILLE_MOYENNE][TAILLE_MOYENNE] ;
int grillePrecedente_facile[TAILLE_FACILE][TAILLE_FACILE];
int grillePrecedente_difficile [TAILLE_DIFFICILE][TAILLE_DIFFICILE];

time_t startTime;
double elapsedTime = 0.0;

int main() {

    srand(time(NULL));
    // Initialiser le générateur de nombres aléatoires
    startTime = time(NULL);

//    initialiserHistorique();

    int grilleFacile[TAILLE_FACILE][TAILLE_FACILE];
    int grilleMoyen[TAILLE_MOYENNE][TAILLE_MOYENNE];
    int grilleDifficile[TAILLE_DIFFICILE][TAILLE_DIFFICILE];

    char choixMenu;
    char choixNiveau;
    char choixCharger;
    char namePlayer;
    char touche;

    while (1){
        elapsedTime = difftime(time(NULL), startTime);
        printf("Temps de jeu : %.0f secondes\n", elapsedTime);
        afficherMenuPrincipal();
        scanf(" %c", &choixMenu);
        switch (choixMenu) {
            case '1':
                affichierNiveau();
                scanf(" %c", &choixNiveau);
                switch (choixNiveau) {
                    case '1':
                        initialGrille_facile(grilleFacile);
                        random_facile(grilleFacile);
                        affichage_Grille_facile(grilleFacile);
                        break;
                    case '2':
                        initialGrille(grilleMoyen);
                        random(grilleMoyen);
                        affichage_Grille(grilleMoyen);
                        break;
                    case '3':
                        initialGrille_difficile(grilleDifficile);
                        random_difficile(grilleDifficile);
                        affichage_Grille_difficile(grilleDifficile);
                        break;
                    default:
                        if(choixMenu < '1' || choixMenu > '4') {
                            printf("Option de niveau invalide.");
                            continue;
                        }
                }
                break;
            case '2':
                // Assurez-vous que cette fonction existe
                affichierCharger();
                scanf(" %c", &choixCharger);
                switch (choixCharger) {
                    case '1':
                        chargerPartie_facile(grilleFacile);
                        affichage_Grille_facile(grilleFacile);
                        break;
                    case '2':
                        chargerPartie_moyen(grilleMoyen);
                        affichage_Grille(grilleMoyen);
                        break;
                    case '3':
                        chargerPartie_difficile(grilleDifficile);
                        affichage_Grille_difficile(grilleDifficile);
                        break;
                    default:
                        printf("Niveau invalide pour le chargement.\n");
                        continue;
                }
                break;
            case '3':
                printf("Voici votre hisoirque de joueurs:  .\n");
                scanf("%c", &namePlayer);
                continue;
            case '4':
                printf("Vous avez quitté le jeu .\n");
                return 0;
            default:
                printf("Option invalide. Veuillez réessayer\n");
                continue;
        }
        while (1){
            if(victoir(grilleMoyen)){
                printf("       GAME OVER. \n");

                break;
            }
            if(victoir_facile(grilleFacile)){
                printf("       GAME OVER. \n");
                break;
            }
            if (victoir_difficile(grilleDifficile)){
                printf("       GAME OVER.. \n");

                break;
            }
            printf("==============================================================================================\n");
            printf("Entrez un mouvement (H=Haut, B=Bas, G=Gauche, D=Droite, R=Revenir en arriere, I=Historique, S=Sauvegarder, C=Charger, Q=Quitter) : ");
            scanf(" %c", &touche); // Lire un caractère d'entrée

            // Vérifier si l'utilisateur souhaite quitter le jeu
            if (touche == 'Q'|| touche == 'q') {
                printf("Vous avez quitté le jeu.\n");
                break; // Sortir de la boucle si l'utilisateur quitte
            }
            // Sauvegarder la partie
            if (touche == 'S') {
                switch (choixNiveau) {
                    case '1':
                        sauvegarderPartie_facile(grilleFacile);
                        break;
                    case '2':
                        sauvegarderPartie_moyen(grilleMoyen);
                        break;
                    case '3':
                        sauvegarderPartie_difficile(grilleDifficile);
                        break;
                    default:
                        printf("Niveau invalide pour la sauvegarde.\n");
                        break;
                }
                continue;
            }
            // Charger une partie
            if (touche == 'C') {
                switch (choixNiveau) {
                    case '1':
                        chargerPartie_facile(grilleFacile);
                        affichage_Grille_facile(grilleFacile);
                        continue;
                    case '2':
                        chargerPartie_moyen(grilleMoyen);
                        affichage_Grille(grilleMoyen);
                        continue;
                    case '3':
                        chargerPartie_difficile(grilleDifficile);
                        affichage_Grille_difficile(grilleDifficile);
                        continue;
                    default:
                        printf("Niveau invalide pour le chargement.\n");
                        break;
                }
                continue;

            }
            if(touche == 'R'){
                switch (choixNiveau) {
                    case '1':
                        revenirEnArriere_facile(grilleFacile,TAILLE_FACILE);
                        sauvegarderPrecedent_facile(grilleFacile,TAILLE_FACILE);
                        affichage_Grille_facile(grilleFacile);
                        continue;
                    case '2':
                        revenirEnArriere(grilleMoyen, TAILLE_MOYENNE);
                        sauvegarderPrecedent(grilleMoyen,TAILLE_MOYENNE);
                        affichage_Grille(grilleMoyen);
                        continue;
                    case'3':
                        revenirEnArriere_difficile(grilleDifficile,TAILLE_DIFFICILE);
                        sauvegarderPrecedent_difficile(grilleDifficile,TAILLE_DIFFICILE);
                        affichage_Grille_difficile(grilleDifficile);
                        continue;
                    default:
                        printf("Niveau invalide pour le chargement.\n");
                        break;
                }

            }
            if(touche == 'I'){
                afficherHistorique();
            }

            // Déplacer la case selon l'entrée de l'utilisateur

            switch (choixNiveau) {
                case '1':
                    deplacerCase_facile(grilleFacile, touche);
                    affichage_Grille_facile(grilleFacile);
                    break;
                case '2':
                    deplacerCase(grilleMoyen, touche);
                    affichage_Grille(grilleMoyen);
                    break;
                case '3':
                    deplacerCase_difficile(grilleDifficile, touche);
                    affichage_Grille_difficile(grilleDifficile);
                    break;
            }
        }
    }

    return 0; // Fin du programme
}
