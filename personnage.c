#include "personnage.h"
#include <stdio.h>
#define DVERTI 186
#define DHORIZ 205
#define DANGHG 201
#define DANGHD 187
#define DANGBG 200
#define DANGBD 188
#define VERTI 179
#define HORIZ 196
#define LINK 197

void initPersonnage(PERSONNAGE *perso, int X, int Y){
    perso->vies = 3;
    perso->co.X = X;
    perso->co.Y = Y;
}


void initBalle(BALLE *balle, int X, int Y){
    balle->co.X = X;
    balle->co.Y = Y;
    balle->direction = 2;
}

void initOiseaux(OISEAUX *oiseaux){
    oiseaux->recup = 0;
    oiseaux->co.X = 19;
    oiseaux->co.Y = 49;
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

void afficherCase(PERSONNAGE* perso, BALLE* balle) {
    printf("%c", DANGHG);
    for (int m = 0; m < 41; ++m) {
        printf("%c", DHORIZ);
    }
    printf("%c\n", DANGHD);


    for (int k = 0; k < 9; ++k) {
        printf("%c ", DVERTI);
        for (int l = 0; l < 9; ++l) {
            printf("   %c", VERTI);
        }
        printf("    %c", DVERTI);
        printf("\n");
        printf("%c ", DVERTI);
        for (int j = 0; j < 9; ++j) {
            printf("%c%c%c", HORIZ, HORIZ, HORIZ);
            printf("%c", LINK);
        }
        printf("%c%c%c %c", HORIZ, HORIZ, HORIZ, DVERTI);
        printf("\n");
    }
    printf("%c ", DVERTI);
    for (int n = 0; n < 9; ++n) {
        printf("   %c", VERTI);
    }
    printf("    %c", DVERTI);
    printf("\n");

    printf("%c", DANGBG);
    for (int l = 0; l < 41; ++l) {
        printf("%c", DHORIZ);
    }
    printf("%c", DANGBD);
}
