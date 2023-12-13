#include "personnage.h"
#include "balle.h"


void initPersonnage(PERSONNAGE *perso, int X, int Y){
    perso->vies = 3;
    perso->co.X = X;
    perso->co.Y = Y;
}


void initOiseaux(OISEAUX *oiseaux){
    oiseaux->recup = 0;
    oiseaux->co.X = 19;
    oiseaux->co.Y = 49;
}


void deplacementPerso(PERSONNAGE *perso, char input){
    switch (input) {
        case 'd' :
        case 'D' :
            if (perso->co.Y < MAXY) {
                cacherCharPerso(perso);
                perso->co.Y += 4;
                gotoligcol(perso->co.X, perso->co.Y);
                printf("O");
            }
            break;
        case 'q' :
        case 'Q' :
            if (perso->co.Y > MINY) {
                cacherCharPerso(perso);
                perso->co.Y -= 4;
                gotoligcol(perso->co.X, perso->co.Y);
                printf("O");
            }
            break;
        case 's' :
        case 'S' :
            if (perso->co.X < MAXX) {
                cacherCharPerso(perso);
                perso->co.X += 2;
                gotoligcol(perso->co.X, perso->co.Y);
                printf("O");
            }
            break;
        case 'z' :
        case 'Z' :
            if (perso->co.X > MINX) {
                cacherCharPerso(perso);
                perso->co.X -= 2;
                gotoligcol(perso->co.X, perso->co.Y);
                printf("O");
            }
            break;
        default :
            break;
    }
}

void cacherCharPerso(PERSONNAGE *perso){
    gotoligcol(perso->co.X, perso->co.Y),
    printf(" ");
}

    void initvictoireoudefaite(PERSONNAGE *snoopy, OISEAUX *oiseaux, BALLE *balle){
        static int oiseauxTouches = 0;
        // Vérifier si Snoopy touche un oiseau, sachant qu ils sont 4
        for (int i = 0; i < 4; i++) {
            if (snoopy->co.X == oiseaux[i].co.X && snoopy->co.Y == oiseaux[i].co.Y) {
                oiseauxTouches++;
                if (oiseauxTouches == 4) {
                    printf("vous avez gagne");  // Snoopy a touché tous les oiseaux et gagne/ il a reussi
                }
            }
        }

        // Vérifier si la balle touche Snoopy
        if (balle->co.X == snoopy->co.X && balle->co.Y == snoopy->co.Y) {
            snoopy->vies--;  // Snoopy perd une vie     // prends en boucles les coordonnes de snoopy et de la balle et enleve une vie a snoopy a chaque fois que leurs chemins se croisent
            if (snoopy->vies <= 0) {
                printf("vous avez perdu");   // Snoopy perd la partie
            }
        }


    }

