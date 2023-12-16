#ifndef PROJET_OISEAUX_H
#define PROJET_OISEAUX_H
#include "personnage.h"
#include "../entitees/conversionCoordonnees.h"
#include "../Affichage/ecranConsole.h"
#define CHAR_OISEAUX 86
void initOiseaux();
typedef struct Oiseaux{
    COORD co;
    short int recup;
}OISEAUX;

void initOiseaux(OISEAUX *oiseaux);
void victoireDefaite(PERSONNAGE *snoopy, OISEAUX *oiseaux);

#endif //PROJET_OISEAUX_H
