#include "menu.h"


void rObjectifs(){
    clearConsole();
    gotoligcol(5, 0);
    printf("LES OBJECTIFS :\n\n"
           "Pour remporter la partie, vous devez recuperer les 4 oiseaux disposes aux extremites du plateau.\n"
           "Pour ce faire, aller voir la rubrique DEPLACEMENTS des regles du jeu.\n"
           "Cependant, prenez garde aux obstacles pouvant se presenter devant vous :\n"
           "-La/Les balle(s) vous poursuivra(ont) tout au long du niveau et si elles vous touche vous predez une vie.\n"
           "Pour faire une action :\t\t\tE \n"
           "Pour fermer le jeu :\t\t\tX \n\n"
           "APPUYER SUR UNE TOUCHE POUR REVENIR AU MENU DES REGLES.");
    while(!_kbhit());
    if(_kbhit()){
        clearConsole();
        reglesDuJeu();
    }
}

void rTouches(){
    clearConsole();
    gotoligcol(5, 0);
    printf("LE DEPLACEMENT :\n\n"
           "Pour vous deplacer vers le haut : \tZ \n"
           "Pour vous deplacer vers la gauche :\tQ \n"
           "Pour vous deplacer vers la droite :\tD \n"
           "Pour vous deplacer vers le bas :\tS \n"
           "Pour faire une action :\t\t\tE \n"
           "Pour fermer le jeu :\t\t\tX\n"
           "Pour revenir au menu :\t\t\tM \n\n"
           "APPUYER SUR UNE TOUCHE POUR REVENIR AU MENU DES REGLES.");
    while(!_kbhit());
    if(_kbhit()){
        clearConsole();
        reglesDuJeu();
    }
}

void rBlocs(){
    clearConsole();
    gotoligcol(5, 0);
    printf("LES OBJECTIFS :\n\n"
           "Pour remporter la partie, vous devez recuperer les 4 oiseaux disposes aux extremites du plateau.\n"
           "Pour ce faire, aller voir la rubrique DEPLACEMENTS des regles du jeu.\n"
           "Cependant, prenez garde aux obstacles pouvant se presenter devant vous :\n"
           "-La/Les balle(s) vous poursuivra(ont) tout au long du niveau et si elles vous touche vous predez une vie.\n"
           "Pour faire une action :\t\t\tE \n"
           "Pour fermer le jeu :\t\t\tX \n\n"
           "APPUYER SUR UNE TOUCHE POUR REVENIR AU MENU DES REGLES.");
    while(!_kbhit());
    if(_kbhit()){
        clearConsole();
        reglesDuJeu();
    }
}


void rScore(){
    clearConsole();
    gotoligcol(5, 0);
    printf("LES OBJECTIFS :\n\n"
           "Pour remporter la partie, vous devez recuperer les 4 oiseaux disposes aux extremites du plateau.\n"
           "Pour ce faire, aller voir la rubrique DEPLACEMENTS des regles du jeu.\n"
           "Cependant, prenez garde aux obstacles pouvant se presenter devant vous :\n"
           "-La/Les balle(s) vous poursuivra(ont) tout au long du niveau et si elles vous touche vous predez une vie.\n"
           "Pour faire une action :\t\t\tE \n"
           "Pour fermer le jeu :\t\t\tX \n\n"
           "APPUYER SUR UNE TOUCHE POUR REVENIR AU MENU DES REGLES.");
    while(!_kbhit());
    if(_kbhit()){
        clearConsole();
        reglesDuJeu();
    }
}

void reglesDuJeu() {
    clearConsole();
    int reglesMinX = 5;
    int reglesMinY = 0;
    gotoligcol(reglesMinX + 2, reglesMinY);
    printf("%c", BALL);
    gotoligcol(reglesMinX, reglesMinY + 2);
    printf("Regles du Jeu :");
    gotoligcol(reglesMinX + 2, reglesMinY + 2);
    printf("Objectifs");
    gotoligcol(reglesMinX + 3, reglesMinY + 2);
    printf("Les Deplacements");
    gotoligcol(reglesMinX + 4, reglesMinY + 2);
    printf("Les Blocs");
    gotoligcol(reglesMinX + 5, reglesMinY + 2);
    printf("Le Score");
    gotoligcol(reglesMinX + 6, reglesMinY + 2);
    printf("Retour ");

    short Select = 0;
    char key;
    do {
        if (_kbhit()) {
            key = (char) getch();
            switch (key) {
                case 'z' :
                case 'Z' :
                    if(Select > 0) {
                        --Select;
                    }
                    break;
                case 's' :
                case 'S' :
                    if(Select < 4) {
                        ++Select;
                    }
                    break;
                case 'e' :
                case 'E' :
                    switch (Select) {
                        case 0 :
                            rObjectifs();
                            break;
                        case 1 :
                            rTouches();
                            break;
                        case 2 :
                            rBlocs();
                            break;
                        case 3 :
                            rScore();
                            break;
                        case 4 :
                            afficherMenu();
                            break;
                    }

            }

            switch (Select) {
                case 0 :
                    gotoligcol(reglesMinX + 2, reglesMinY);
                    printf("%c", BALL);
                    gotoligcol(reglesMinX + 3, reglesMinY);
                    printf("  ");
                    gotoligcol(0, 0);
                    break;
                case 1 :
                    gotoligcol(reglesMinX + 3, reglesMinY);
                    printf("%c", BALL);
                    gotoligcol(reglesMinX + 2, reglesMinY);
                    printf("  ");
                    gotoligcol(reglesMinX + 4, reglesMinY);
                    printf("  ");
                    gotoligcol(0, 0);
                    break;
                case 2:
                    gotoligcol(reglesMinX + 4, reglesMinY);
                    printf("%c", BALL);
                    gotoligcol(reglesMinX + 3, reglesMinY);
                    printf("  ");
                    gotoligcol(reglesMinX + 5, reglesMinY);
                    printf("  ");
                    gotoligcol(0, 0);
                    break;
                case 3 :
                    gotoligcol(reglesMinX + 5, reglesMinY);
                    printf("%c", BALL);
                    gotoligcol(reglesMinX + 4, reglesMinY);
                    printf("  ");
                    gotoligcol(reglesMinX + 6, reglesMinY);
                    printf("  ");
                    gotoligcol(0, 0);
                    break;
                case 4 :
                    gotoligcol(reglesMinX + 6, reglesMinY);
                    printf("%c", BALL);
                    gotoligcol(reglesMinX + 5, reglesMinY);
                    printf("  ");
                    gotoligcol(reglesMinX + 7, reglesMinY);
                    printf("  ");
                    gotoligcol(0, 0);
                    break;
            }
        }
    } while (1);
}
