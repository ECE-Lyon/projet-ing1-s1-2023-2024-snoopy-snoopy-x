#include "menu.h"
#define ANSI_RESET "\x1b[0m"
#define ANSI_BLACK "\x1b[30m"
#define ANSI_RED "\x1b[31m"
#define ANSI_GREEN "\x1b[32m"
#define ANSI_YELLOW "\x1b[33m"
#define ANSI_BLUE "\x1b[34m"
#define ANSI_MAGENTA "\x1b[35m"
#define ANSI_CYAN "\x1b[36m"
#define ANSI_WHITE "\x1b[37m"

void quitter(){
    exit(0);
}

void afficherMenu() {
    clearConsole();
    printf("\33[?25l");
    int MenuminX = 6;
    int MenuminY = 40;
    gotoligcol(MenuminX + 2, MenuminY + 8);
    printf("%c", BALL);
    gotoligcol(MenuminX, MenuminY);

    printf("%s%s%s\n", ANSI_YELLOW, "Bienvenue dans la revanche de Snoopy.", ANSI_RESET);
    gotoligcol(MenuminX + 2, MenuminY + 10);
    printf("%s%s", ANSI_RED, "1.Regles du jeu");
    gotoligcol(MenuminX + 3, MenuminY + 7);
    printf("%s%s", ANSI_BLUE, "2.Lancer un nouveau Jeu\n", ANSI_GREEN, ANSI_RESET);
    gotoligcol(MenuminX + 4, MenuminY + 8);
    printf("%s%s", ANSI_RED, " 3.Charger une partie ", ANSI_GREEN, ANSI_RESET);
    gotoligcol(MenuminX + 5, MenuminY + 11);
    printf("%s%s", ANSI_BLUE,"4. Mot de passe,"ANSI_GREEN, ANSI_RESET);
    gotoligcol(MenuminX + 6, MenuminY + 13);
    printf("%s%s", ANSI_RED,"5. Scores",ANSI_GREEN, ANSI_RESET);
    gotoligcol(MenuminX + 7, MenuminY + 13);
    printf("%s%s", ANSI_BLUE,"6. Quitter ");


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
                            reglesDuJeu();
                            break;
                        case 1 :
                            niveau();
                            break;
                        case 2 :
                            //TODO: chargement();
                            break;
                        case 3 :
                            motDePasse();
                            //TODO: password():
                            break;
                        case 4 :
                            //TODO: highScores();
                            break;
                        case 5 :
                            quitter();
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
