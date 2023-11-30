#include "ecranConsole.h"

void gotoligcol(int lig, int col){
    COORD mycoord;
    mycoord.X = col;
    mycoord.Y = lig;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), mycoord);
}

void clearConsole(){
    gotoligcol(0, 0);
    for(int i = 0; i < 30; i++){
        for(int j = 0; j < 80; j++){
            printf(" ");
        }
    }
}

void afficherTableau(int tableau[10][20], PERSONNAGE* perso, BALLE* balle){
    gotoligcol(0, 0);
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 20; y++) {
            printf("%c", tableau[x][y]);
        }
        printf("\n");
    }
    gotoligcol(perso->co.X, perso->co.Y);
    printf("S");
    gotoligcol(balle->co.X, balle->co.Y);
    printf("%c", 15);
}