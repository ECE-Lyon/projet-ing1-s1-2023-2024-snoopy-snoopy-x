#include "menu.h"


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

    gotoligcol(0,0);
    printf("%s%s", ANSI_RED
            "                       #                       \n"
           "                      ###                      \n"
           "                      # #                      \n"
           "                     ## ##                     \n"
           "                    ##   ##                    \n"
           "                    ##    #                    \n"
           "                   ##     ##                   \n"
           "                   #       ##                  \n"
           "                  #         #                  \n"
           "  #################         ################# \n"
           "    ##                                   ##   \n"
           "      ###                             ###      \n"
           "        ####                        ###        \n"
           "           ###                   ###           \n"
           "              ##               ###             \n"
           "              ##                ##             \n"
           "             ##                  #             \n"
           "             #         ##        ##            \n"
           "            ##      ### ###       ##           \n"
           "            #     ###      ###    ##           \n"
           "           ##  ###           ###   ##          \n"
           "           # ###                ### #          \n"
           "          ###                      ###         \n"
           "          #                          #         ");
    gotoligcol(0,70);
    printf("                       #                       \n");
    gotoligcol(1,70);
    printf("                      ###                      \n");
    gotoligcol(2,70);
    printf("                      # #                      \n");
    gotoligcol(3,70);
    printf("                     ## ##                     \n");
    gotoligcol(4,70);
    printf("                    ##   ##                    \n");
    gotoligcol(5,70);
    printf("                    ##    #                    \n");
    gotoligcol(6,70);
    printf("                   ##     ##                   \n");
    gotoligcol(7,70);
    printf("                   #       ##                  \n");
    gotoligcol(8,70);
    printf("                  #         #                  \n");
    gotoligcol(9,70);
    printf("  #################         ################# \n");
    gotoligcol(10,70);
    printf("    ##                                   ##   \n");
    gotoligcol(11,70);
    printf("      ###                             ###      \n");
    gotoligcol(12,70);
    printf("        ####                        ###        \n");
    gotoligcol(13,70);
    printf("           ###                   ###           \n");
    gotoligcol(14,70);
    printf("              ##               ###             \n");
    gotoligcol(15,70);
    printf("              ##                ##             \n");
    gotoligcol(16,70);
    printf("             ##                  #             \n");
    gotoligcol(17,70);
    printf("             #         ##        ##            \n");
    gotoligcol(18,70);
    printf("            ##      ### ###       ##           \n");
    gotoligcol(19,70);
    printf("            #     ###      ###    ##           \n");
    gotoligcol(20,70);
    printf("           ##  ###           ###   ##          \n");
    gotoligcol(21,70);
    printf("           # ###                ### #          \n");
    gotoligcol(22,70);
    printf("          ###                      ###         \n");
    gotoligcol(23,70);
    printf("          #                          #         ");

    gotoligcol(MenuminX, MenuminY);
    printf("%s%s%s\n", ANSI_YELLOW, "Bienvenue dans la revanche de Snoopy.", ANSI_RESET);
    gotoligcol(MenuminX + 2, MenuminY + 10);
    printf("%s%s", ANSI_RED, "1.Regles du jeu");
    gotoligcol(MenuminX + 3, MenuminY + 7);
    printf("%s%s", ANSI_BLUE, "2.Lancer un nouveau Jeu\n", ANSI_GREEN, ANSI_RESET);
    gotoligcol(MenuminX + 4, MenuminY + 8);
    printf("%s%s", ANSI_RED, " 3.Charger une partie ", ANSI_GREEN, ANSI_RESET);
    gotoligcol(MenuminX + 5, MenuminY + 11);
    printf("%s%s", ANSI_BLUE,"4.Mot de passe"ANSI_GREEN, ANSI_RESET);
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
                case 'Z' :
                case 'z' :
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
                        case 1 : {
                            PARTIE partie = niveau1();
                            PARTIE partie1 = niveau2(partie);
                            PARTIE partie2 = niveau3(partie1);
                            //partie2;
                            afficherMenu();
                            break;
                        }
                        case 2 :{
                            PARTIE partie = chargerNiveau(selectFichier());
                            jouerNiveau(&partie);
                        }

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
                    printf("%s%c",ANSI_YELLOW, BALL);
                    gotoligcol(MenuminX + 3, MenuminY + 5);
                    printf("  ");
                    gotoligcol(0,0);
                    break;
                case 1 :
                    gotoligcol(MenuminX + 3, MenuminY + 5);
                    printf("%s%c",ANSI_YELLOW, BALL);
                    gotoligcol(MenuminX + 2, MenuminY + 8);
                    printf("  ");
                    gotoligcol(MenuminX + 4, MenuminY + 6);
                    printf("  ");
                    gotoligcol(0,0);
                    break;
                case 2:
                    gotoligcol(MenuminX + 4, MenuminY + 6);
                    printf("%s%c",ANSI_YELLOW, BALL);
                    gotoligcol(MenuminX + 3, MenuminY + 5);
                    printf("  ");
                    gotoligcol(MenuminX + 5, MenuminY + 9);
                    printf("  ");
                    gotoligcol(0,0);
                    break;
                case 3 :
                    gotoligcol(MenuminX + 5, MenuminY + 9);
                    printf("%s%c", ANSI_YELLOW,BALL);
                    gotoligcol(MenuminX + 4, MenuminY + 6);
                    printf("  ");
                    gotoligcol(MenuminX + 6, MenuminY + 11);
                    printf("  ");
                    gotoligcol(0,0);
                    break;
                case 4 :
                    gotoligcol(MenuminX + 6, MenuminY + 11 );
                    printf("%s%c", ANSI_YELLOW,BALL);
                    gotoligcol(MenuminX + 5, MenuminY + 9);
                    printf("  ");
                    gotoligcol(MenuminX + 7, MenuminY + 11);
                    printf("  ");
                    gotoligcol(0,0);
                    break;
                case 5 :
                    gotoligcol(MenuminX + 7, MenuminY + 11);
                    printf("%s%c",ANSI_YELLOW, BALL);
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
