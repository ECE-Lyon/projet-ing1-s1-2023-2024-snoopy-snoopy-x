#ifndef PROJET_CONSOLEDEBUG_H
#define PROJET_CONSOLEDEBUG_H
#include "../entitees/balle.h"
#include <assert.h>
#include "../ecranConsole.h"


void printDateDansLogs(FILE* fichierLogs);

void consoleDebug(FILE* fichierLogs, PERSONNAGE* perso, BALLE* balle);

void debugFinJeu(FILE* fichierLogs, PERSONNAGE* perso, BALLE* balle);


#endif //PROJET_CONSOLEDEBUG_H
