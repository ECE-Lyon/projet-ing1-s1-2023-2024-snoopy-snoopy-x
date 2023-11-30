#include "balle.h"

void initBalle(BALLE *balle, int X, int Y){
    balle->co.X = X;
    balle->co.Y = Y;
    balle->direction = 2;
}

void checkDeplacementBalle(BALLE *balle, int X, int Y){
    switch(balle->direction){
        case 0 : {
            if(balle->co.X <= 1){
                balle->direction = 3;
                checkDeplacementBalle(balle, X, Y);
                break;
            }
            if(balle->co.Y <= 3){
                balle->direction = 1;
                checkDeplacementBalle(balle, X, Y);
                break;
            }
            balle->co.X -= 1;
            balle->co.Y -= 2;
            break;
        }
        case 1 : {
            if(balle->co.X <= 1){
                balle->direction = 2;
                checkDeplacementBalle(balle, X, Y);
                break;
            }
            if(balle->co.Y >= 39){
                balle->direction = 0;
                checkDeplacementBalle(balle, X, Y);
                break;
            }
            balle->co.X -= 1;
            balle->co.Y += 2;
            break;
        }
        case 2 : {
            if(balle->co.X >= 19){
                balle->direction = 1;
                checkDeplacementBalle(balle, X, Y);
                break;
            }
            if(balle->co.Y >= 39){
                balle->direction = 3;
                checkDeplacementBalle(balle, X, Y);
                break;
            }
            balle->co.X += 1;
            balle->co.Y += 2;
            break;
        }
        case 3 : {
            if(balle->co.X >= 19){
                balle->direction = 0;
                checkDeplacementBalle(balle, X, Y);
                break;
            }
            if(balle->co.Y <= 3){
                balle->direction = 2;
                checkDeplacementBalle(balle, X, Y);
                break;
            }
            balle->co.X += 1;
            balle->co.Y -= 2;
            break;
        }
    }
}