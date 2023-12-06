#include "plateau.h"
#include "ecranConsole.h"

int TableauminX = 6;
int TableayminY = 70;

void afficherCase(PERSONNAGE* perso, BALLE* balle) {
    gotoligcol(TableauminX, TableayminY);
    printf("%c", DOUBLEANGLEHAUTGAUCHE);
    for (int m = 0; m < 41; ++m) {
        printf("%c", DOUBLEHORIZONTAL);
    }
    printf("%c", DOUBLEANGLEHAUTDROIT);                     //ret
    gotoligcol(TableauminX += 1, TableayminY);

    for (int k = 0; k < 9; ++k) {
        printf("%c ", DOUBLEVERTICAL);
        for (int l = 0; l < 9; ++l) {
            printf("   %c", VERTICAL);
        }
        printf("    %c", DOUBLEVERTICAL);
        gotoligcol(TableauminX += 1, TableayminY);                   //ret
        printf("%c ", DOUBLEVERTICAL);
        for (int j = 0; j < 9; ++j) {
            printf("%c%c%c", HORIZONTAL, HORIZONTAL, HORIZONTAL);
            printf("%c", LINK);
        }
        printf("%c%c%c %c", HORIZONTAL, HORIZONTAL, HORIZONTAL, DOUBLEVERTICAL);
        gotoligcol(TableauminX += 1, TableayminY);                        //ret
    }
    printf("%c ", DOUBLEVERTICAL);
    for (int n = 0; n < 9; ++n) {
        printf("   %c", VERTICAL);
    }
    printf("    %c", DOUBLEVERTICAL);
    gotoligcol(TableauminX += 1, TableayminY);                         //ret

    printf("%c", DOUBLEANGLEBASGAUCHE);
    for (int l = 0; l < 41; ++l) {
        printf("%c", DOUBLEHORIZONTAL);
    }
    printf("%c", DOUBLEANGLEBASDROITE);
    TableauminX = 6;
}
