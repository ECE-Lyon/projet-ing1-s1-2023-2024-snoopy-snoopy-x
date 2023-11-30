#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include "personnage.h"


void gotoligcol( int lig, int col )
{
    COORD mycoord;
    mycoord.X = col;
    mycoord.Y = lig;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}

int main() {
    time_t start,end;
    double dif;

    time (&start);
    time (&end);
    dif = difftime (end,start);
    Personnage perso;
    initPersonnage(&perso);
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


    do {
        char a;
        gotoligcol(0, 0);
        if (_kbhit()) {
            a = _getch();
            for (int x = 0; x < 10; x++) {
                for (int y = 0; y < 20; y++) {
                    printf("%c", tableau[x][y]);
                }
                printf("\n");
            }
            switch(a){
                case 'd' : perso.co.Y++; break;
                case 'q' : perso.co.Y--; break;
                case 's' : perso.co.X++; break;
                case 'z' : perso.co.X--; break;
                case 'e' : goto Fin;
                default : break;
            }
            gotoligcol(perso.co.X, perso.co.Y);
            printf("S");
        }

        if (perso.co.Y < 0) perso.co.Y =0;
        if (perso.co.X < 0) perso.co.X =0;

        time (&end);
        dif = difftime (end,start);
        gotoligcol(21, 21);
        printf("Temps : %.2f", dif);
    }while(1);
    Fin :
    return 0;
}