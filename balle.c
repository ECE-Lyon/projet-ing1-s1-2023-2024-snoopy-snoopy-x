#include "balle.h"

void initBalle(BALLE *balle, int X, int Y){                 //initialistation de la structure de la balle
    balle->co.X = X;                                        //Coordonnées X
    balle->co.Y = Y;                                        //Coordonnées Y
    balle->direction = 2;                                   //Variable de direction de la balle
}

void checkDeplacementBalle(BALLE *balle, PERSONNAGE *perso, int X, int Y){     //initialistation de la structure gerant le déplacement de la balle
    switch(balle->direction){
        case 0 : {
            if(balle->co.X <= 7){                           //
                balle->direction = 3;
                checkDeplacementBalle(balle, perso, X, Y);
                break;
            }
            if(balle->co.Y <= 73){
                balle->direction = 1;
                checkDeplacementBalle(balle, perso, X, Y);
                break;
            }
            balle->co.X -= 1;
            balle->co.Y -= 2;
            break;
        }
        case 1 : {
            if(balle->co.X <= 7){
                balle->direction = 2;
                checkDeplacementBalle(balle, perso, X, Y);
                break;
            }
            if(balle->co.Y >= 109){
                balle->direction = 0;
                checkDeplacementBalle(balle, perso, X, Y);
                break;
            }
            balle->co.X -= 1;
            balle->co.Y += 2;
            break;
        }
        case 2 : {
            if(balle->co.X >= 25){
                balle->direction = 1;
                checkDeplacementBalle(balle, perso, X, Y);
                break;
            }
            if(balle->co.Y >= 109){
                balle->direction = 3;
                checkDeplacementBalle(balle, perso, X, Y);
                break;
            }
            balle->co.X += 1;
            balle->co.Y += 2;
            break;
        }
        case 3 : {
            if(balle->co.X >= 25){
                balle->direction = 0;
                checkDeplacementBalle(balle, perso, X, Y);
                break;
            }
            if(balle->co.Y <= 73){
                balle->direction = 2;
                checkDeplacementBalle(balle, perso, X, Y);
                break;
            }
            balle->co.X += 1;
            balle->co.Y -= 2;
            break;
        }
    }
    if(balle->co.Y == perso->co.Y && balle->co.X == perso->co.X){
        perso->vies--;
        gotoligcol(23, 21);
        printf("PV : %d", perso->vies);
    }
}