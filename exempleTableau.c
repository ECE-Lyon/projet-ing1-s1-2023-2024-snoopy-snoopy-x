#include "partie.h"

int main() {
    FILE *fichierLogs = fopen("../consoleDebug/logs.log", "a");
    int finJeu = 0;
    time_t start,end;
    int difMillis = 0, difPrecMillis = 0, difPrecMillisBalle = 0;
    struct timeval stop, startT;
    double dif;
    gettimeofday(&startT, NULL);
    time (&start);

    time (&end);
    PERSONNAGE perso;
    initPersonnage(&perso, 1, 3);
    BALLE balle;
    initBalle(&balle, 11, 31);

    do {
        time (&end);
        gettimeofday(&stop, NULL);
        dif = difftime(end,start);
        gotoligcol(0, 0);
        if(difMillis >= difPrecMillisBalle+250){
            difPrecMillisBalle = difMillis;
            checkDeplacementBalle(&balle, balle.co.X, balle.co.Y);
            afficherCase(&perso, &balle);
        }
        gotoligcol(perso.co.X, perso.co.Y);
        printf("O");
        gotoligcol(balle.co.X, balle.co.Y);
        printf("%c", 207);

        char a = 0;
        gotoligcol(0, 0);

        if (_kbhit()) {
            a = (char) getch();
            if(difMillis >= difPrecMillis+300) {
                difPrecMillis = difMillis;
                afficherCase(&perso, &balle);
                switch (a) {
                    case 'd' :
                        if (perso.co.Y < 39) {
                            perso.co.Y += 4;
                        }
                        break;
                    case 'D' :
                        if (perso.co.Y < 39) {
                            perso.co.Y += 4;
                        }
                        break;
                    case 'q' :
                        if (perso.co.Y > 3) {
                            perso.co.Y -= 4;
                        }
                        break;
                    case 'Q' :
                        if (perso.co.Y > 3) {
                            perso.co.Y -= 4;
                        }
                        break;
                    case 's' :
                        if (perso.co.X < 19) {
                            perso.co.X += 2;
                        }
                        break;
                    case 'S' :
                        if (perso.co.X < 19) {
                            perso.co.X += 2;
                        }
                        break;
                    case 'z' :
                        if (perso.co.X > 1) {
                            perso.co.X -= 2;
                        }
                        break;
                    case 'Z' :
                        if (perso.co.X > 1) {
                            perso.co.X -= 2;
                        }
                        break;
                    case 'x' :
                       finJeu = 1;
                       break;
                    case 't' :
                        consoleDebug(fichierLogs, &perso, &balle);
                        break;
                    default :
                        break;
                }
                gotoligcol(perso.co.X, perso.co.Y);
                printf("O");
                gotoligcol(balle.co.X, balle.co.Y);
                printf("%c", 207);
            }
        }

        gotoligcol(21, 21);
        printf("Temps : %.2f\n", dif);
        difMillis = ((stop.tv_sec - startT.tv_sec) * 1000000 + stop.tv_usec - startT.tv_usec)/1000;
        gotoligcol(22, 21);
        printf("Temps : %d\n", difMillis);
    }while(!finJeu);
    debugFinJeu(fichierLogs, &perso, &balle);
    return 0;
}