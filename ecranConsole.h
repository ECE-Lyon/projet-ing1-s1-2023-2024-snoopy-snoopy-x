#ifndef PROJET_ECRANCONSOLE_H
#define PROJET_ECRANCONSOLE_H
#include <windows.h>
#include <stdio.h>
#include "personnage.h"


void gotoligcol(int lig, int col);

void clearConsole();

void afficherTableau(int tableau[10][20], PERSONNAGE* perso, BALLE* balle);

#endif //PROJET_ECRANCONSOLE_H