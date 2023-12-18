#include "Oiseaux.h"

void initOiseaux(OISEAUX *oiseaux) {
    oiseaux[0].co.X = convCoX(0);
    oiseaux[0].co.Y = convCoY(0);
    oiseaux[0].recup = 0;

    oiseaux[1].co.X = convCoX(9);
    oiseaux[1].co.Y = convCoY(0);
    oiseaux[1].recup = 0;

    oiseaux[2].co.X = convCoX(0);
    oiseaux[2].co.Y = convCoY(9);
    oiseaux[2].recup = 0;

    oiseaux[3].co.X = convCoX(9);
    oiseaux[3].co.Y = convCoY(9);
    oiseaux[3].recup = 0;
}

void afficherOiseaux(OISEAUX *oiseaux) {
    for (int i = 0; i < 4; i++) {
        if (!oiseaux[i].recup) {
            gotoligcol(oiseaux[i].co.X, oiseaux[i].co.Y);
            printf("%c", CHAR_OISEAUX);
        }
    }
}

void recupOiseaux(OISEAUX *oiseaux, PERSONNAGE perso) {
    for (int i = 0; i < 4; i++) {
        if (perso.co.X == oiseaux[i].co.X && perso.co.Y == oiseaux[i].co.Y){
            oiseaux[i].recup = 1;
        }
    }
}

void oiseauxRecup(OISEAUX *oiseaux, PERSONNAGE perso) {
    int scoreOiseaux = 0;
    for (int i = 0; i < 4; i++) {
        if (oiseaux[i].recup){
            scoreOiseaux = scoreOiseaux+1;
        }
    }
    if(scoreOiseaux==4){
        clearConsole();
        gotoligcol(14,100);
        printf("Le mote de passe est : \n\n");
        gotoligcol(16,102);
        printf("Niveau suivant\n");
        gotoligcol(18,102);
        printf( "Retour au menu \n");
        gotoligcol(20,102);
        printf( "Saisir un mot de passe \n");
        gotoligcol(22,102);
        printf("Quitter le jeu");
        gotoligcol(0,0);
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
        short Select = 0;
        char key;
        do {
            if (_kbhit()) {
                key = (char) getch();
                switch (key) {
                    case 'z' :
                    case 'Z' :
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
                                printf("Le mot de passe est : ");
                                break;
                            case 1 :
                                //niveau1();
                                break;
                            case 2 :
                                //TODO: chargement();
                                break;
                            case 3 :
                                //motDePasse();
                                //TODO: password():
                                break;
                            case 4 :
                                //TODO: highScores();
                                break;
                            case 5 :
                                //quitter();
                                break;
                        }
                }
                switch (Select) {
                    case 0 :
                        gotoligcol( 16,  98);
                        printf("%c", BALL);
                        gotoligcol( 16+ 2,  98);
                        printf("  ");
                        gotoligcol(0,0);
                        break;
                    case 1 :
                        gotoligcol( 18,  98);
                        printf("%c", BALL);
                        gotoligcol( 18+ 2,  98);
                        printf("  ");
                        gotoligcol( 18-2,  98);
                        printf("  ");
                        gotoligcol(0,0);
                        break;
                    case 2:
                        gotoligcol( 20,  98);
                        printf("%c", BALL);
                        gotoligcol( 20+2,  98);
                        printf("  ");
                        gotoligcol( 20-2,  98);
                        printf("  ");
                        gotoligcol(0,0);
                        break;
                    case 3 :
                        gotoligcol( 22,  98);
                        printf("%c", BALL);
                        gotoligcol( 22+2,  98);
                        printf("  ");
                        gotoligcol( 22-2,  98);
                        printf("  ");
                        gotoligcol(0,0);
                        break;
                    case 4 :
                        gotoligcol( + 24,  98 );
                        printf("%c", BALL);
                        gotoligcol( + 24+2,  98);
                        printf("  ");
                        gotoligcol( + 24-2,  + 98);
                        printf("  ");
                        gotoligcol(0,0);
                        break;

                }
                if(key == 'e' || key == 'E'){

                }
            }


        }while (1);
    }
        while(1){
            if(_kbhit()) break;}

    }
