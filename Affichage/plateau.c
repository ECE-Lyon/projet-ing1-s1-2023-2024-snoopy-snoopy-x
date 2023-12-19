#include "plateau.h"

void afficherCase() {
    int TableauminX = 6;
    int TableauminY = 70;

    gotoligcol(TableauminX - 2, TableauminY - 4);
    printf("%s%c", ANSI_GREEN, DOUBLEANGLEHAUTGAUCHE);
    for (int m = 0; m < 49; ++m) {
        printf("%c", DOUBLEHORIZONTAL);
    }
    printf("%c", DOUBLEANGLEHAUTDROIT);

    for(int i = 1; i < 24; i++){
        gotoligcol(TableauminX - 2 + i, TableauminY - 4);
        printf("%c", DOUBLEVERTICAL);
        gotoligcol(TableauminX - 2 + i, TableauminY + 46);
        printf("%c", DOUBLEVERTICAL);
    }
    gotoligcol(TableauminX + 22, TableauminY - 4);
    printf("%s%c", ANSI_GREEN, DOUBLEANGLEBASGAUCHE);
    for (int m = 0; m < 49; ++m) {
       // if(partie->niveau.tempsRestant)
        printf("%s%c", ANSI_GREEN, DOUBLEHORIZONTAL);
    }
    printf("%c", DOUBLEANGLEBASDROITE);

    for(int i = 0; i < 23; i++){
        for (int j = 0; j < 49; ++j) {
            gotoligcol(TableauminX - 1 + i, TableauminY - 3 + j);
            printf("%s%c",ANSI_CYAN, CHAR_BLOC_FIXE);
        }
    }

    gotoligcol(TableauminX, TableauminY);
    printf("%s%c", ANSI_GREEN, DOUBLEANGLEHAUTGAUCHE);
    for (int m = 0; m < 41; ++m) {
        printf("%s%c", ANSI_GREEN, DOUBLEHORIZONTAL);
    }
    printf("%s%c", ANSI_GREEN, DOUBLEANGLEHAUTDROIT);
    gotoligcol(TableauminX += 1, TableauminY);

    for (int k = 0; k < 9; ++k) {
        printf("%s%c ", ANSI_GREEN, DOUBLEVERTICAL);
        for (int l = 0; l < 9; ++l) {
            printf("   %s%c", ANSI_GREEN, VERTICAL);
        }
        printf("    %s%c", ANSI_GREEN, DOUBLEVERTICAL);
        gotoligcol(TableauminX += 1, TableauminY);
        printf("%c ", DOUBLEVERTICAL);
        for (int j = 0; j < 9; ++j) {
            printf("%c%c%c", HORIZONTAL, HORIZONTAL, HORIZONTAL);
            printf("%c", LINK);
        }
        printf("%c%c%c %c", HORIZONTAL, HORIZONTAL, HORIZONTAL, DOUBLEVERTICAL);
        gotoligcol(TableauminX += 1, TableauminY);
    }
    printf("%c ", DOUBLEVERTICAL);
    for (int n = 0; n < 9; ++n) {
        printf("   %c", VERTICAL);
    }
    printf("    %c", DOUBLEVERTICAL);
    gotoligcol(TableauminX += 1, TableauminY);

    printf("%c", DOUBLEANGLEBASGAUCHE);
    for (int l = 0; l < 41; ++l) {
        printf("%c", DOUBLEHORIZONTAL);
    }
    printf("%c", DOUBLEANGLEBASDROITE);

    gotoligcol(4, 90);
    printf("%c%c%c", DOUBLELIENBAS, DOUBLEHORIZONTAL, DOUBLELIENBAS);
    gotoligcol(5, 90);
    printf("%c %c", DOUBLEVERTICAL, DOUBLEVERTICAL);
    gotoligcol(6, 90);
    printf("%c%c%c",DOUBLELIENHAUT, DOUBLEHORIZONTAL, DOUBLELIENHAUT);
}
