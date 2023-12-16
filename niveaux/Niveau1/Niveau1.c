#include "Niveau1.h"


void niveau1() {
    NIVEAU niveau = initNiveau(1);
    clearConsole();
    time_t start, end;
    int difMillis = 0, difPrecMillis = 0, difPrecMillisBalle = 0;
    struct timeval stop, startT;
    double dif;
    gettimeofday(&startT, NULL);
    time(&start);

    time(&end);
    BALLE balle;
    initBalle(&balle, convCoX(5), convCoY(5));
    afficherCase();

    gotoligcol(balle.co.X, balle.co.Y);
    printf("%c", 27);

    do {
        time(&end);
        gettimeofday(&stop, NULL);
        dif = difftime(end, start);
        gotoligcol(0, 0);
        if (difMillis >= difPrecMillisBalle + 125) {
            difPrecMillisBalle = difMillis;
            checkDeplacementBalle(&balle, &niveau.perso, niveau.tabBlocs, niveau.nbBlocs);
        }
        tapisRoulant(&niveau.perso, niveau.tabBlocs, niveau.nbBlocs);
        afficherTousLesBlocs(niveau.tabBlocs, niveau.nbBlocs);
        gotoligcol(niveau.perso.co.X, niveau.perso.co.Y);
        printf("O");

        piege(&niveau.perso, niveau.tabBlocs, niveau.nbBlocs);
        gotoligcol(23, 21);
        printf("PV : %d", niveau.perso.vies);

        char a;
        if (_kbhit()) {
            a = (char) getch();
            switch (a) {
                case 'x' :
                case 'X' :
                    quitter();
                    break;
                case 't' :
                case 'T' :
                    //consoleDebug(fichierLogs, &perso, &balle);
                    break;
                case 'm' :
                case 'M' :
                    afficherMenu();
                default :
                    deplacementPerso(&niveau.perso, a, niveau.tabBlocs, niveau.nbBlocs);
                    break;
            }
            if (difMillis >= difPrecMillis + 100) {
                difPrecMillis = difMillis;
                gotoligcol(balle.co.X, balle.co.Y);
                printf("%c", 207);

            }
        }
        if (niveau.perso.vies == 0) {
            gameOver();
        }
        gotoligcol(21, 21);
        printf("Temps : %.2f\n", dif);
        difMillis = ((stop.tv_sec - startT.tv_sec) * 1000000 + stop.tv_usec - startT.tv_usec) / 1000;
        gotoligcol(22, 21);
        printf("Temps : %d\n", difMillis);
        gotoligcol(24, 21);
        printf("Y:%d X:%d", niveau.perso.co.Y, niveau.perso.co.X);
        gotoligcol(25, 21);
        printf("co init : %d%d\n", niveau.perso.initX, niveau.perso.initY);
    } while (1);
    //debugFinJeu(fichierLogs, &perso, &balle);
}