#ifndef PROJET_OISEAUX_H
#define PROJET_OISEAUX_H

#include "../Affichage/plateau.h"
#include "../entitees/conversionCoordonnees.h"
#include "../Affichage/ecranConsole.h"
#include "../entitees/balle.h"
#define CHAR_OISEAUX 86
typedef struct Oiseaux{
    COORD co;
    short int recup;
}OISEAUX;

void initOiseaux(OISEAUX* oiseaux);

void afficherOiseaux(OISEAUX* oiseaux);

void recupOiseaux(OISEAUX* oiseaux, PERSONNAGE perso);

void oiseauxRecup(OISEAUX *oiseaux, PERSONNAGE perso);

#endif //PROJET_OISEAUX_H
