#ifndef PROJET_PERSONNAGE_H
#define PROJET_PERSONNAGE_H

#include <windows.h>
#include <conio.h>
#include <time.h>


typedef struct PERSONNAGE{
    COORD co;
    short int vies;
}PERSONNAGE;

typedef struct BALLE{
    COORD co;
    short int direction;
}BALLE;

void initPersonnage(PERSONNAGE *perso);

void initBalle(BALLE *balle, int X, int Y);
void checkDeplacementBalle(BALLE *balle, int tab[10][20]);

#endif //PROJET_PERSONNAGE_H