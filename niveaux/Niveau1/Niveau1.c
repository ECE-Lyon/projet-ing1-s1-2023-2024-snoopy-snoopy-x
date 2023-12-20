#include "Niveau1.h"


PARTIE niveau1() {
    PARTIE partie;
    partie.niveau = initNiveau(1);
    partie.niveauActuel = 1;
    jouerNiveau(&partie);
    clearConsole();
    printf("%s%s", ANSI_CYAN
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
    gotoligcol(15,50);
printf("Le mot de passe est : chien");
clock_t start,end;
   start = clock();
    end = clock();
    while((end-start) <= 3*CLOCKS_PER_SEC) {
        end = clock();
    }
    return partie;
}