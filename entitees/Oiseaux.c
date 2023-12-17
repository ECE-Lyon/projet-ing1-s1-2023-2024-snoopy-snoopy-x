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
        if (!oiseaux->recup) {
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