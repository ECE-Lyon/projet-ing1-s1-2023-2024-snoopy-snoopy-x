
#include "mdp.h"

void motDePasse() {
    clearConsole();
    gotoligcol(5, 0);
    char chien[] = {"chien"};
    char chat[] = {"chat"};
    char cheval[] = {"cheval"};
    char cochon[] = {"cochon"};
    char mdp[10];
    gotoligcol(25, 83);
    printf("SAISISSEZ 'E' COMME MOT DE PASSE POUR RETOURNER AU MENU");
    gotoligcol(6, 0);
    printf("%s", ANSI_RED
                 "                                  ##                                  \n"
                 "                                  ###                                 \n"
                 "                                   ###########                        \n"
                 "                                           ####                       \n"
                 "                                             ##                       \n"
                 "                                           ####                       \n"
                 "                                   ###########                        \n"
                 "                                  ####                                \n"
                 "                                #######                               \n"
                 "                               ###  ###                               \n"
                 "               ########################################               \n"
                 "          ##################################################          \n"
                 "       ######                #####  #####                ######       \n"
                 "      ####    #######          ########                     ####      \n"
                 "    ####   #############                           #####      ####    \n"
                 "   ####  ####         ####                        #######      ####   \n"
                 "   ### ####   #######   ####                      #######       ###   \n"
                 "  ###  ### ###### ###### ###                  ###  #####  ###    ###  \n"
                 "  ### ###  ###### ######  ###               #######     #######  ###  \n"
                 "  ### ###  ##         ##  ### #####  #####  ### ###     ### #### ###  \n"
                 "  ### #### ###### ######  ###               #######      ######  ###  \n"
                 "  ###  ###    ### ###    ###                       ######        ###  \n"
                 "   ###  ####  #######  ####                       ### ###       ###   \n"
                 "    ###  #####       #####                        #######      ###    \n"
                 "     ###   #############                            ###       ###     \n"
                 "      #####                                                #####      \n"
                 "        ######                                          ######        \n"
                 "           ################################################           \n");
    gotoligcol(20, 90);
    printf("%s%s", ANSI_BLUE, "Saisissez un mot de passe valide : ");
    scanf("%s", mdp);
    PARTIE partie;
    if (!strcmp("chien", mdp)) {
        PARTIE partie = niveau1();
    }
    if (!strcmp("chat", mdp)) {
        partie.niveauActuel = 2;
        niveau2(partie);
    }
    if (!strcmp("cheval", mdp)) {
        partie.niveauActuel = 3;
        niveau3(partie);
    }
    if (!strcmp("cochon", mdp)) {
        printf("Niveau non disponible");
    }
    if (!strcmp("e", mdp) || !strcmp("E", mdp)) {
        afficherMenu();
    }
}
