#ifndef PROJET_CHARGERNIVEAUX_H
#define PROJET_CHARGERNIVEAUX_H

#include "../entitees/Oiseaux.h"
#include <sys/time.h>



typedef struct Niveau {
    PERSONNAGE perso;
    short nbBalles;
    BALLE* tabBalles;
    short nbBlocs;
    BLOC* tabBlocs;
    OISEAUX oiseaux[4];
    short int tpsBalle; //Nombre de ticks par secondes du déplacement de la balle = fréquence = 1/période
    int tempsRestant;
    int difMillis;
    int difPrecMillis;
}NIVEAU;

NIVEAU initNiveau(short int niveau);


#endif //PROJET_CHARGERNIVEAUX_H
