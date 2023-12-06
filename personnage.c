#include "personnage.h"

void initPersonnage(PERSONNAGE *perso, int X, int Y){
    perso->vies = 3;
    perso->co.X = X;
    perso->co.Y = Y;
}


void initOiseaux(OISEAUX *oiseaux){
    oiseaux->recup = 0;
    oiseaux->co.X = 19;
    oiseaux->co.Y = 49;
}


