#ifndef PROJET_BLOCS_H
#define PROJET_BLOCS_H

#define CHAR_BLOC_CASSABLE 35
#define CHAR_BLOC_PIEGE 33
#define CHAR_BLOC_POUSSABLE 19

#include <windows.h>
#include <assert.h>
#include "../Affichage/ecranConsole.h"
//#include "../consoleDebug/consoleDebug.h"

// Permet de définir les type de blocs, on le passe en typedef pour l'utiliser dans la struct BLOC.
typedef enum {cassable, piege, poussable}TYPEBLOC; // Allez voir la docu sur les enums si vous voulez comprendre comment l'utiliser (pas dur)

typedef struct bloc{
    COORD co;
    TYPEBLOC type;
    //short pv;
    short int existe;
}BLOC;

BLOC initBloc(TYPEBLOC type, short int X, short int Y); // Permet d'initialiser facilement les blocs

void afficherBloc(BLOC bloc);

void afficherTousLesBlocs(BLOC* bloc, int nbBlocs);

short collisionBlocs(short X, short Y, BLOC blocs[], int nbBlocs);

#endif //PROJET_BLOCS_H
