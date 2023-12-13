#include "consoleDebug.h"

/*
void printDateDansLogs(FILE* fichierLogs){
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char s[64];
    size_t ret = strftime(s, sizeof(s), "%c", tm);
    assert(ret);
    fprintf(fichierLogs, "%s\n", s);
}

void consoleDebug(FILE* fichierLogs, PERSONNAGE* perso, BALLE* balle){
    fprintf(fichierLogs, "\n");
    printDateDansLogs(fichierLogs);
    gotoligcol(21, 3);
    char phrase[20];
    scanf("%s", phrase);
    gotoligcol(21, 3);
    for(int i = 0; i < 50; i++){
        printf(" ");
    }
    fprintf(fichierLogs, "Input : %s\n", phrase);
    char commandeFermerConsole[5] = {"shut"};
    if(!strcmp(phrase, commandeFermerConsole)){
        fprintf(fichierLogs, "Commande : fermerConsole\n");
        clearConsole();
        fflush(fichierLogs);
        return;
    }

    char commandePause[6] = {"pause"};
    if(!strcmp(phrase, commandePause)){
        fprintf(fichierLogs, "Commande : pause\n");
        consoleDebug(fichierLogs, perso, balle);
        fflush(fichierLogs);
    }

    char commandeDonnerCo[9] = {"donnerCo"};
    if(!strcmp(phrase, commandeDonnerCo)){
        fprintf(fichierLogs, "Commande : donnerCo -> val : X = %d, Y = %d", perso->co.X, perso->co.Y);
        fflush(fichierLogs);
        return;
    }

    char commandeClearLogs[10] = {"clearLogs"};
    if(!strcmp(phrase, commandeClearLogs)){
        fclose(fichierLogs);
        fichierLogs = fopen("../consoleDebug/logs.log", "w");
        fclose(fichierLogs);
        fichierLogs = fopen("../consoleDebug/logs.log", "a");
        fprintf(fichierLogs, "Cleared on : ");
        printDateDansLogs(fichierLogs);
        printf("\n\n");
        fflush(fichierLogs);
        return;
    }

    char commandeSiu[4] = {"siu"};
    if(!strcmp(phrase, commandeSiu)){
        fprintf(fichierLogs, "Commande : SIUUUUUUUU\n");
        clearConsole();
        gotoligcol(0, 0);
        printf("\n"
               "\n"
               "                                                               \n"
               "                                                               \n"
               "  .--.--.      ,---,                                           \n"
               " /  /    '. ,`--.' |         ,--,          ,--,          ,--,  \n"
               "|  :  /`. / |   :  :       ,'_ /|        ,'_ /|        ,'_ /|  \n"
               ";  |  |--`  :   |  '  .--. |  | :   .--. |  | :   .--. |  | :  \n"
               "|  :  ;_    |   :  |,'_ /| :  . | ,'_ /| :  . | ,'_ /| :  . |  \n"
               " \\  \\    `. '   '  ;|  ' | |  . . |  ' | |  . . |  ' | |  . .  \n"
               "  `----.   \\|   |  ||  | ' |  | | |  | ' |  | | |  | ' |  | |  \n"
               "  __ \\  \\  |'   :  ;:  | | :  ' ; :  | | :  ' ; :  | | :  ' ;  \n"
               " /  /`--'  /|   |  '|  ; ' |  | ' |  ; ' |  | ' |  ; ' |  | '  \n"
               "'--'.     / '   :  |:  | : ;  ; | :  | : ;  ; | :  | : ;  ; |  \n"
               "  `--'---'  ;   |.' '  :  `--'   \\'  :  `--'   \\'  :  `--'   \\ \n"
               "            '---'   :  ,      .-./:  ,      .-./:  ,      .-./ \n"
               "                     `--`----'     `--`----'     `--`----'     \n"
               "                                                               \n"
               "");
        consoleDebug(fichierLogs, perso, balle);
        fflush(fichierLogs);
        return;
    }

    char commandeKill[5] = {"kill"};
    if(!strcmp(phrase, commandeKill)){
        fprintf(fichierLogs, "Commande : kill\n");
        debugFinJeu(fichierLogs, perso, balle);
        fflush(fichierLogs);
        assert(0);
    }
    clearConsole();
}


void debugFinJeu(FILE* fichierLogs, PERSONNAGE* perso, BALLE* balle){
    fprintf(fichierLogs, "\nFin du jeu : ");
    printDateDansLogs(fichierLogs);
    fprintf(fichierLogs, "Personnage : \n"
                         "\t- co X : %d, co Y : %d\n"
                         "\t- Pv : %d\n"
                         "Balle : \n"
                         "\t- Co X : %d, co Y : %d\n"
                         "\t- Direction : %d\n\n",
            perso->co.X, perso->co.Y, perso->vies, balle->co.X, balle->co.X, balle-> direction);
}
*/