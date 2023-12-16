#include "conversionCoordonnees.h"


int convCoX(int x) {
    return ((x * 2) + MINX);
}

int convCoY(int y) {
    return ((y * 4) + MINY);
}

COORD convCo(int x, int y) {
    COORD co;
    co.X = convCoX(x);
    co.Y = convCoY(y);
    return co;
}