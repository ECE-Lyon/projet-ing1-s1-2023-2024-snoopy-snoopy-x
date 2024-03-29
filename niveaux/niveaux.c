#include "niveaux.h"
#include "Scores.h"

void jouerNiveau(PARTIE *partie) {
    clearConsole();
    afficherCase();
    gotoligcol(5, 91);
    printf("%s%d",ANSI_YELLOW, partie->niveauActuel);
    const int tempsRestantDebut = partie->niveau.tempsRestant;
    afficherBalles(partie->niveau.nbBalles, partie->niveau.tabBalles);
    BLOCSTEMPS blocstemps[137];
    partie->niveau.difPrecMillis = 0;
    int difPrecMillisBalle = 0;
    struct timeval stop, startT;
    gettimeofday(&startT, NULL);
    gettimeofday(&stop, NULL);

    for (int i = 0; i < 137; ++i) {
        blocstemps[i].etatBloc = 1;
    }
    for (int i = 0; i < 23; ++i) {
        blocstemps[i].co.X = 5;
        blocstemps[i].co.Y = 93 + i;
        gotoligcol(blocstemps[i].co.X, blocstemps[i].co.Y);
        printf("%s%c", ANSI_GREEN, CHAR_BLOC_FIXE);
    }
    for (int i = 23; i < 44; ++i) {
        blocstemps[i].co.X = 6 + i - 23;
        blocstemps[i].co.Y = 113;
        gotoligcol(blocstemps[i].co.X, blocstemps[i].co.Y);
        printf("%s%c%c%c", ANSI_GREEN, CHAR_BLOC_FIXE, CHAR_BLOC_FIXE, CHAR_BLOC_FIXE);
    }
    for (int i = 44; i < 93; ++i) {
        blocstemps[i].co.X = 27;
        blocstemps[i].co.Y = 115 - i + 44;
        gotoligcol(blocstemps[i].co.X, blocstemps[i].co.Y);
        printf("%s%c", ANSI_GREEN, CHAR_BLOC_FIXE);
    }
    for (int i = 93; i < 115; ++i) {
        blocstemps[i].co.X = 26 - i + 93;
        blocstemps[i].co.Y = 67;
        gotoligcol(blocstemps[i].co.X, blocstemps[i].co.Y);
        printf("%s%c%c%c", ANSI_GREEN, CHAR_BLOC_FIXE, CHAR_BLOC_FIXE, CHAR_BLOC_FIXE);
    }
    for (int i = 114; i < 137; ++i) {
        blocstemps[i].co.X = 5;
        blocstemps[i].co.Y = 67 + i - 114;
        gotoligcol(blocstemps[i].co.X, blocstemps[i].co.Y);
        printf("%s%c%s", ANSI_GREEN, CHAR_BLOC_FIXE, ANSI_GREEN);
    }

    int i;
    for (i = 0; i < 120 - partie->niveau.tempsRestant; ++i) {
        if ((i < 23 || (i >= 44 && i < 93) ||
             (i >= 114 && i < 137))) {
            gotoligcol(blocstemps[i].co.X, blocstemps[i].co.Y);
            printf(" ");
        }
        else if ((i >= 23 && i < 44) ||
             (i >= 93 && i < 115)) {
            gotoligcol(blocstemps[i].co.X, blocstemps[i].co.Y);
            printf("   ");
        }
    }


    do {
        gettimeofday(&stop, NULL);

        afficherTousLesBlocs(partie->niveau.tabBlocs, partie->niveau.nbBlocs);
        afficherOiseaux(partie->niveau.oiseaux);
        if (oiseauxRecup(partie->niveau.oiseaux, partie->niveau.perso)) {
            partie->niveauActuel++;
            return;
        }
        gotoligcol(partie->niveau.perso.co.X, partie->niveau.perso.co.Y);
        printf("O");

        blocPiege(&partie->niveau.perso, partie->niveau.tabBlocs, partie->niveau.nbBlocs);
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
                    sauvegarder(*partie, selectFichier());
                    exit(0);
                }
                case 'p' :
                case 'P' : {
                    time_t tempsDebutPause = time(NULL);
                    gotoligcol(5, 9);
                    printf("Jeu en pause, appuyez sur une touche pour continuer.");
                    while (!_kbhit());
                    gotoligcol(5, 9);
                    printf("                                                    ");
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

        if (partie->niveau.perso.vies == 0 || partie->niveau.tempsRestant == 0) {
            gameOver();
        }

        partie->niveau.difMillis = ((stop.tv_sec - startT.tv_sec) * 1000000 + stop.tv_usec - startT.tv_usec) / 1000;
        partie->niveau.tempsRestant = (tempsRestantDebut*1000 - partie->niveau.difMillis) / 1000;

        if (partie->niveau.difMillis >= difPrecMillisBalle + 1000 / partie->niveau.tpsBalle) {
            difPrecMillisBalle = partie->niveau.difMillis;
            checkDeplacementToutesBalles(partie->niveau.nbBalles, partie->niveau.tabBalles, &partie->niveau.perso,
                                         partie->niveau.tabBlocs, partie->niveau.nbBlocs);
        }

        switch (partie->niveau.perso.vies) {
            case 3 :
                gotoligcol(29, 89);
                printf("%c %c %c", 3, 3, 3);
                break;
            case 2 :
                gotoligcol(29, 89);
                printf("     ");
                gotoligcol(29, 89);
                printf("  %c %c", 3, 3);
                break;
            case 1 :
                gotoligcol(29, 89);
                printf("     ");
                gotoligcol(29, 89);
                printf("    %c", 3);
                break;
        }

        if ((i < 23 || (i >= 44 && i < 93) ||
             (i >= 114 && i < 137)) && partie->niveau.difMillis >= partie->niveau.difPrecMillis + 857) {
            partie->niveau.difPrecMillis = partie->niveau.difMillis;
            gotoligcol(blocstemps[i].co.X, blocstemps[i].co.Y);
            printf(" ");
            i++;
        }
        if (((i >= 23 && i < 44) ||
             (i >= 93 && i < 115)) && partie->niveau.difMillis >= partie->niveau.difPrecMillis + 857) {
            partie->niveau.difPrecMillis = partie->niveau.difMillis;
            gotoligcol(blocstemps[i].co.X, blocstemps[i].co.Y);
            printf("   ");
            i++;
        }
    } while (1);
}