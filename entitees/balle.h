#ifndef PROJET_BALLE_H
#define PROJET_BALLE_H
#include "personnage.h"
#include <windows.h>

#define LINK 197
#define BALL 207
#define ANSI_CYAN "\x1b[36m"

typedef struct Balle{
    COORD co;
    short int direction;
}BALLE;


void afficherBalles(short nbBalles, BALLE* balle);

void checkDeplacementBalle(BALLE* balle, PERSONNAGE* perso, BLOC blocs[], int nbBlocs);

void checkDeplacementToutesBalles(short nbBalles, BALLE* balle, PERSONNAGE* perso, BLOC blocs[], int nbBlocs);

#endif