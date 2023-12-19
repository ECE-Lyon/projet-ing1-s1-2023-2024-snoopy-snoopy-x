#ifndef PROJET_SCORES_H
#define PROJET_SCORES_H

#include "../entitees/balle.h"
#include "chargerNiveaux.h"
//#include "../Affichage/ecranConsole.h"


void gameOver();

typedef struct Partie {
    int score[4];
    short niveauActuel;
    NIVEAU niveau;
}PARTIE;


/*
typedef struct Scores{
    short int scoreNiveau1;
    short int scoreNiveau2;
    short int scoreNiveau3;
    short int scoreNiveau4;
}SCORES;

#endif //PROJET_SCORES_H
