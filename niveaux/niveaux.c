#include "niveaux.h"
#include "Scores.h"

void jouerNiveau(PARTIE *partie) {
    clearConsole();

    afficherCase();
    afficherBalles(partie->niveau.nbBalles, partie->niveau.tabBalles);

    int difMillis = 0, difPrecMillis = 0, difPrecMillisBalle = 0;
    struct timeval stop, startT;
    gettimeofday(&startT, NULL);

    do {
        gettimeofday(&stop, NULL);

        if (difMillis >= difPrecMillisBalle + 1000 / partie->niveau.tpsBalle) {
            difPrecMillisBalle = difMillis;
            checkDeplacementToutesBalles(partie->niveau.nbBalles, partie->niveau.tabBalles, &partie->niveau.perso,
                                         partie->niveau.tabBlocs, partie->niveau.nbBlocs);
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
                    FILE *fichier = selectFichier();
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
        partie->niveau.tempsRestant = (TEMPS_MAX_MILLIS - difMillis) / 1000;
        gotoligcol(0, 0);
        printf("Temps restant : %d\n", partie->niveau.tempsRestant);

        if (difMillis >= difPrecMillis + 857) {
            difPrecMillis = difMillis;
            if (partie->niveau.tempsRestant > 99) {
                gotoligcol(5, 93 + partie->niveau.i);
                printf(" ");
                partie->niveau.i += 1;
            }
            if (partie->niveau.tempsRestant == 99) {
                partie->niveau.i = 0;
            }
            if (partie->niveau.tempsRestant > 81 && partie->niveau.tempsRestant <= 99) {
                gotoligcol(6 + partie->niveau.i, 113);
                printf("   ");
                partie->niveau.i += 1;
            }
            if (partie->niveau.tempsRestant == 81) {
                partie->niveau.i = 0;
            }
            if (partie->niveau.tempsRestant > 39 && partie->niveau.tempsRestant <= 81) {
                gotoligcol(27, 115 - partie->niveau.i);
                printf(" ");
                partie->niveau.i += 1;
            }
            if (partie->niveau.tempsRestant == 39) {
                partie->niveau.i = 0;
            }
            if (partie->niveau.tempsRestant > 21 && partie->niveau.tempsRestant <= 39) {
                gotoligcol(26 - partie->niveau.i, 67);
                printf("   ");
                partie->niveau.i += 1;
            }
            if (partie->niveau.tempsRestant == 21) {
                partie->niveau.i = 0;
            }
            if (partie->niveau.tempsRestant > 0 && partie->niveau.tempsRestant <= 21) {
                gotoligcol(5, 67 + partie->niveau.i);
                printf(" ");
                partie->niveau.i += 1;
            }
        }
    } while (1);
}