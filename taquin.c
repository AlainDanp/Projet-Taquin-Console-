#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "taquin.h"

typedef  struct {
    char direction;
    double time;
} Mouvement;

char historiqueMouvements[MAX_HISTORIQUE];
int compteurMouvements = 0;

void ajouterMouvement(char direction);

void affichage_Grille(int grille[4][4]) {
    printf("Grille actuelle normal :\n");
    printf("==============================================================================================\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {  // Ligne supérieure de bordure
            printf("+------");
        }
        printf("+\n");
        // Affichage des nombres (ou espace pour la case vide)
        for (int j = 0; j < 4; j++) {
            if (grille[i][j] == 0) {
                printf("|   X  "); // Case vide
            } else {
                printf("|  %2d  ", grille[i][j]); // Affiche le chiffre centré
            }
        }
        printf("|\n");
    }
    for (int j = 0; j < 4; j++) { // Ligne inférieure de bordure pour la dernière rangée
        printf("+------");
    }
    printf("+\n");
}

void affichage_Grille_facile(int grille[3][3]) {
    printf("Grille actuelle facile :\n");
    printf("==============================================================================================\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {  // Ligne supérieure de bordure
            printf("+------");
        }
        printf("+\n");

        // Affichage des nombres (ou espace pour la case vide)
        for (int j = 0; j < 3; j++) {
            if (grille[i][j] == 0) {
                printf("|   X  "); // Case vide
            } else {
                printf("|  %2d  ", grille[i][j]); // Affiche le chiffre centré
            }
        }
        printf("|\n");
    }
    for (int j = 0; j < 3; j++) { // Ligne inférieure de bordure pour la dernière rangée
        printf("+------");
    }
    printf("+\n");
}

void affichage_Grille_difficile(int grille[9][9]) {
    printf("Grille actuelle difficile :\n");
    printf("==============================================================================================\n");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {  // Ligne supérieure de bordure
            printf("+------");
        }
        printf("+\n");

        // Affichage des nombres (ou espace pour la case vide)
        for (int j = 0; j < 9; j++) {
            if (grille[i][j] == 0) {
                printf("|   X  "); // Case vide
            } else {
                printf("|  %2d  ", grille[i][j]); // Affiche le chiffre centré
            }
        }
        printf("|\n");
    }
    for (int j = 0; j < 9; j++) { // Ligne inférieure de bordure pour la dernière rangée
        printf("+------");
    }
    printf("+\n");
}
void initialGrille(int grille[4][4]) {
    int numéro = 1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (numéro < 16) {
                grille[i][j] = numéro++;
            } else {
                grille[i][j] = 0;  // case vide
            }
        }
    }
}
void initialGrille_facile(int grille[3][3]){
    int numéro = 1;
    for (int i = 0; i <3 ; i++){
        for (int j = 0; j < 3; ++j) {
            if(numéro < 9){
                grille[i][j] = numéro++;
            } else{
                grille[i][j] = 0;
            }
        }
    }
}
void initialGrille_difficile(int grille[9][9]){
    int numéro = 1;
    for (int i = 0; i <9 ; i++){
        for (int j = 0; j < 9; ++j) {
            if(numéro < 81){
                grille[i][j] = numéro++;
            } else{
                grille[i][j] = 0;
            }
        }
    }
}

int victoir(int grille[4][4]) {
    int numero = 1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == 4 - 1 && j == 4 - 1) {
                return (grille[i][j] == 0) ? 1 : 0;
            }
            if (grille[i][j] != numero++) {
                return 0;  // le puzzle n'est pas résolu
            }
        }
    }
    return 1; // le puzzle est résolu
}
int victoir_facile(int grille[3][3]) {
    int numero = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 3 - 1 && j == 3 - 1) {
                return (grille[i][j] == 0) ? 1 : 0;
            }
            if (grille[i][j] != numero++) {
                return 0;  // le puzzle n'est pas résolu
            }
        }
    }
    return 1; // le puzzle est résolu
}
int victoir_difficile(int grille[9][9]) {
    int numero = 1;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (i == 9 - 1 && j == 9 - 1) {
                return (grille[i][j] == 0) ? 1 : 0;
            }
            if (grille[i][j] != numero++) {
                return 0;  // le puzzle n'est pas résolu
            }
        }
    }
    return 1; // le puzzle est résolu
}

void random(int grille[4][4]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (grille[i][j] == 0) {
                break;
            }
        }
        if (j < 3) {
            break;
        }
    }
    for (int k = 0; k < 100; k++) {
        int direction = rand() % 3; // 0=Haut, 1=Bas, 2=Gauche, 3=Droite

        switch (direction) {
            case 0: // Haut
                if (i > 0) {
                    grille[i][j] = grille[i - 1][j];
                    grille[i - 1][j] = 0;
                    i--;
                }
                break;

            case 1: // Bas
                if (i < 3 - 1) {
                    grille[i][j] = grille[i + 1][j];
                    grille[i + 1][j] = 0;
                    i++;
                }
                break;

            case 2: // Gauche
                if (j > 0) {
                    grille[i][j] = grille[i][j - 1];
                    grille[i][j - 1] = 0;
                    j--;
                }
                break;

            case 3: // Droite
                if (j < 3 - 1) {
                    grille[i][j] = grille[i][j + 1];
                    grille[i][j + 1] = 0;
                    j++;
                }
                break;
        }
    }
}
// niveau 2

void random_facile(int grille[3][3]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (grille[i][j] == 0) {
                break;
            }
        }
        if (j < 3) {
            break;
        }
    }
    for (int k = 0; k < 100; k++) {
        int direction = rand() % 3; // 0=Haut, 1=Bas, 2=Gauche, 3=Droite

        switch (direction) {
            case 0: // Haut
                if (i > 0) {
                    grille[i][j] = grille[i - 1][j];
                    grille[i - 1][j] = 0;
                    i--;
                }
                break;

            case 1: // Bas
                if (i < 3 - 1) {
                    grille[i][j] = grille[i + 1][j];
                    grille[i + 1][j] = 0;
                    i++;
                }
                break;

            case 2: // Gauche
                if (j > 0) {
                    grille[i][j] = grille[i][j - 1];
                    grille[i][j - 1] = 0;
                    j--;
                }
                break;

            case 3: // Droite
                if (j < 3 - 1) {
                    grille[i][j] = grille[i][j + 1];
                    grille[i][j + 1] = 0;
                    j++;
                }
                break;
        }
    }
}
void random_difficile(int grille[9][9]) {
    int i, j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (grille[i][j] == 0) {
                break;
            }
        }
        if (j < 9) {
            break;
        }
    }
    for (int k = 0; k < 400; k++) {
        int direction = rand() % 9; // 0=Haut, 1=Bas, 2=Gauche, 3=Droite

        switch (direction) {
            case 0: // Haut
                if (i > 0) {
                    grille[i][j] = grille[i - 1][j];
                    grille[i - 1][j] = 0;
                    i--;
                }
                break;

            case 1: // Bas
                if (i < 9 - 1) {
                    grille[i][j] = grille[i + 1][j];
                    grille[i + 1][j] = 0;
                    i++;
                }
                break;

            case 2: // Gauche
                if (j > 0) {
                    grille[i][j] = grille[i][j - 1];
                    grille[i][j - 1] = 0;
                    j--;
                }
                break;

            case 3: // Droite
                if (j < 9 - 1) {
                    grille[i][j] = grille[i][j + 1];
                    grille[i][j + 1] = 0;
                    j++;
                }
                break;
        }
    }
}
// Fonction pour déplacer une case
//niveau 1

void deplacerCase(int grille[4][4], char direction) {

    int i, j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (grille[i][j] == 0) {
                break;
            }
        }
        if (j < 4) {
            break;
        }
    }
    switch (direction) {
        case 'H':
        case 'h':
            if (i > 0){ // Haut
                grille[i][j] = grille[i - 1][j];
                grille[i - 1][j] = 0;
            } else{
                printf("Deplacement  impossible \n ");
            }
            break;
        case 'B':
        case 'b':
            if(i < 3){ // Bas
                grille[i][j] = grille[i + 1][j];
                grille[i + 1][j] = 0;
            } else {
                printf("Deplacement  Impossible \n");
            }
            break;
        case 'G':
        case 'g':
            if (j > 0){ //Gauche
                grille[i][j] = grille[i][j - 1];
                grille[i][j - 1 ] = 0;
            } else{
                printf("Deplacement impossible \n");
            }
            break;
        case 'D':
        case 'd':
            if (j < 3){
                grille[i][j] = grille[i][j + 1];
                grille[i][j + 1 ] = 0;
            } else{
                printf("Deplacement  impossible \n");
            }
            break;
        case 'I':
            printf("OK\n1"
                   "");
            break;
        default:
            printf("Direction non valide. Utilisez H ou h, B ou b, D ou d, G ou g ");
    }
    ajouterMouvement(direction);
}
// déplacer 2
void deplacerCase_facile(int grille[3][3], char direction) {
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (grille[i][j] == 0) {
                break;
            }
        }
        if (j < 3) {
            break;
        }
    }
    switch (direction) {
        case 'H':
        case 'h':
            if (i > 0){ // Haut
                grille[i][j] = grille[i - 1][j];
                grille[i - 1][j] = 0;
            } else{
                printf("Deplacement  impossible \n ");
            }
            break;
        case 'B':
        case 'b':
            if(i < 2){ // Bas
                grille[i][j] = grille[i + 1][j];
                grille[i + 1][j] = 0;
            } else {
                printf("Deplacement  Impossible \n");
            }
            break;
        case 'G':
        case 'g':
            if (j > 0){ //Gauche
                grille[i][j] = grille[i][j - 1];
                grille[i][j - 1 ] = 0;
            } else{
                printf("Deplacement impossible \n");
            }
            break;
        case 'D':
        case 'd':
            if (j < 2){
                grille[i][j] = grille[i][j + 1];
                grille[i][j + 1 ] = 0;
            } else{
                printf("Deplacement  impossible \n");
            }
            break;
        case 'I':
            printf("OK\n");
            break;
        default:
            printf("Direction non valide. Utilisez H ou h, B ou b, D ou d, G ou g ");
    }
    ajouterMouvement(direction);
}

void deplacerCase_difficile(int grille[9][9], char direction) {
    int i, j;

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (grille[i][j] == 0) {
                break;
            }
        }
        if (j < 9) {
            break;
        }
    }
    switch (direction) {
        case 'H':
        case 'h':
            if (i > 0){ // Haut
                grille[i][j] = grille[i - 1][j];
                grille[i - 1][j] = 0;
            } else{
                printf("Deplacement  impossible \n ");
            }
            break;
        case 'B':
        case 'b':
            if(i < 8){ // Bas
                grille[i][j] = grille[i + 1][j];
                grille[i + 1][j] = 0;
            } else {
                printf("Deplacement  Impossible \n");
            }
            break;
        case 'G':
        case 'g':
            if (j > 0){ //Gauche
                grille[i][j] = grille[i][j - 1];
                grille[i][j - 1 ] = 0;
            } else{
                printf("Deplacement impossible \n");
            }
            break;
        case 'D':
        case 'd':
            if (j < 8){
                grille[i][j] = grille[i][j + 1];
                grille[i][j + 1 ] = 0;
            } else{
                printf("Deplacement  impossible \n");
            }
            break;
        case 'I':
            printf("OK\n");
            break;
        default:
            printf("Direction non valide. Utilisez H ou h, B ou b, D ou d, G ou g ");
    }
    ajouterMouvement(direction);

}

void ajouterMouvement(char mouvement) {
    if (mouvement == 'H' || mouvement == 'B' || mouvement == 'G' || mouvement == 'D' || mouvement == 'h' || mouvement == 'b' || mouvement == 'g' || mouvement == 'd' ) { // Vérifier si la touche est une touche de déplacement valide
        if (compteurMouvements < MAX_HISTORIQUE) {
            historiqueMouvements[compteurMouvements] = mouvement;
            compteurMouvements++;
        }
    }
}


void sauvegarderPartie_moyen(int grille[TAILLE_MOYENNE][TAILLE_MOYENNE]) {
    FILE *file = fopen("sauvegarde_moyen.txt", "w");
    if (file == NULL) {
        printf("Erreur lors de la sauvegarde.\n");
        return;
    }
    for (int i = 0; i < TAILLE_MOYENNE; i++) {
        for (int j = 0; j < TAILLE_MOYENNE; j++) {
            fprintf(file, "%d ", grille[i][j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
    printf("Partie sauvegardée avec succès (moyen).\n");
}

void sauvegarderPartie_facile(int grille[TAILLE_FACILE][TAILLE_FACILE]) {
    FILE *file = fopen("sauvegarde_facile.txt", "w");
    if (file == NULL) {
        printf("Erreur lors de la sauvegarde.\n");
        return;
    }
    for (int i = 0; i < TAILLE_FACILE; i++) {
        for (int j = 0; j < TAILLE_FACILE; j++) {
            fprintf(file, "%d ", grille[i][j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
    printf("Partie sauvegardée avec succès (facile).\n");
}
void sauvegarderPartie_difficile(int grille[TAILLE_DIFFICILE][TAILLE_DIFFICILE]) {
    FILE *file = fopen("sauvegarde_difficile.txt", "w");
    if (file == NULL) {
        printf("Erreur lors de la sauvegarde.\n");
        return;
    }
    for (int i = 0; i < TAILLE_DIFFICILE; i++) {
        for (int j = 0; j < TAILLE_DIFFICILE; j++) {
            fprintf(file, "%d ", grille[i][j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
    printf("Partie sauvegardée avec succès (difficile).\n");
}

void chargerPartie_difficile(int grille[TAILLE_DIFFICILE][TAILLE_DIFFICILE]) {
    FILE *file = fopen("sauvegarde_difficile.txt", "r");
    if (file == NULL) {
        printf("Erreur lors du chargement.\n");
        return;
    }
    for (int i = 0; i < TAILLE_DIFFICILE; i++) {
        for (int j = 0; j < TAILLE_DIFFICILE; j++) {
            fscanf(file, "%d", &grille[i][j]);
        }
    }
    fclose(file);
    printf("Partie chargée avec succès (difficile).\n");
}
void chargerPartie_moyen(int grille[TAILLE_MOYENNE][TAILLE_MOYENNE]) {
    FILE *file = fopen("sauvegarde_moyen.txt", "r");
    if (file == NULL) {
        printf("Erreur lors du chargement.\n");
        return;
    }
    for (int i = 0; i < TAILLE_MOYENNE; i++) {
        for (int j = 0; j < TAILLE_MOYENNE; j++) {
            fscanf(file, "%d", &grille[i][j]);
        }
    }
    fclose(file);
    printf("Partie chargée avec succès (moyen).\n");
}

void chargerPartie_facile(int grille[TAILLE_FACILE][TAILLE_FACILE]) {
    FILE *file = fopen("sauvegarde_facile.txt", "r");
    if (file == NULL) {
        printf("Erreur lors du chargement.\n");
        return;
    }
    for (int i = 0; i < TAILLE_FACILE; i++) {
        for (int j = 0; j < TAILLE_FACILE; j++) {
            fscanf(file, "%d", &grille[i][j]);
        }
    }
    fclose(file);
    printf("Partie chargée avec succès (facile).\n");
}


void sauvegarderPrecedent(int grille[][TAILLE_MOYENNE], int taille) {
    for (int i = 0; i < taille; i++) {
        for (int j = 0; j < taille; j++) {
            grillePrecedente[i][j] = grille[i][j];
        }
    }
}
void revenirEnArriere(int grille[][TAILLE_MOYENNE], int taille) {
    for (int i = 0; i < taille; i++) {
        for (int j = 0; j < taille; j++) {
            grille[i][j] = grillePrecedente[i][j];
        }
    }
    printf("Retour en arrière.\n");
}
void sauvegarderPrecedent_facile(int grille[][TAILLE_FACILE], int taille) {
    for (int i = 0; i < taille; i++) {
        for (int j = 0; j < taille; j++) {
            grillePrecedente_facile[i][j] = grille[i][j];
        }
    }
}
void revenirEnArriere_facile(int grille[][TAILLE_FACILE], int taille) {
    for (int i = 0; i < taille; i++) {
        for (int j = 0; j < taille; j++) {
            grille[i][j] = grillePrecedente_facile[i][j];
        }
    }
    printf("Retour en arrière.\n");
}

void sauvegarderPrecedent_difficile(int grille[][TAILLE_DIFFICILE], int taille) {
    for (int i = 0; i < taille; i++) {
        for (int j = 0; j < taille; j++) {
            grillePrecedente_difficile[i][j] = grille[i][j];
        }
    }
}
void revenirEnArriere_difficile(int grille[][TAILLE_DIFFICILE], int taille) {
    for (int i = 0; i < taille; i++) {
        for (int j = 0; j < taille; j++) {
            grille[i][j] = grillePrecedente_difficile[i][j];
        }
    }
    printf("Retour en arrière.\n");
}