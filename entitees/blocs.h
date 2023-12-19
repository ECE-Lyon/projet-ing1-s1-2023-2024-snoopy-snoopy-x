#ifndef PROJET_BLOCS_H
#define PROJET_BLOCS_H

#define CHAR_BLOC_CASSABLE_NEUF 177
#define CHAR_BLOC_CASSABLE_ABIME 176
#define CHAR_BLOC_PIEGE 19
#define CHAR_BLOC_POUSSABLE 61
#define CHAR_BLOC_FIXE 219
#define CHAR_BLOC_TAPIS_HAUT 24
#define CHAR_BLOC_TAPIS_BAS 25
#define CHAR_BLOC_TAPIS_DROIT 26
#define CHAR_BLOC_TAPIS_GAUCHE 60

#include <windows.h>
#include <assert.h>
#include "../Affichage/ecranConsole.h"
#include "conversionCoordonnees.h"
//#include "../consoleDebug/consoleDebug.h"

// Permet de définir les type de blocs, on le passe en typedef pour l'utiliser dans la struct BLOC.
typedef enum {cassable, pieges, poussable, fixe, tapisroulantbas, tapisroulantgauche, tapisroulanthaut, tapisroulantdroit}TYPEBLOC; // Allez voir la docu sur les enums si vous voulez comprendre comment l'utiliser (pas dur)
//équivalent save: A,     B,       C,       D,       E,                F,                    G,                 H
typedef struct bloc{
    COORD co;
    TYPEBLOC type;
    short pv, deplacementRestant;
    short existe;
}BLOC;

BLOC initBloc(TYPEBLOC type, short int X, short int Y); // Permet d'initialiser facilement les blocs

void afficherBloc(BLOC* bloc);

void afficherTousLesBlocs(BLOC* bloc, int nbBlocs);

int collisionBlocs(short X, short Y, BLOC blocs[], int nbBlocs);

void casserBloc(short X, short Y, BLOC blocs[], int nbBlocs);

void chercherCasserBlocs(COORD co, BLOC blocs[], int nbBlocs);


#endif //PROJET_BLOCS_H
