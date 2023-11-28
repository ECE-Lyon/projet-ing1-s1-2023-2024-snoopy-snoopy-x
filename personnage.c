//
// Created by symph on 22/11/2023.
//

#include "personnage.h"

void initPersonnage(PERSONNAGE *perso){
    perso->vies = 3;
    perso->co.X = 0;
    perso->co.Y = 0;
}


void initBalle(BALLE *balle, int X, int Y){
    balle->co.X = X;
    balle->co.Y = Y;
    balle->direction = 2;
}

void checkDeplacementBalle(BALLE *balle, int tab[10][20]){
    switch(balle->direction){
        case 0 : {
            if(!(balle->co.X)){
                balle->direction = 3;
                checkDeplacementBalle(balle, tab);
                break;
            }
            if(!(balle->co.Y)){
                balle->direction = 1;
                checkDeplacementBalle(balle, tab);
                break;
            }
            balle->co.X--;
            balle->co.Y--;
            break;
        }
        case 1 : {
            if(!(balle->co.X)){
                balle->direction = 2;
                checkDeplacementBalle(balle, tab);
                break;
            }
            if(balle->co.Y == 19){
                balle->direction = 0;
                checkDeplacementBalle(balle, tab);
                break;
            }
            balle->co.X--;
            balle->co.Y++;
            break;
        }
        case 2 : {
            if(balle->co.X == 9){
                balle->direction = 1;
                checkDeplacementBalle(balle, tab);
                break;
            }
            if(balle->co.Y == 19){
                balle->direction = 3;
                checkDeplacementBalle(balle, tab);
                break;
            }
            balle->co.X++;
            balle->co.Y++;
            break;
        }
        case 3 : {
            if(balle->co.X == 9){
                balle->direction = 0;
                checkDeplacementBalle(balle, tab);
                break;
            }
            if(!(balle->co.Y)){
                balle->direction = 2;
                checkDeplacementBalle(balle, tab);
                break;
            }
            balle->co.X++;
            balle->co.Y--;
            break;
        }
    }
}