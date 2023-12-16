#ifndef PROJET_PERSONNAGE_H
#define PROJET_PERSONNAGE_H

#define CHAR_OISEAUX 118

#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdio.h>
#include "../Affichage/ecranConsole.h"
#include "blocs.h"
//#include "consoleDebug/consoleDebug.h"


typedef struct Personnage{
    COORD co;
    unsigned short int vies;
    unsigned short int initX;
    unsigned short int initY;
}PERSONNAGE;



void initPersonnage(PERSONNAGE *perso, int X, int Y);

void afficherOiseaux();
void resetPosition(PERSONNAGE *perso);

void deplacementPerso(PERSONNAGE *perso, char input, BLOC blocs[], int nbBlocs);
void cacherCharPerso(PERSONNAGE *perso);

void tapisRoulant(PERSONNAGE *perso, BLOC blocs[], int nbBlocs);

#endif