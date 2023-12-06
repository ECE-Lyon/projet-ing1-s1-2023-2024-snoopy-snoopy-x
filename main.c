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
    initPersonnage(&perso, 7, 73);
    BALLE balle;
    initBalle(&balle, 19, 85);

    do {
        time (&end);
        gettimeofday(&stop, NULL);
        dif = difftime(end,start);
        gotoligcol(0, 0);
        if(difMillis >= difPrecMillisBalle+250){
            difPrecMillisBalle = difMillis;
            checkDeplacementBalle(&balle, &perso, balle.co.X, balle.co.Y);
            afficherCase(&perso, &balle);

        }
        gotoligcol(perso.co.X, perso.co.Y);
        printf("O");
        gotoligcol(balle.co.X, balle.co.Y);
        printf("%c", 207);
        char a;
        gotoligcol(0, 0);

        if (_kbhit()) {
            a = (char) getch();
            if(difMillis >= difPrecMillis+100) {
                difPrecMillis = difMillis;
                afficherCase(&perso, &balle);
                switch (a) {
                    case 'd' :
                    case 'D' :
                        if (perso.co.Y < MAXY) {
                            perso.co.Y += 4;
                        }
                        break;
                    case 'q' :
                    case 'Q' :
                        if (perso.co.Y > MINY) {
                            perso.co.Y -= 4;
                        }
                        break;
                    case 's' :
                    case 'S' :
                        if (perso.co.X < MAXX) {
                            perso.co.X += 2;
                        }
                        break;
                    case 'z' :
                    case 'Z' :
                        if (perso.co.X > MINX) {
                            perso.co.X -= 2;
                        }
                        break;
                    case 'x' :
                    case 'X' :
                        finJeu = 1;
                        break;
                    case 't' :
                    case 'T' :
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
        gotoligcol(24,21);
        printf("%d, %d", perso.co.X, perso.co.Y);
        gotoligcol(25,21);
        printf("%d", perso.vies);
    }while(!finJeu);
    debugFinJeu(fichierLogs, &perso, &balle);
    return 0;
}