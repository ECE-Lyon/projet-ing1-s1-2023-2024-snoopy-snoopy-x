#ifndef PROJET_SCORES_H
#define PROJET_SCORES_H
#include "../entitees/personnage.h"
#include "../entitees/balle.h"
#include "../Affichage/ecranConsole.h"
#define BLOC_GAMEOVER 219

void gameOver();

typedef struct Scores{
    short int scoreNiveau1;
    short int scoreNiveau2;
    short int scoreNiveau3;
    short int scoreNiveau4;
}SCORES;

#endif //PROJET_SCORES_H
