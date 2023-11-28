#include <stdio.h>
#include "personnage.h"
#include <sys/time.h>


void gotoligcol(int lig, int col)
{
// ressources
    COORD mycoord;
    mycoord.X = col;
    mycoord.Y = lig;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), mycoord);
}

void afficherTableau(int tableau[10][20], PERSONNAGE* perso, BALLE* balle){
    gotoligcol(0, 0);
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 20; y++) {
            printf("%c", tableau[x][y]);
        }
        printf("\n");
    }
    gotoligcol(perso->co.X, perso->co.Y);
    printf("S");
    gotoligcol(balle->co.X, balle->co.Y);
    printf("%c", 15);
}

int main() {
    time_t start,end;
    struct timeval stop, startT;
    double dif, difPrec = 0;
    gettimeofday(&startT, NULL);
    time (&start);
    // Do some calculation.
    time (&end);
    dif = difftime (end,start);
    PERSONNAGE perso;
    initPersonnage(&perso);
    BALLE balle;
    initBalle(&balle, 5, 5);

    gotoligcol(0, 0);

    int tableau[10][20];
    for(int x = 0; x < 10; x++){
        for(int y = 0; y < 20; y++){
            tableau[x][y] = 254;
        }
    }


    for(int x = 0; x < 10; x++){
        for(int y = 0; y < 20; y++){
            printf("%c", tableau[x][y]);
        }
        printf("\n");
    }
    gotoligcol(perso.co.X, perso.co.Y);
    printf("S");
    gotoligcol(balle.co.X, balle.co.Y);
    printf("%c", 149);

    do {
        time (&end);
        gettimeofday(&stop, NULL);
        dif = difftime(end,start);
        if(difPrec != dif){
            checkDeplacementBalle(&balle, tableau);
            afficherTableau(tableau, &perso, &balle);
        }
        difPrec = dif;
        char a = 0;
        gotoligcol(0, 0);

        if (_kbhit()) {
            a = (char) getch();
            if(/*dif>(difPrec + 0.1)*/1) {
                difPrec = dif;
                switch (a) {
                    case 'd' :
                        perso.co.Y++;
                        break;
                    case 'q' :
                        perso.co.Y--;
                        break;
                    case 's' :
                        perso.co.X++;
                        break;
                    case 'z' :
                        perso.co.X--;
                        break;
                    case 'e' :
                        goto Fin;
                    default :
                        break;
                }
                if (perso.co.Y < 0) perso.co.Y = 0;
                if (perso.co.X < 0) perso.co.X = 0;
            }
            afficherTableau(tableau, &perso, &balle);
        }

        gotoligcol(21, 21);
        printf("Temps : %.2f\n", dif);
        gotoligcol(22, 21);
        printf("took %lu us\n", (stop.tv_sec - startT.tv_sec) * 1000000 + stop.tv_usec - startT.tv_usec);
        gotoligcol(23,21);
        printf("temps en millis : %lu", ((stop.tv_sec - startT.tv_sec) * 1000000 + stop.tv_usec - startT.tv_usec)/1000);
    }while(1);
    Fin :
    return 0;
}
