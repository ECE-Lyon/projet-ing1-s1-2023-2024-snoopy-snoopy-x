#ifndef PROJET_PARTIE_H
#define PROJET_PARTIE_H
#include <stdio.h>
#include "plateau.h"
#include <sys/time.h>
#include "consoleDebug/consoleDebug.h"
#include <conio.h>

#define TEMPSLIM 180


typedef struct niveau{
    PERSONNAGE perso;
    BALLE balle[5];
    int tempsMillis;

}NIVEAU;


#endif
