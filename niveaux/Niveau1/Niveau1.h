#ifndef PROJET_NIVEAU1_H
#define PROJET_NIVEAU1_H
#include <stdio.h>
#include "../../Affichage/plateau.h"
#include "../../entitees/blocs.h"
#include <sys/time.h>
#include "../../consoleDebug/consoleDebug.h"
#include <conio.h>

#define TEMPSLIM 120


typedef struct Niveau {
    PERSONNAGE perso;
    short nbBalles;
    BALLE* tabBalles;
    OISEAUX oiseaux[4];
    short int tpsBalle; //Nombre de ticks par secondes du déplacement de la balle = fréquence = 1/période
    int tempsMillis;
}NIVEAU;

NIVEAU initNiveau(short int niveau);

void niveau();

#endif
