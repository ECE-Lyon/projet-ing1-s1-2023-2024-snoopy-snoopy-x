#include "partie.h"


int main() {
    FILE *fichierLogs = fopen("../consoleDebug/logs.log", "a+");
    int finJeu = 0;
    time_t start,end;
    int difMillis = 0, difPrecMillis = 0, difPrecMillisBalle = 0;
    struct timeval stop, startT;
    double dif;
    gettimeofday(&startT, NULL);
    time (&start);

    time (&end);
    PERSONNAGE perso;
    initPersonnage(&perso, 7, 73);
    BALLE balle;
    initBalle(&balle, 19, 85);
    afficherCase(&perso, &balle);

    gotoligcol(perso.co.X, perso.co.Y);
    printf("O");
    gotoligcol(balle.co.X, balle.co.Y);
    printf("%c", 207);

    do {
        time (&end);
        gettimeofday(&stop, NULL);
        dif = difftime(end,start);
        gotoligcol(0, 0);
        if(difMillis >= difPrecMillisBalle+125){
            difPrecMillisBalle = difMillis;
            checkDeplacementBalle(&balle, &perso, balle.co.X, balle.co.Y);
        }
        char a;
        gotoligcol(0, 0);

        if (_kbhit()) {
            a = (char) getch();
            switch(a) {
                case 'x' :
                case 'X' :
                    finJeu = 1;break;
                case 't' :
                case 'T' :
                    consoleDebug(fichierLogs, &perso, &balle); break;
                default :
                    deplacementPerso(&perso, a); break;
            }
            if(difMillis >= difPrecMillis+100) {
                difPrecMillis = difMillis;
                gotoligcol(perso.co.X, perso.co.Y);
                printf("O");
                gotoligcol(balle.co.X, balle.co.Y);
                printf("%c", 207);
                gotoligcol(23, 21);
                printf("PV : %d", perso.vies);
            }
        }

        gotoligcol(21, 21);
        printf("Temps : %.2f\n", dif);
        difMillis = ((stop.tv_sec - startT.tv_sec) * 1000000 + stop.tv_usec - startT.tv_usec)/1000;
        gotoligcol(22, 21);
        printf("Temps : %d\n", difMillis);
        gotoligcol(24,21);
        printf("%d, %d", perso.co.X, perso.co.Y);
    }while(!finJeu);
    debugFinJeu(fichierLogs, &perso, &balle);
    return 0;

}