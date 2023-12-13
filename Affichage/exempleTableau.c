#include "../Partie/partie.h"
#include "../couleursPrintf/couleursPrintf.h"


int main() {
    NIVEAU niveau1 = initNiveau(1);
    printf("tpsBalle %d\n", niveau1.tpsBalle);
    printf("coDepart %hd %hd\n", niveau1.perso.co.X, niveau1.perso.co.Y);
    printf("nbBalles %hd :\n", niveau1.nbBalles);
    for(int i = 0; i < niveau1.nbBalles; i++) {
        printf("co balle %d : %hd %hd. dir : %hd\n", i, niveau1.tabBalles[i].co.X, niveau1.tabBalles[i].co.Y, niveau1.tabBalles[i].direction);
    }

    while(1);
}