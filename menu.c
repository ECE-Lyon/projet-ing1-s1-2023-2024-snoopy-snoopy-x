#include "menu.h"
#include "partie.h"
#include <stdio.h>
#include <conio.h>

void reglesDuJeu(){

}

void afficherMenu() {
    int MenuminX = 6;
    int MenuminY = 40;
    gotoligcol(MenuminX + 2, MenuminY + 8);
    printf("%c", BALL);
    gotoligcol(MenuminX, MenuminY);
    printf("Bienvenue dans la revanche de Snoopy.");
    gotoligcol(MenuminX + 2, MenuminY + 10);
    printf("1. Regles du jeu");
    gotoligcol(MenuminX + 3, MenuminY + 7);
    printf("2. Lancer un nouveau Jeu");
    gotoligcol(MenuminX + 4, MenuminY + 8);
    printf("3. Charger une partie ");
    gotoligcol(MenuminX + 5, MenuminY + 11);
    printf("4. Mot de passe ");
    gotoligcol(MenuminX + 6, MenuminY + 13);
    printf("5. Scores ");
    gotoligcol(MenuminX + 7, MenuminY + 13);
    printf("6. Quitter ");


    short Select = 0;
    char key;
    do {
        if (_kbhit()) {
            key = (char) getch();
            switch (key) {
                case 'z' :
                case 'Z' :
                    if (Select > 0) {
                        Select--;
                    }
                    break;
                case 's' :
                case 'S' :
                    if (Select < 6) {
                        Select++;
                    }
                    break;
                case 'e' :
                case 'E' :
                    switch (Select) {
                        case 0 :
                            //GameRules();
                            break;
                        case 1 :
                            Niveau();
                            break;
                        case 2 :
                            //Chargement();
                            break;
                        case 3 :
                            //Password():
                            break;
                        case 4 :
                            //HighScores();
                            break;
                        case 5 :
                            break;
                    }
            }
            switch (Select) {
                case 0 :
                    gotoligcol(MenuminX + 2, MenuminY + 8);
                    printf("%c", BALL);
                    gotoligcol(MenuminX + 3, MenuminY + 5);
                    printf("  ");
                    gotoligcol(0,0);
                    break;
                case 1 :
                    gotoligcol(MenuminX + 3, MenuminY + 5);
                    printf("%c", BALL);
                    gotoligcol(MenuminX + 2, MenuminY + 8);
                    printf("  ");
                    gotoligcol(MenuminX + 4, MenuminY + 6);
                    printf("  ");
                    gotoligcol(0,0);
                    break;
                case 2:
                    gotoligcol(MenuminX + 4, MenuminY + 6);
                    printf("%c", BALL);
                    gotoligcol(MenuminX + 3, MenuminY + 5);
                    printf("  ");
                    gotoligcol(MenuminX + 5, MenuminY + 9);
                    printf("  ");
                    gotoligcol(0,0);
                    break;
                case 3 :
                    gotoligcol(MenuminX + 5, MenuminY + 9);
                    printf("%c", BALL);
                    gotoligcol(MenuminX + 4, MenuminY + 6);
                    printf("  ");
                    gotoligcol(MenuminX + 6, MenuminY + 11);
                    printf("  ");
                    gotoligcol(0,0);
                    break;
                case 4 :
                    gotoligcol(MenuminX + 6, MenuminY + 11 );
                    printf("%c", BALL);
                    gotoligcol(MenuminX + 5, MenuminY + 9);
                    printf("  ");
                    gotoligcol(MenuminX + 7, MenuminY + 11);
                    printf("  ");
                    gotoligcol(0,0);
                    break;
                case 5 :
                    gotoligcol(MenuminX + 7, MenuminY + 11);
                    printf("%c", BALL);
                    gotoligcol(MenuminX + 6, MenuminY + 11);
                    printf("  ");
                    gotoligcol(0,0);
                    break;
            }
            if(key == 'e' || key == 'E'){

            }
        }


    }while (1);
}
