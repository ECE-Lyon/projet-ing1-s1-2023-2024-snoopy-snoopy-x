#include "blocs.h"


BLOC initBloc(TYPEBLOC type, short int X, short int Y){
    BLOC bloc;
    bloc.type = type;
    bloc.existe = 1;
    bloc.co.X = X * 2 + 7;
    bloc.co.Y = Y * 4 + 73;
    switch (bloc.type) {
        case cassable : {

        } break;
        case piege : {

        } break;
        case poussable : {

        } break;

        default :
            assert(!"Bloc non valide");
    }
    return bloc;
}

void afficherBloc(BLOC bloc) { // Affichage d'un bloc en fonction de son type
    gotoligcol(bloc.co.X, bloc.co.Y);
    switch (bloc.type) {
        case cassable : printf("%c", CHAR_BLOC_CASSABLE); break;
        case piege : printf("%c", CHAR_BLOC_PIEGE); break;
        case poussable : printf("%c", CHAR_BLOC_POUSSABLE); break;
    }
}

void afficherTousLesBlocs(BLOC* bloc, int nbBlocs) { // Affichage de tous les blocs via l'appel suvvessif de la fonction afficherBloc()
    for (int i = 0; i < nbBlocs; i++) {
        afficherBloc(bloc[i]);
    }
}

int collisionBlocs(short X, short Y, BLOC blocs[], int nbBlocs) {
    for(int i = 0; i < nbBlocs; i++) {
        if (blocs[i].co.X == X && blocs[i].co.Y == Y) {
            return 1;
        }
    }
    return 0;
}