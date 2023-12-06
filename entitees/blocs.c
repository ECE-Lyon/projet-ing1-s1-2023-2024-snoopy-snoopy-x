#include "blocs.h"


void initBloc(BLOC* bloc, TYPEBLOC type, short int X, short int Y){
    bloc->type = type;
    bloc->existe = 1;
    bloc->co.X = X;
    bloc->co.Y = Y;
}