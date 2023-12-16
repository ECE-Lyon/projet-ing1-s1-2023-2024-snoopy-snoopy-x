#ifndef PROJET_NIVEAU1_H
#define PROJET_NIVEAU1_H
#include "../../Affichage/plateau.h"
#include "../../entitees/blocs.h"
#include <sys/time.h>
#include "../../Niveaux/Scores.h"
#include "../../Menu/menu.h"

#define TEMPS_MAX_MILLIS 180000
#define TEMPS_MAX 180


#define TEMPSLIM 120


typedef struct Niveau {
    PERSONNAGE perso;
    short nbBalles;
    BALLE* tabBalles;
    short nbBlocs;
    BLOC* tabBlocs;
    OISEAUX oiseaux[4];
    short int tpsBalle; //Nombre de ticks par secondes du déplacement de la balle = fréquence = 1/période
    int tempsMillis;
}NIVEAU;

NIVEAU initNiveau(short int niveau);

void niveau();

#endif
