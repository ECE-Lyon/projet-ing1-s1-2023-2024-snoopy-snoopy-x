#ifndef PROJET_SCORES_H
#define PROJET_SCORES_H

#include "../entitees/balle.h"
#include "chargerNiveaux.h"


void gameOver();

typedef struct Partie {
    int score[4];
    short niveauActuel;
    NIVEAU niveau;
}PARTIE;


#endif //PROJET_SCORES_H
