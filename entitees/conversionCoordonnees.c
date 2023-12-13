#include "conversionCoordonnees.h"

//    X * 2 + 7;
//    Y * 4 + 73;

int convCoX(int x) {
    return x * 2 + 7;
}

int convCoY(int y) {
    return y * 4 + 73;
}

COORD convCo(int x, int y) {
    COORD co;
    co.X = convCoX(x);
    co.Y = convCoY(y);
    return co;
}