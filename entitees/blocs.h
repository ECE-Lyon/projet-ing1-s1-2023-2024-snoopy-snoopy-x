#ifndef PROJET_BLOCS_H
#define PROJET_BLOCS_H

//définir les char des blocs pour pouvoir les afficher après.
#define CHAR_BLOC_CASSABLE 0

#include <windows.h>
// Permet de définir les type de blocs, on le passe en typedef pour l'utiliser dans la struct BLOC.
typedef enum {cassable, malus, ect}TYPEBLOC; // Allez voir la docu sur les enums si vous voulez comprendre comment l'utiliser (pas dur)

typedef struct bloc{
    COORD co;
    TYPEBLOC type;
    short int existe;
}BLOC;

void initBloc(BLOC* bloc, TYPEBLOC type, short int X, short int Y); // Permet d'initialiser facilement les blocs

#endif //PROJET_BLOCS_H
