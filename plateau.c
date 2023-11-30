#include "plateau.h"


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
