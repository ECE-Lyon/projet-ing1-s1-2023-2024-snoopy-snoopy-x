#ifndef PROJET_PERSONNAGE_H
#define PROJET_PERSONNAGE_H
#include <windows.h>
#include <conio.h>
#include <time.h>


typedef struct PERSONNAGE{
    COORD co;
    short int vies;
}Personnage;

void initPersonnage(Personnage *perso);



#endif //PROJET_PERSONNAGE_H
