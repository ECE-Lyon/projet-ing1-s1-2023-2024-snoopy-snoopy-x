#ifndef PROJET_SCORES_H
#define PROJET_SCORES_H

//#include "../Affichage/ecranConsole.h"
//#include "../Menu/menu.h"
#include <windows.h>
#include <conio.h>
#include "chargerNiveaux.h"
#include "../entitees/balle.h"

void gameOver();

typedef struct Scores{
    short int scoreNiveau1;
    short int scoreNiveau2;
    short int scoreNiveau3;
    short int scoreNiveau4;
}SCORES;

#endif //PROJET_SCORES_H
