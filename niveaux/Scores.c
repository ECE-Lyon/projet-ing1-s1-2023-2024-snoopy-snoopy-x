#include "Scores.h"

void gameOver(){
    clearConsole();
    gotoligcol( 2, 10);
    printf("GAME OVER\n\n"
           "APPUYER SUR UNE TOUCHE POUR REVENIR AU MENU.");
    if(_kbhit()){
        clearConsole();
        afficherMenu();
    }
    while(1);
}

