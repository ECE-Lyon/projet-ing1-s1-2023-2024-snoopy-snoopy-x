#ifndef PROJET_PERSONNAGE_H
#define PROJET_PERSONNAGE_H
#define MAXX 25
#define MAXY 109
#define MINX 7
#define MINY 73

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

void deplacementPerso(PERSONNAGE *perso, char input, BLOC blocs[], int nbBlocs);
void cacherCharPerso(PERSONNAGE *perso);

void initvictoireoudefaite(PERSONNAGE *snoopy, OISEAUX *oiseaux);

#endif