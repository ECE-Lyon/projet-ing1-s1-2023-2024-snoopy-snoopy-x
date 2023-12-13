#ifndef PROJET_BALLE_H
#define PROJET_BALLE_H
#include "personnage.h"
#include <windows.h>
//#include "../Affichage/ecranConsole.h"
#define LINK 197


typedef struct Balle{
    COORD co;
    short int direction;
}BALLE;

void initBalle(BALLE *balle, int X, int Y);
void checkDeplacementBalle(BALLE *balle, PERSONNAGE *perso, int X, int Y);


#endif