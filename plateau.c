#include "plateau.h"
#include "ecranConsole.h"



void afficherCase() {
    int TableauminX = 6;
    int TableauminY = 70;
    gotoligcol(TableauminX, TableauminY);
    printf("%c", DOUBLEANGLEHAUTGAUCHE);
    for (int m = 0; m < 41; ++m) {
        printf("%c", DOUBLEHORIZONTAL);
    }
    printf("%c", DOUBLEANGLEHAUTDROIT);
    gotoligcol(TableauminX += 1, TableauminY);

    for (int k = 0; k < 9; ++k) {
        printf("%c ", DOUBLEVERTICAL);
        for (int l = 0; l < 9; ++l) {
            printf("   %c", VERTICAL);
        }
        printf("    %c", DOUBLEVERTICAL);
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
    TableauminX = 6;
}
