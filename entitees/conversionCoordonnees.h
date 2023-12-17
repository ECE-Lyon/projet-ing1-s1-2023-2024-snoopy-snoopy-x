#ifndef PROJET_CONVERSIONCOORDONNEES_H
#define PROJET_CONVERSIONCOORDONNEES_H

#include "windows.h"

#define MINX 7
#define MINY 73
#define MAXX (MINX+9*2)
#define MAXY (MINY+9*4)

short convCoX(int x);
short convCoY(int y);

COORD convCo(int x, int y);

#endif //PROJET_CONVERSIONCOORDONNEES_H
