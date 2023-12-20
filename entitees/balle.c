#include "balle.h"

void initBalle(BALLE *balle, int X, int Y){                 //initialistation de la structure de la balle
    balle->co.X = X;                                        //Coordonnées X
    balle->co.Y = Y;                                        //Coordonnées Y
    balle->direction = 2;                                   //Variable de direction de la balle
}

void afficherBalles(short nbBalles, BALLE* balle) {
    for(int i = 0; i < nbBalles; i++) {
        gotoligcol(balle[i].co.X, balle[i].co.Y);
        printf("%s%c",ANSI_CYAN, 27);
    }
}

void checkDeplacementBalle(BALLE *balle, PERSONNAGE *perso, BLOC blocs[], int nbBlocs){ //initialistation de la structure gerant le déplacement de la balle
    if(balle->co.X%2){
        if (balle->co.X == perso->co.X && balle->co.Y == perso->co.Y) {
            gotoligcol(balle->co.X, balle->co.Y);
            printf("0");
        }else {
            gotoligcol(balle->co.X, balle->co.Y);
            printf(" ");
        }
    }else{
        gotoligcol(balle->co.X, balle->co.Y);
        printf("%s%c",ANSI_CYAN, LINK);
    }
    switch(balle->direction){
        case 0 : {
            if(balle->co.X <= 7 || collisionBlocs(balle->co.X - 1, balle->co.Y - 2, blocs, nbBlocs)){
                balle->direction = 3;
                balle->co.X += 1;
                balle->co.Y -= 2;
                break;
            }
            if(balle->co.Y <= 73){
                balle->direction = 1;
                balle->co.X -= 1;
                balle->co.Y += 2;
                break;
            }
            balle->co.X -= 1;
            balle->co.Y -= 2;
            break;
        }
        case 1 : {
            if(balle->co.X <= 7 || collisionBlocs(balle->co.X - 1, balle->co.Y + 2, blocs, nbBlocs)){
                balle->direction = 2;
                balle->co.X += 1;
                balle->co.Y += 2;
                break;
            }
            if(balle->co.Y >= 109){
                balle->direction = 0;
                balle->co.X -= 1;
                balle->co.Y -= 2;
                break;
            }
            balle->co.X -= 1;
            balle->co.Y += 2;
            break;
        }
        case 2 : {
            if(balle->co.X >= 25 || collisionBlocs(balle->co.X + 1, balle->co.Y + 2, blocs, nbBlocs)){
                balle->direction = 1;
                balle->co.X -= 1;
                balle->co.Y += 2;
                break;
            }
            if(balle->co.Y >= 109){
                balle->direction = 3;
                balle->co.X += 1;
                balle->co.Y -= 2;
                break;
            }
            balle->co.X += 1;
            balle->co.Y += 2;
            break;
        }
        case 3 : {
            if(balle->co.X >= 25 || collisionBlocs(balle->co.X + 1, balle->co.Y - 2, blocs, nbBlocs)){
                balle->direction = 0;
                balle->co.X -= 1;
                balle->co.Y -= 2;
                break;
            }
            if(balle->co.Y <= 73){
                balle->direction = 2;
                balle->co.X += 1;
                balle->co.Y += 2;
                break;
            }
            balle->co.X += 1;
            balle->co.Y -= 2;
            break;
        }
        default : exit(100000);
    }
    gotoligcol(balle->co.X, balle->co.Y);
    printf("%s%c",ANSI_CYAN, 207);
    if(balle->co.Y == perso->co.Y && balle->co.X == perso->co.X){
        perso->vies--;
        resetPosition(perso);
        gotoligcol(perso->co.X, perso->co.Y);
        printf("O");
        gotoligcol(23, 21);
        printf("%s PV : %d",ANSI_CYAN, perso->vies);
    }
}

void checkDeplacementToutesBalles(short nbBalles, BALLE* balle, PERSONNAGE* perso, BLOC blocs[], int nbBlocs) {
    for(int i = 0; i < nbBalles; i++) {
        checkDeplacementBalle(&balle[i], perso, blocs, nbBlocs);
    }
}