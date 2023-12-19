#include "niveaux.h"

void jouerNiveau(PARTIE* partie) {
    clearConsole();

    afficherCase();
    afficherBalles(partie->niveau.nbBalles, partie->niveau.tabBalles);

    int difMillis = 0, difPrecMillis = 0, difPrecMillisBalle = 0;
    struct timeval stop, startT;
    gettimeofday(&startT, NULL);

    do {
        gettimeofday(&stop, NULL);

        if (difMillis >= difPrecMillisBalle + 1000/partie->niveau.tpsBalle) {
            difPrecMillisBalle = difMillis;
            checkDeplacementToutesBalles(partie->niveau.nbBalles, partie->niveau.tabBalles, &partie->niveau.perso, partie->niveau.tabBlocs, partie->niveau.nbBlocs);
        }

        afficherTousLesBlocs(partie->niveau.tabBlocs, partie->niveau.nbBlocs);
        afficherOiseaux(partie->niveau.oiseaux);
        oiseauxRecup(partie->niveau.oiseaux, partie->niveau.perso);
        gotoligcol(partie->niveau.perso.co.X, partie->niveau.perso.co.Y);
        printf("O");

        blocPiege(&partie->niveau.perso, partie->niveau.tabBlocs, partie->niveau.nbBlocs);
        gotoligcol(23, 21);
        printf("PV : %d", partie->niveau.perso.vies);

        tapisRoulant(&partie->niveau.perso, partie->niveau.tabBlocs, partie->niveau.nbBlocs);
        char a;
        if (_kbhit()) {
            a = (char) getch();
            switch (a) {
                case 'x' :
                case 'X' :
                    exit(0);
                case 'n' :
                case 'N' : {
                    FILE* fichier = selectFichier();
                    sauvegarder(*partie, fichier);
                    exit(0);
                }
                case 'm' :
                case 'M' :
                    //afficherMenu();
                default :
                    deplacementPerso(&partie->niveau.perso, a, partie->niveau.tabBlocs, partie->niveau.nbBlocs);
                    recupOiseaux(partie->niveau.oiseaux, partie->niveau.perso);
                    break;
            }
            if (difMillis >= difPrecMillis + 100) {
                difPrecMillis = difMillis;
            }
        }

        if (partie->niveau.perso.vies == 0) {
            gameOver();
        }

        difMillis = ((stop.tv_sec - startT.tv_sec) * 1000000 + stop.tv_usec - startT.tv_usec) / 1000;
        partie->niveau.tempsMillis = difMillis;
        gotoligcol(0, 0);
        printf("Temps restant : %d\n", (TEMPS_MAX_MILLIS - partie->niveau.tempsMillis)/1000);
        /*
        gotoligcol(24, 21);
        printf("X:%d Y:%d", partie->niveau.perso.co.X, partie->niveau.perso.co.Y);
        gotoligcol(25, 21);
        printf("co init : %d %d\n", partie->niveau.perso.initX, partie->niveau.perso.initY);
        */
    } while (1);
}