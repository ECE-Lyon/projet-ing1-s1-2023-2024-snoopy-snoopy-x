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

typedef struct OISEAUX{
    COORD co;
    short int recup;
}OISEAUX;

typedef struct PARTIE{
    BALLE balle;
    PERSONNAGE perso;
}PARTIE;

void initPersonnage(PERSONNAGE *perso, int X, int Y);
void initBalle(BALLE *balle, int X, int Y);
void afficherCase(PERSONNAGE* perso, BALLE* balle);
void checkDeplacementBalle(BALLE *balle, int X, int Y);
void initOiseaux(OISEAUX *oiseaux);

#endif