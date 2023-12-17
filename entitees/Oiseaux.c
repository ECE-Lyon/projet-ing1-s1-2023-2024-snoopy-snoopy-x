#include "Oiseaux.h"

void initOiseaux(OISEAUX *oiseaux) {
    oiseaux->recup = 0;
    oiseaux->co.X = 19;
    oiseaux->co.Y = 49;
}
void victoireDefaite(PERSONNAGE *snoopy, OISEAUX *oiseaux) {
    int oiseauxTouches = 0;
    // Vérifier si Snoopy touche un oiseau, sachant qu ils sont 4
    for (int i = 0; i < 4; i++) {
        if (snoopy->co.X == oiseaux[i].co.X && snoopy->co.Y == oiseaux[i].co.Y) {
            oiseauxTouches++;
            if (oiseauxTouches == 4) {
                printf("vous avez gagne");  // Snoopy a touché tous les oiseaux et gagne/ il a reussi
            }
        }
    }
}
void oiseaux(){
    int TableauminX = 6;
    int TableauminY = 70;
    gotoligcol(TableauminX+1,TableauminY+3);
    printf("%c", CHAR_OISEAUX);
    gotoligcol(TableauminX+1,TableauminY+39);
    printf("%c", CHAR_OISEAUX);
    gotoligcol(TableauminX+19,TableauminY+3);
    printf("%c", CHAR_OISEAUX);
    gotoligcol(TableauminX+19,TableauminY+39);
    printf("%c", CHAR_OISEAUX);
}