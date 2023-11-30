#include "personnage.h"
#include <stdio.h>
#define Dverti 186
#define Dhoriz 205
#define Danghg 201
#define Danghd 187
#define Dangbg 200
#define Dangbd 188
#define verti 179
#define horiz 196
#define link 197

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
    printf("%c", Danghg);
    for (int m = 0; m < 41; ++m) {
        printf("%c", Dhoriz);
    }
    printf("%c\n", Danghd);


    for (int k = 0; k < 9; ++k) {
        printf("%c ", Dverti);
        for (int l = 0; l < 9; ++l) {
            printf("   %c", verti);
        }
        printf("    %c", Dverti);
        printf("\n");
        printf("%c ", Dverti);
        for (int j = 0; j < 9; ++j) {
            printf("%c%c%c", horiz, horiz, horiz);
            printf("%c", link);
        }
        printf("%c%c%c %c", horiz, horiz, horiz, Dverti);
        printf("\n");
    }
    printf("%c ", Dverti);
    for (int n = 0; n < 9; ++n) {
        printf("   %c", verti);
    }
    printf("    %c", Dverti);
    printf("\n");

    printf("%c", Dangbg);
    for (int l = 0; l < 41; ++l) {
        printf("%c", Dhoriz);
    }
    printf("%c", Dangbd);
}

void gotoligcol(int lig, int col){
    COORD mycoord;
    mycoord.X = col;
    mycoord.Y = lig;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), mycoord);
}