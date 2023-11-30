#ifndef PROJET_BALLE_H
#define PROJET_BALLE_H
#include <windows.h>

typedef struct BALLE{
    COORD co;
    short int direction;
}BALLE;

void initBalle(BALLE *balle, int X, int Y);
void checkDeplacementBalle(BALLE *balle, int X, int Y);


#endif