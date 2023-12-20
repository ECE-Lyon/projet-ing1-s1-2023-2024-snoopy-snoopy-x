#include "Niveau3.h"

PARTIE niveau3(PARTIE partie) {
    partie.niveau = initNiveau(3);
    partie.niveauActuel = 3;
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
    printf("%s%s", ANSI_BLUE, "Le mot de passe est : chien");
    gotoligcol(menuMinX + 3, menuMinY - 3);
    printf("%s%s", ANSI_BLUE, "Lancecement du niveau suivant dans 5 secondes !\n", ANSI_GREEN, ANSI_RESET);
    clock_t start,end;
    start = clock();
    end = clock();
    while((end-start) <= 5*CLOCKS_PER_SEC) {
        end = clock();
    }
    return partie;
}