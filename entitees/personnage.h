#ifndef PROJET_PERSONNAGE_H
#define PROJET_PERSONNAGE_H
#define MAXX 25
#define MAXY 109
#define MINX 7
#define MINY 73
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
}PERSONNAGE;



typedef struct Oiseaux{
    COORD co;
    short int recup;
}OISEAUX;


void initPersonnage(PERSONNAGE *perso, int X, int Y);
void initOiseaux(OISEAUX *oiseaux);
void afficherOiseaux();

void deplacementPerso(PERSONNAGE *perso, char input, BLOC blocs[], int nbBlocs);
void cacherCharPerso(PERSONNAGE *perso);

void tapisRoulant(short X, short Y,PERSONNAGE *perso, BLOC blocs[], int nbBlocs);

#endif