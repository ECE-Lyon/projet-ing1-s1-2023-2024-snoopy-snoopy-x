#ifndef PROJET_SAUVEGARDES_H
#define PROJET_SAUVEGARDES_H
#include "stdio.h"

#include "../niveaux/Scores.h"

#define MINX_MENU_SAVE 6
#define MINY_MENU_SAVE 40

FILE* selectFichier();

PARTIE chargerNiveau(FILE* fichier);

void sauvegarder(PARTIE partie, FILE* fichier);

#endif //PROJET_SAUVEGARDES_H
