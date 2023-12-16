#ifndef PROJET_CONVERSIONCOORDONNEES_H
#define PROJET_CONVERSIONCOORDONNEES_H

#include "windows.h"

#define MAXX 25
#define MAXY (MAXX + 84)
#define MINX 7
#define MINY (MINX + 66)

int convCoX(int x);
int convCoY(int y);

COORD convCo(int x, int y);

#endif //PROJET_CONVERSIONCOORDONNEES_H
