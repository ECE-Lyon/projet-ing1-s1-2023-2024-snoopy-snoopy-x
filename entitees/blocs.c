#include "blocs.h"


BLOC initBloc(TYPEBLOC type, short int X, short int Y){
    BLOC bloc;
    bloc.type = type;
    bloc.existe = 1;
    bloc.co.X = X;
    bloc.co.Y = Y;
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

void afficherBloc(BLOC bloc) {
    gotoligcol(bloc.co.X, bloc.co.Y);
    switch (bloc.type) {
        case cassable : printf("%c", CHAR_BLOC_CASSABLE); break;
        case piege : printf("%c", CHAR_BLOC_PIEGE); break;
        case poussable : printf("%c", CHAR_BLOC_POUSSABLE); break;
    }
}

void afficherTousLesBlocs(BLOC* bloc, int nbBlocs) {
    for (int i = 0; i < nbBlocs; i++) {
        afficherBloc(bloc[i]);
    }
}

short collisionBlocs(short X, short Y, BLOC blocs[], int nbBlocs) {
    for(int i = 0; i < nbBlocs; i++) {
        if (blocs[i].co.X == X && blocs[i].co.Y == Y) return 0;
    }
    return 1;
}