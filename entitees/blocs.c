#include "blocs.h"

BLOC initBloc(TYPEBLOC type, short int X, short int Y){
    BLOC bloc;
    bloc.type = type;
    bloc.existe = 1;
    bloc.pv = -1;
    bloc.co = convCo(X, Y);
    switch (bloc.type) {
        case cassable : {
            bloc.pv = 2;
        }
            break;
        case piege : {
            //TODO
        }
            break;
        case poussable : {
            //TODO
        }
            break;
        case fixe :
            break;
        case tapisroulantbas : {
        }
            break;
        case tapisroulanthaut : {
        }
            break;
        case tapisroulantdroit : {
        }
            break;
        case tapisroulantgauche : {
        }
            break;
        default :
            assert(!"Bloc non valide");
    }
    return bloc;
}

void afficherBloc(BLOC* bloc) { // Affichage d'un bloc en fonction de son type
    if (bloc->existe) {
        gotoligcol(bloc->co.X, bloc->co.Y);
        switch (bloc->type) {
            case cassable :
                if(bloc->pv == 2){
                    printf("%c", CHAR_BLOC_CASSABLE_NEUF);
                    break;
                }
                if(bloc->pv == 1){
                    printf("%c", CHAR_BLOC_CASSABLE_ABIME);
                }
                break;
            case piege :
                printf("%c", CHAR_BLOC_PIEGE);
                break;
            case poussable :
                printf("%c", CHAR_BLOC_POUSSABLE);
                break;
            case fixe :
                printf("%c", CHAR_BLOC_FIXE);
                break;
            case tapisroulantbas :
                printf("%c", CHAR_BLOC_TAPIS_BAS);
                break;
            case tapisroulanthaut :
                printf("%c", CHAR_BLOC_TAPIS_HAUT);
                break;
            case tapisroulantdroit :
                printf("%c", CHAR_BLOC_TAPIS_DROIT);
                break;
            case tapisroulantgauche :
                printf("%c", CHAR_BLOC_TAPIS_GAUCHE);
                break;
        }
    }
}

void afficherTousLesBlocs(BLOC *bloc, int nbBlocs) { // Affichage de tous les blocs via l'appel successif de la fonction afficherBloc()
    for (int i = 0; i < nbBlocs; i++) {
        gotoligcol(i, 0);
        // Pour afficher les blocs en haut pour débugger :
        // printf("%d, %d", bloc[i].existe, bloc[i].pv);
        afficherBloc(&bloc[i]);
    }
}

int collisionBlocs(short X, short Y, BLOC blocs[], int nbBlocs) {
    for (int i = 0; i < nbBlocs; i++) {
        switch (blocs->type){
            case fixe :
            case poussable :
            case cassable :
                if (blocs[i].co.X == X && blocs[i].co.Y == Y && blocs[i].existe) {
                    return 1;
                }
                break;
            default:
                break;
        }
    }
    return 0;
}

void casserBloc(short X, short Y, BLOC blocs[], int nbBlocs) {
    // Coordonnées en convCo, sert à casser le bloc cassable aux coordonnées X Y
    for (int i = 0; i < nbBlocs; i++) {
        if (blocs[i].co.X == X && blocs[i].co.Y == Y && blocs[i].type == cassable) {
            blocs[i].pv -= 1;
            if(blocs[i].pv <= 0) {
                blocs[i].existe = 0;
                gotoligcol(X, Y);
                printf(" ");
            }
        }
    }
}

void chercherCasserBlocs(COORD co, BLOC blocs[], int nbBlocs) {
    casserBloc(co.X - 2, co.Y, blocs, nbBlocs);
    casserBloc(co.X + 2, co.Y, blocs, nbBlocs);
    casserBloc(co.X, co.Y + 4, blocs, nbBlocs);
    casserBloc(co.X, co.Y - 4, blocs, nbBlocs);
}


