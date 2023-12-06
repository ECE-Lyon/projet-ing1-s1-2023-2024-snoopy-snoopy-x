#include "personnage.h"

void gotoligcol(int lig, int col){
    COORD mycoord;
    mycoord.X = col;
    mycoord.Y = lig;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), mycoord);
}


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
                cacherCharPerso(perso);
                perso->co.Y += 4;
                gotoligcol(perso->co.X, perso->co.Y);
                printf("O");
            }
            break;
        case 'q' :
        case 'Q' :
            if (perso->co.Y > MINY) {
                cacherCharPerso(perso);
                perso->co.Y -= 4;
                gotoligcol(perso->co.X, perso->co.Y);
                printf("O");
            }
            break;
        case 's' :
        case 'S' :
            if (perso->co.X < MAXX) {
                cacherCharPerso(perso);
                perso->co.X += 2;
                gotoligcol(perso->co.X, perso->co.Y);
                printf("O");
            }
            break;
        case 'z' :
        case 'Z' :
            if (perso->co.X > MINX) {
                cacherCharPerso(perso);
                perso->co.X -= 2;
                gotoligcol(perso->co.X, perso->co.Y);
                printf("O");
            }
            break;
        default :
            break;
    }
}

void cacherCharPerso(PERSONNAGE *perso){
    gotoligcol(perso->co.X, perso->co.Y),
    printf(" ");
}