#include "personnage.h"

void initPersonnage(PERSONNAGE *perso, int X, int Y){
    perso->vies = 3;
    perso->co.X = X;
    perso->co.Y = Y;
}


void initOiseaux(OISEAUX *oiseaux){
    oiseaux->recup = 0;
    oiseaux->co.X = 19;
    oiseaux->co.Y = 49;
}


void deplacementPerso(PERSONNAGE *perso, char input){
    switch (input) {
        case 'd' :
        case 'D' :
            if (perso->co.Y < MAXY) {
                perso->co.Y += 4;
            }
            break;
        case 'q' :
        case 'Q' :
            if (perso->co.Y > MINY) {
                perso->co.Y -= 4;
            }
            break;
        case 's' :
        case 'S' :
            if (perso->co.X < MAXX) {
                perso->co.X += 2;
            }
            break;
        case 'z' :
        case 'Z' :
            if (perso->co.X > MINX) {
                perso->co.X -= 2;
            }
            break;
        default :
            break;
    }
}