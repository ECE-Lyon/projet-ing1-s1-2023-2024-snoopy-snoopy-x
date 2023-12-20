#include "Niveau3.h"

PARTIE niveau3(PARTIE partie) {
    partie.niveau = initNiveau(3);
    partie.niveauActuel = 3;
    jouerNiveau(&partie);
    partie.score[2] = partie.niveau.tempsRestant;
    clearConsole();
    printf("%s%s", ANSI_BLUE
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
    printf("Le mot de passe est : cheval");
    clock_t start,end;
    start = clock();
    end = clock();
    while((end-start) <= 3*CLOCKS_PER_SEC) {
        end = clock();
    }
    return partie;
}