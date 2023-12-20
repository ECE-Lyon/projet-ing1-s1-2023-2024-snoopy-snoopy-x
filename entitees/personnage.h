#ifndef PROJET_PERSONNAGE_H
#define PROJET_PERSONNAGE_H


#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdio.h>
#include "../Affichage/ecranConsole.h"
#include "blocs.h"


typedef struct Personnage{
    COORD co;
    unsigned short int vies;
    unsigned short int initX;
    unsigned short int initY;
}PERSONNAGE;


void resetPosition(PERSONNAGE *perso);

void deplacementPerso(PERSONNAGE *perso, char input, BLOC blocs[], int nbBlocs);
void cacherCharPerso(PERSONNAGE *perso);

void tapisRoulant(PERSONNAGE *perso, BLOC blocs[], int nbBlocs);
void blocPiege(PERSONNAGE *perso, BLOC blocs[], int nbBlocs);
void blocPoussable(PERSONNAGE *perso, BLOC blocs[], int nbBlocs);
#endif