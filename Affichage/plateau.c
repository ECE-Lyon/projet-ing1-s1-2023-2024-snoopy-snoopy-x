#include "plateau.h"

void afficherCase() {
    int TableauminX = 6;
    int TableauminY = 70;
    gotoligcol(TableauminX, TableauminY);
    printf("%s%c",ANSI_RED, DOUBLEANGLEHAUTGAUCHE);
    for (int m = 0; m < 41; ++m) {
        printf("%s%c",ANSI_RED, DOUBLEHORIZONTAL);
    }
    printf("%s%c",ANSI_RED, DOUBLEANGLEHAUTDROIT);
    gotoligcol(TableauminX += 1, TableauminY);

    for (int k = 0; k < 9; ++k) {
        printf("%s%c ",ANSI_RED, DOUBLEVERTICAL);
        for (int l = 0; l < 9; ++l) {
            printf("   %s%c",ANSI_RED,VERTICAL);
        }
        printf("    %s%c",ANSI_RED, DOUBLEVERTICAL);
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
}
