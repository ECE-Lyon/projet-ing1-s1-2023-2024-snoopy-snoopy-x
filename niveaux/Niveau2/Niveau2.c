#include "Niveau2.h"

PARTIE niveau2(PARTIE partie) {
    partie.niveau = initNiveau(2);
    partie.niveauActuel = 2;
    jouerNiveau(&partie);
    partie.score[1] = partie.niveau.tempsRestant;
    clearConsole();
    printf("%s%s", ANSI_MAGENTA
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
                   "      ###            BRAVO             ###      \n"
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
    printf("Le mot de passe est : chat");
    clock_t start,end;
    start = clock();
    end = clock();
    while((end-start) <= 3*CLOCKS_PER_SEC) {
        end = clock();
    }
    return partie;
}