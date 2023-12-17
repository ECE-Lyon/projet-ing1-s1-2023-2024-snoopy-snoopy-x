#include "niveaux.h"

void jouerNiveau(NIVEAU* niveau) {
    clearConsole();

    afficherCase();
    afficherBalles(niveau->nbBalles, niveau->tabBalles);

    int difMillis = 0, difPrecMillis = 0, difPrecMillisBalle = 0;
    struct timeval stop, startT;

    do {
        gettimeofday(&stop, NULL);

        if (difMillis >= difPrecMillisBalle + 1000/niveau->tpsBalle) {
            difPrecMillisBalle = difMillis;
            checkDeplacementTouesBalles(niveau->nbBalles, niveau->tabBalles, &niveau->perso, niveau->tabBlocs, niveau->nbBlocs);
        }

        afficherTousLesBlocs(niveau->tabBlocs, niveau->nbBlocs);
        gotoligcol(niveau->perso.co.X, niveau->perso.co.Y);
        printf("O");

        blocPiege(&niveau->perso, niveau->tabBlocs, niveau->nbBlocs);
        gotoligcol(23, 21);
        printf("PV : %d", niveau->perso.vies);

        tapisRoulant(&niveau->perso, niveau->tabBlocs, niveau->nbBlocs);
        char a;
        if (_kbhit()) {
            a = (char) getch();
            switch (a) {
                case 'x' :
                case 'X' :
                    quitter();
                    break;
                case 'm' :
                case 'M' :
                    afficherMenu();
                default :
                    deplacementPerso(&niveau->perso, a, niveau->tabBlocs, niveau->nbBlocs);
                    break;
            }
            if (difMillis >= difPrecMillis + 100) {
                difPrecMillis = difMillis;
            }
        }

        if (niveau->perso.vies == 0) {
            gameOver();
        }

        difMillis = ((stop.tv_sec - startT.tv_sec) * 1000000 + stop.tv_usec - startT.tv_usec) / 1000;
        niveau->tempsMillis = difMillis;
        gotoligcol(22, 21);
        printf("Temps restant : %d\n", (TEMPS_MAX_MILLIS - niveau->tempsMillis)/1000);
        /*
        gotoligcol(24, 21);
        printf("X:%d Y:%d", niveau->perso.co.X, niveau->perso.co.Y);
        gotoligcol(25, 21);
        printf("co init : %d %d\n", niveau->perso.initX, niveau->perso.initY);
        */
    } while (1);
}