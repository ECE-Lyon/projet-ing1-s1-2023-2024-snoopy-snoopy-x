#ifndef PROJET_PARTIE_H
#define PROJET_PARTIE_H
#include <stdio.h>
#include "plateau.h"
#include "entitees/blocs.h"
#include <sys/time.h>
#include "consoleDebug/consoleDebug.h"
#include <conio.h>

#define TEMPSLIM 120


typedef struct niveau {
    PERSONNAGE perso;
    BALLE balle[5];
    short int tpsBalle; //Nombre de ticks par secondes du déplacement de la balle = fréquence = 1/période
    int tempsMillis;
};

void Niveau();

#endif
