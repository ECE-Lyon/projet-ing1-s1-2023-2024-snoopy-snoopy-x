#ifndef PROJET_NIVEAUX_H
#define PROJET_NIVEAUX_H

#include <stdio.h>
#include "../sauvegardes/sauvegardes.h"
#include "Scores.h"

//#include "../Menu/menu.h"
typedef struct BLOCSTEMPS {
    short etatBloc;
    COORD co;
}BLOCSTEMPS;

void jouerNiveau(PARTIE* partie);

#endif //PROJET_NIVEAUX_H
