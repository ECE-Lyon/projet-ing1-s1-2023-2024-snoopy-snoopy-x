#include "menu.h"

void rObjectifs(){
    clearConsole();
    gotoligcol(5, 0);
    printf("LES OBJECTIFS :\n\n"
           "Pour remporter la partie, vous devez recuperer les 4 oiseaux disposes aux extremites du plateau.\n"
           "Pour ce faire, aller voir la rubrique DEPLACEMENTS des regles du jeu.\n"
           "Cependant, prenez garde aux obstacles pouvant se presenter devant vous :\n"
           "-La/Les balle(s) vous poursuivra(ont) tout au long du niveau1 et si elles vous touche vous predez une vie.\n"
           " \n"
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
    printf("LES TOUCHES :\n\n"
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
    printf("LES BLOCS :\n\n"
           "Il y a plusieurs blocs disponibles differents : \n"
           " -Les blocs que vous pourrez casser pour vous frayez un chemin  : %c\n"
           " -Les blocs que vous pourrez deplacer et qui seront immobiles : %c \n"
           " -Les blocs pieges qui vous feront directement perdre la partie : %c\n "
           " \n"
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
    printf("LE SCORE :\n\n"
           "Le score sera calcule en fonction du temps mis pour realiser les niveaux.\n"
           "Plus vous serez rapide, plus il sera eleve. \n"
           "Le score sera cumule sur les differents niveaux.\n"
           " \n"
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
    gotoligcol(reglesMinX +2, reglesMinY);
    printf("%c", BALL);
    gotoligcol(reglesMinX, reglesMinY + 2);
    printf("Regles du Jeu :");
    gotoligcol(reglesMinX + 2, reglesMinY + 2);
    printf("- Objectifs");
    gotoligcol(reglesMinX + 3, reglesMinY + 2);
    printf("- Les Touches");
    gotoligcol(reglesMinX + 4, reglesMinY + 2);
    printf("- Les Blocs");
    gotoligcol(reglesMinX + 5, reglesMinY + 2);
    printf("- Le Score");
    gotoligcol(reglesMinX + 6, reglesMinY + 2);
    printf("- Retour ");

    gotoligcol(reglesMinX , reglesMinY+80);
    printf("         :@\n");
    gotoligcol(reglesMinX + 1, reglesMinY+80);
    printf("     @@@%.  %@@@@          :\n");
    gotoligcol(reglesMinX + 2, reglesMinY+80);
    printf("    ~@@            @@@@@@@<         #@@@@>\n");
    gotoligcol(reglesMinX + 3, reglesMinY+80);
    printf("    @@                                 -@@@\n");
    gotoligcol(reglesMinX + 4, reglesMinY+80);
    printf("   @@                                    @\n");
    gotoligcol(reglesMinX + 5, reglesMinY+80);
    printf("  @@                  @:                 .@<@@@@@@\n");
    gotoligcol(reglesMinX + 6, reglesMinY+80);
    printf(" @@                 @@                    #@@@     @\n");
    gotoligcol(reglesMinX + 7, reglesMinY+80);
    printf("@@                                         [    @@@@\n");
    gotoligcol(reglesMinX + 8, reglesMinY+80);
    printf("@~                                        @\n");
    gotoligcol(reglesMinX + 9, reglesMinY+80);
    printf("@@  *@@@  @                               @\n");
    gotoligcol(reglesMinX + 10, reglesMinY+80);
    printf("@]  @@@@@[ @                            @~\n");
    gotoligcol(reglesMinX + 11, reglesMinY+80);
    printf("@  @@@@@@@+ @                        @@\n");
    gotoligcol(reglesMinX + 12, reglesMinY+80);
    printf("@  @@@@@@@@ %                    ~@#\n");
    gotoligcol(reglesMinX + 13, reglesMinY+80);
    printf("@  @@@@@@@@ :                 (@\n");
    gotoligcol(reglesMinX + 14, reglesMinY+80);
    printf("@) %@@@@@@@*-:              @@\n");
    gotoligcol(reglesMinX + 15, reglesMinY+80);
    printf("@  %@@@@@@^@@            {@\n");
    gotoligcol(reglesMinX + 16, reglesMinY+80);
    printf("    @^  {@@@ (>   #@       @\n");
    gotoligcol(reglesMinX + 17, reglesMinY+80);
    printf("        @@@@@@@       @     #~\n");
    gotoligcol(reglesMinX +18, reglesMinY+80);
    printf("        @     @\n");
    gotoligcol(reglesMinX + 19, reglesMinY+80);
    printf("        @@@@* <+\n");
    gotoligcol(reglesMinX + 20, reglesMinY+80);
    printf("        @      #@\n");
    gotoligcol(reglesMinX + 21, reglesMinY+80);
    printf("        @        @\n");
    gotoligcol(reglesMinX + 22, reglesMinY+80);
    printf( "        %@         @\n");
    gotoligcol(reglesMinX + 23, reglesMinY+80);
    printf( "        @ @         @>\n");
    gotoligcol(reglesMinX + 24, reglesMinY+80);
    printf( "        @  @     @     @\n");
    gotoligcol(reglesMinX + 25, reglesMinY+80);
    printf( "        @  @      @     @\n");
    gotoligcol(reglesMinX + 26, reglesMinY+80);
    printf( "        @  @       @     @\n");
    gotoligcol(reglesMinX + 27, reglesMinY+80);
    printf( "        @   @      =<     @\n");
    gotoligcol(reglesMinX + 28, reglesMinY+69);
    printf( "        -@@@@][%@@@  @       @     {=\n");
    gotoligcol(reglesMinX + 29, reglesMinY+67);
    printf( "        ~@          @- @@     @      @\n");
    gotoligcol(reglesMinX + 30, reglesMinY+69);
    printf( "        @@@@@@@@@@@  @@(@ @     -@\n");
    gotoligcol(reglesMinX + 31, reglesMinY+80);
    printf( "        =@         @<\n");
    gotoligcol(reglesMinX + 32, reglesMinY+80);
    printf( "        @        %\n");
    gotoligcol(reglesMinX + 33, reglesMinY+80);
    printf(  "        @        {@@@%\n");
    gotoligcol(reglesMinX + 34, reglesMinY+80);
    printf( "            @        %@@@)   @@+\n");
    gotoligcol(reglesMinX + 35, reglesMinY+80);
    printf( "            @@                 [@  @\n");
    gotoligcol(reglesMinX + 36, reglesMinY+80);
    printf( "            @(                     @  @\n");
    gotoligcol(reglesMinX + 37, reglesMinY+80);
    printf( "            @               @  @   @  %.\n");
    gotoligcol(reglesMinX + 38, reglesMinY+80);
    printf( "            ~*  )((%@@@@@@@@@@@@@@@@-\n");



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
                    gotoligcol(reglesMinX +3, reglesMinY);
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
