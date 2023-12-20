#include "niveaux.h"
#include "Scores.h"

void jouerNiveau(PARTIE *partie) {
    clearConsole();

    afficherCase();
    gotoligcol(5, 91);
    printf("%d", partie->niveauActuel);
    afficherBalles(partie->niveau.nbBalles, partie->niveau.tabBalles);

    partie->niveau.difPrecMillis = 0;
    int difPrecMillisBalle = 0;
    int difMillis = 0;
    partie->niveau.tempsRestant = 120;
    struct timeval stop, startT, pause, finPause;
    gettimeofday(&startT, NULL);
    gettimeofday(&stop, NULL);


    do {
        gettimeofday(&stop, NULL);

        if (partie->niveau.difMillis >= difPrecMillisBalle + 1000 / partie->niveau.tpsBalle) {
            difPrecMillisBalle = partie->niveau.difMillis;
            checkDeplacementToutesBalles(partie->niveau.nbBalles, partie->niveau.tabBalles, &partie->niveau.perso,
                                         partie->niveau.tabBlocs, partie->niveau.nbBlocs);
        }

        afficherTousLesBlocs(partie->niveau.tabBlocs, partie->niveau.nbBlocs);
        afficherOiseaux(partie->niveau.oiseaux);
        if (oiseauxRecup(partie->niveau.oiseaux, partie->niveau.perso)) {
            partie->niveauActuel++;
            return;
        }
        gotoligcol(partie->niveau.perso.co.X, partie->niveau.perso.co.Y);
        printf("O");

        blocPiege(&partie->niveau.perso, partie->niveau.tabBlocs, partie->niveau.nbBlocs);
        gotoligcol(23, 21);
        printf("PV : %d", partie->niveau.perso.vies);

        tapisRoulant(&partie->niveau.perso, partie->niveau.tabBlocs, partie->niveau.nbBlocs);
        char key;
        char a;
        if (_kbhit()) {
            a = (char) getch();
            switch (a) {
                case 'x' :
                case 'X' :
                    exit(0);
                case 'n' :
                case 'N' : {
                    sauvegarder(*partie, selectFichier());
                    exit(0);
                }
                case 'p' :
                case 'P' : {
                    time_t tempsDebutPause = time(NULL);
                    gotoligcol(5, 9);
                    printf("Jeu en pause, taper P pour continuer %ld\n", pause.tv_sec);
                    gotoligcol(5, 10);
                    while (!_kbhit());
                    time_t tempsFinPause = time(NULL);
                    time_t tempsDePause = difftime(tempsDebutPause, tempsFinPause);
                    startT.tv_sec -= (int) tempsDePause;
                    break;
                }
                default :
                    deplacementPerso(&partie->niveau.perso, a, partie->niveau.tabBlocs, partie->niveau.nbBlocs);
                    recupOiseaux(partie->niveau.oiseaux, partie->niveau.perso);
                    break;
            }
        }

        if (partie->niveau.perso.vies == 0 || partie->niveau.tempsRestant == -1) {
            gameOver();
        }
        gotoligcol(0, 0);
        printf("Pause ? : %d\n", partie->niveau.pause);
        printf("temps restant : %d  \n", partie->niveau.tempsRestant);
        printf("temps Pause : %d\n", partie->niveau.tempsPause);
        printf("temps diftemps : %d\n", partie->niveau.difTemps);

        partie->niveau.difMillis = ((stop.tv_sec - startT.tv_sec) * 1000000 + stop.tv_usec - startT.tv_usec) / 1000;
        partie->niveau.tempsRestant = (TEMPS_MAX_MILLIS - partie->niveau.difMillis) / 1000;



        if (partie->niveau.difMillis >= partie->niveau.difPrecMillis + 857) {
            partie->niveau.difPrecMillis = partie->niveau.difMillis;
            if (partie->niveau.tempsRestant == 119){
                partie->niveau.i = 0;
            }
            if (partie->niveau.tempsRestant > 99 && partie->niveau.tempsRestant <= 120) {
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
            if (partie->niveau.tempsRestant > 1 && partie->niveau.tempsRestant <= 21) {
                gotoligcol(5, 67 + partie->niveau.i);
                printf(" ");
                partie->niveau.i += 1;
            }
        }

        } while (1);
    }