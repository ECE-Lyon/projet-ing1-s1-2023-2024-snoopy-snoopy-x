
#include "mdp.h"

void motDePasse() {
    clearConsole();
    gotoligcol(5, 0);
    char chien, chat, cheval, cochon;
    char mdp[20];
    gotoligcol(25,83);
    printf("SAISISSEZ 'E' COMME MOT DE PASSE POUR RETOURNER AU MENU");
    gotoligcol(6,0);
    printf("%s%s", ANSI_RED
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
    gotoligcol(20,90);
    printf("%s%s", ANSI_BLUE, "Saisissez un mot de passe valide : ");
    scanf("%s", &mdp);

    while (!_kbhit());
    if (_kbhit()) {
        clearConsole();;
        if (strcmp("chien", mdp)) {

        }
        if (strcmp("chat", mdp)) {

        }
        if (strcmp("cheval", mdp)) {

        }
        if (strcmp("cochon", mdp)) {

        }
        if (strcmp("e", mdp)){
            afficherMenu();
        }
        if (strcmp("E", mdp)){
            afficherMenu();
        }

    }
}