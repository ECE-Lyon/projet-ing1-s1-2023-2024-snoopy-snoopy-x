#ifndef PROJET_CHARGERNIVEAUX_H
#define PROJET_CHARGERNIVEAUX_H

//#include "../Affichage/plateau.h"
#include "../entitees/Oiseaux.h"
//#include "../Menu/menu.h"
//#include "Scores.h"


#include <sys/time.h>



#define TEMPS_MAX_MILLIS 120000
#define TEMPS_MAX 180


typedef struct Niveau {
    PERSONNAGE perso;
    short nbBalles;
    BALLE* tabBalles;
    short nbBlocs;
    BLOC* tabBlocs;
    OISEAUX oiseaux[4];
    short int tpsBalle; //Nombre de ticks par secondes du déplacement de la balle = fréquence = 1/période
    int tempsRestant;
    int i;
    int pause;
    int tempsPause;
    int difMillis;
    int difTemps;
}NIVEAU;

NIVEAU initNiveau(short int niveau);

void afficherTemps();

#endif //PROJET_CHARGERNIVEAUX_H
