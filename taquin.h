#ifndef TAQUIN_H
#define TAQUIN_H

#define TAILLE_FACILE 3
#define TAILLE_MOYENNE 4
#define TAILLE_DIFFICILE 9
#define MAX_HISTORIQUE 1000



// Déclaration des fonctions
void initialGrille(int grille[TAILLE_MOYENNE][TAILLE_MOYENNE]);
void initialGrille_facile(int grille[TAILLE_FACILE][TAILLE_FACILE]);
void initialGrille_difficile(int grille[TAILLE_DIFFICILE][TAILLE_DIFFICILE] );

void affichage_Grille(int grille[TAILLE_MOYENNE][TAILLE_MOYENNE]);
void affichage_Grille_facile(int grille[TAILLE_FACILE][TAILLE_FACILE]);
void affichage_Grille_difficile(int grille[TAILLE_DIFFICILE][TAILLE_DIFFICILE]);


void random(int grille[TAILLE_MOYENNE][TAILLE_MOYENNE]);
void random_facile(int grille[TAILLE_FACILE][TAILLE_FACILE]);
void random_difficile(int grille[TAILLE_DIFFICILE][TAILLE_DIFFICILE]);

void deplacerCase(int grille[TAILLE_MOYENNE][TAILLE_MOYENNE], char direction);
void deplacerCase_facile(int grille[TAILLE_FACILE][TAILLE_FACILE], char direction);
void deplacerCase_difficile(int grille[TAILLE_DIFFICILE][TAILLE_DIFFICILE], char direction);

int  victoir(int grille[TAILLE_MOYENNE][TAILLE_MOYENNE]);
int  victoir_facile(int grille[TAILLE_FACILE][TAILLE_FACILE]);
int  victoir_difficile(int grille[TAILLE_DIFFICILE][TAILLE_DIFFICILE]);


void sauvegarderPartie_facile(int grille[TAILLE_FACILE][TAILLE_FACILE]);
void sauvegarderPartie_moyen(int grille[TAILLE_MOYENNE][TAILLE_MOYENNE]);
void sauvegarderPartie_difficile(int grille[TAILLE_DIFFICILE][TAILLE_DIFFICILE]);

void chargerPartie_facile(int grille[TAILLE_FACILE][TAILLE_FACILE]);
void chargerPartie_moyen(int grille[TAILLE_MOYENNE][TAILLE_MOYENNE]);
void chargerPartie_difficile(int grille[TAILLE_DIFFICILE][TAILLE_DIFFICILE]);

extern int grillePrecedente[TAILLE_MOYENNE][TAILLE_MOYENNE];
void sauvegarderPrecedent(int grille[][TAILLE_MOYENNE], int taille);
void revenirEnArriere(int grille[][TAILLE_MOYENNE], int taille);

extern int grillePrecedente_facile[TAILLE_FACILE][TAILLE_FACILE];
void sauvegarderPrecedent_facile(int grille[][TAILLE_FACILE], int taille);
void revenirEnArriere_facile(int grille[][TAILLE_FACILE], int taille);

extern int grillePrecedente_difficile[TAILLE_DIFFICILE][TAILLE_DIFFICILE];
void sauvegarderPrecedent_difficile(int grille[][TAILLE_DIFFICILE], int taille);
void revenirEnArriere_difficile(int grille[][TAILLE_DIFFICILE], int taille);

extern char historiqueMouvements[MAX_HISTORIQUE];
extern int compteurMouvements;

#endif
