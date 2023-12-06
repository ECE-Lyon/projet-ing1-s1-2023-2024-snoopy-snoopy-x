#ifndef PROJET_PERSONNAGE_H
#define PROJET_PERSONNAGE_H
#define MAXX 200
#define MAXY 200
#define MINX 0
#define MINY 0

#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdio.h>


typedef struct PERSONNAGE{
    COORD co;
    short int vies;
}PERSONNAGE;



typedef struct OISEAUX{
    COORD co;
    short int recup;
}OISEAUX;



void initPersonnage(PERSONNAGE *perso, int X, int Y);
void initOiseaux(OISEAUX *oiseaux);

#endif