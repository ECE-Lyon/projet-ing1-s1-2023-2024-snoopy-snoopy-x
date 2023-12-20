#include "Niveau4.h"

PARTIE niveau4(PARTIE partie) {
    partie.niveau = initNiveau(4);
    partie.niveauActuel = 4;
    jouerNiveau(&partie);
    clearConsole();
    printf("%s", ANSI_YELLOW
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
    "      ###            BRAVO            ###      \n"
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
    int menuMinX = 5;
    int menuMinY = 60;
    gotoligcol(menuMinX, menuMinY + 2);
    printf("%s%s%s\n", ANSI_YELLOW, "FELICITATIONS ! Niveau reussi !", ANSI_RESET);
    gotoligcol(menuMinX + 2, menuMinY + 4);
    printf("%s%s", ANSI_BLUE, "Le mot de passe est : cochon");
    gotoligcol(menuMinX + 3, menuMinY - 10);
    printf("%s%s", ANSI_BLUE, "VICTOIRE !\n", ANSI_GREEN, ANSI_RESET);
    clock_t start,end;
    start = clock();
    end = clock();
    while((end-start) <= 5*CLOCKS_PER_SEC) {
        end = clock();
    }
    return partie;
}

