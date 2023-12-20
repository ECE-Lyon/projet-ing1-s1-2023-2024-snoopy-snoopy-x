#include "menu.h"


void quitter(){
    exit(0);
}

void afficherMenu() {
    clearConsole();
    printf("\33[?25l");
    int MenuminX = 6;
    int MenuminY = 40;
    gotoligcol(MenuminX + 2, MenuminY + 8);
    printf("%c", BALL);

    gotoligcol(MenuminX, MenuminY);
    printf("%s%s%s\n", ANSI_YELLOW, "Bienvenue dans la revanche de Snoopy.", ANSI_RESET);
    gotoligcol(MenuminX + 2, MenuminY + 10);
    printf("%s%s", ANSI_RED, "1.Regles du jeu");
    gotoligcol(MenuminX + 3, MenuminY + 7);
    printf("%s%s", ANSI_BLUE, "2.Lancer un nouveau Jeu\n", ANSI_GREEN, ANSI_RESET);
    gotoligcol(MenuminX + 4, MenuminY + 8);
    printf("%s%s", ANSI_RED, " 3.Charger une partie ", ANSI_GREEN, ANSI_RESET);
    gotoligcol(MenuminX + 5, MenuminY + 11);
    printf("%s%s", ANSI_BLUE,"4.Mot de passe"ANSI_GREEN, ANSI_RESET);
    gotoligcol(MenuminX + 6, MenuminY + 13);
    printf("%s%s", ANSI_RED,"5. Scores",ANSI_GREEN, ANSI_RESET);
    gotoligcol(MenuminX + 7, MenuminY + 13);
    printf("%s%s", ANSI_BLUE,"6. Quitter ");

    short Select = 0;
    char key;
    do {
        if (_kbhit()) {
            key = (char) getch();
            switch (key) {
                case 'Z' :
                case 'z' :
                    if (Select > 0) {
                        Select--;
                    }
                    break;
                case 's' :
                case 'S' :
                    if (Select < 6) {
                        Select++;
                    }
                    break;
                case 'e' :
                case 'E' :
                    switch (Select) {
                        case 0 :
                            reglesDuJeu();
                            break;
                        case 1 : {
                            PARTIE partie = niveau1();
                            PARTIE partie1 = niveau2(partie);
                            PARTIE partie2 = niveau3(partie1);
                            int score = 0;
                            for(int i = 0; i < 3; i++) {
                                score += partie2.score[i];
                            }
                            score *= 100 * partie2.niveau.perso.vies;
                            coupe(score);
                            afficherMenu();
                            break;
                        }
                        case 2 :{
                            PARTIE partie = chargerNiveau(selectFichier());
                            if(partie.niveauActuel == -1) {
                                afficherMenu();
                                break;
                            }
                            jouerNiveau(&partie);
                            switch(partie.niveauActuel) {
                                case 2 : {
                                    PARTIE partie1 = niveau2(partie);
                                    PARTIE partie2 = niveau3(partie1);
                                    int score = 0;
                                    for(int i = 0; i < 3; i++) {
                                        score += partie2.score[i];
                                    }
                                    score *= 100 * partie2.niveau.perso.vies;
                                    coupe(score);
                                    afficherMenu();
                                } break;
                                case 3 : {
                                    PARTIE partie2 = niveau3(partie);
                                    int score = 0;
                                    for(int i = 0; i < 3; i++) {
                                        score += partie2.score[i];
                                    }
                                    score *= 100 * partie2.niveau.perso.vies;
                                    coupe(score);
                                    afficherMenu();
                                } break;
                            }
                        }

                            break;
                        case 3 :
                            motDePasse();
                            afficherMenu();
                            break;
                        case 4 :
                            //TODO: highScores();
                            break;
                        case 5 :
                            quitter();
                            break;
                    }
            }
            switch (Select) {
                case 0 :
                    gotoligcol(MenuminX + 2, MenuminY + 8);
                    printf("%s%c",ANSI_YELLOW, BALL);
                    gotoligcol(MenuminX + 3, MenuminY + 5);
                    printf("  ");
                    gotoligcol(0,0);
                    break;
                case 1 :
                    gotoligcol(MenuminX + 3, MenuminY + 5);
                    printf("%s%c",ANSI_YELLOW, BALL);
                    gotoligcol(MenuminX + 2, MenuminY + 8);
                    printf("  ");
                    gotoligcol(MenuminX + 4, MenuminY + 6);
                    printf("  ");
                    gotoligcol(0,0);
                    break;
                case 2:
                    gotoligcol(MenuminX + 4, MenuminY + 6);
                    printf("%s%c",ANSI_YELLOW, BALL);
                    gotoligcol(MenuminX + 3, MenuminY + 5);
                    printf("  ");
                    gotoligcol(MenuminX + 5, MenuminY + 9);
                    printf("  ");
                    gotoligcol(0,0);
                    break;
                case 3 :
                    gotoligcol(MenuminX + 5, MenuminY + 9);
                    printf("%s%c", ANSI_YELLOW,BALL);
                    gotoligcol(MenuminX + 4, MenuminY + 6);
                    printf("  ");
                    gotoligcol(MenuminX + 6, MenuminY + 11);
                    printf("  ");
                    gotoligcol(0,0);
                    break;
                case 4 :
                    gotoligcol(MenuminX + 6, MenuminY + 11 );
                    printf("%s%c", ANSI_YELLOW,BALL);
                    gotoligcol(MenuminX + 5, MenuminY + 9);
                    printf("  ");
                    gotoligcol(MenuminX + 7, MenuminY + 11);
                    printf("  ");
                    gotoligcol(0,0);
                    break;
                case 5 :
                    gotoligcol(MenuminX + 7, MenuminY + 11);
                    printf("%s%c",ANSI_YELLOW, BALL);
                    gotoligcol(MenuminX + 6, MenuminY + 11);
                    printf("  ");
                    gotoligcol(0,0);
                    break;
            }
            if(key == 'e' || key == 'E'){

            }
        }


    }while (1);
}

void coupe(int score) {
    clearConsole();
    printf("                                                                                \n"
           "                                                                                 \n"
           "                                                                                 \n"
           "                                 <)<<)))))))))))                                 \n"
           "                    )))<   <))))))))))))))))))))))))<)   )<<)                    \n"
           "                  ))))))))<)))))))))))))))))))))))))))))))))))<                  \n"
           "           <)    <)<     <))))))))))))))))))))))))))))))     )))    <)           \n"
           "          <)<   <))      <)))))))))))VICTOIRE))))))))))      ))<   ))<          \n"
           "         ))))<   )<        <)))))))))))))))))))))))))<        )<   <))))         \n"
           "      )< )))))    <<       ))))))))))))))))))))))))))<       <)    <)))< )<      \n"
           "      <))<<)))<))  <))<    )))))))))))))))))))))))))))    ))<)  <))<))<))))      \n"
           "      ))))))))))<     <)<)  ))))))))))))))))))))))))<  <<)<)    <))))))))))      \n"
           "       )))))))))<)      )))))))))))))))))))))))))))))))<<      )<))))))))<       \n"
           "      <)<)))))))))      ))<))))))))))))))))))))))))))< )<)     <))))))))<)<      \n"
           "      ))<)))))))))     ))) <)))))))))))))))))))))))<)) <)<     ))))))))))))      \n"
           "       ))))))))))<       <))  ))))))))))))))))))))<  )))       <))))))))))       \n"
           "        ))))))))))))           <)))))))))))))))))<           )<<))))))))<        \n"
           "        )<<))))))))<<           ))))))))))))))))<           )<))<))))<)))        \n"
           "         <)))<)<)))))             <)))))))))))<             ))))<)<<)))<         \n"
           "          ))))))))))))< )          <))))))))))          < )))))))))))))          \n"
           "          <<)<)))))))))))<           )))))))            ))))))))))))<<)          \n"
           "           <)))))))))<)))))           <))))           <))))<))))))))))           \n"
           "            <)))))))))))))<)<<        ))))<        <))<))))))))))))))            \n"
           "              ))<)<)))))))))))<)       )))<      )<)))))))))))<<<<)              \n"
           "              <)))))))))))))))))<     <)))<     <))))<))))))))))))<              \n"
           "                )<)))))))))))))))<    )))))    ))))))))))))))))))<               \n"
           "                    <))))))))))))<    )))))    <))))))))))))<                    \n"
           "                    <)<)<)))))))))<  ))))))<  )<<)))))))<))))                    \n"
           "                     )))))))))<)    )))))))))    <<<))))))<)                     \n"
           "                                   )))))))))))                                   \n"
           "                                   ))))))))))<                                   \n"
           "                                  )))))))))))<)                                  \n"
           "                               )<)))))))))))))))))                               \n"
           "                               <))))))))))))))))))                               \n"
           "                               ))))))))))))))))))<                               \n"
           "                                ))<)))))))))))<<)                                \n"
           "                                      <<<<<                                      \n"
           "                                                                                 \n");
    printf("\n\nScore : %d", score);
    clock_t start,end;
    start = clock();
    end = clock();
    while((end - start) <= 2*CLOCKS_PER_SEC) {
        end = clock();
    }
    while (!_kbhit());
}


void menuEntreNiveaux(){

}