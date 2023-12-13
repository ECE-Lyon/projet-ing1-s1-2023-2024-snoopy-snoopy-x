#include "personnage.h"



void initPersonnage(PERSONNAGE *perso, int X, int Y) {
    perso->vies = 3;
    perso->co = convCo(X, Y);
}


void initOiseaux(OISEAUX *oiseaux) {
    oiseaux->recup = 0;
    oiseaux->co.X = 19;
    oiseaux->co.Y = 49;
}


void deplacementPerso(PERSONNAGE *perso, char input, BLOC blocs[], int nbBlocs) {
    switch (input) {
        case 'd' :
        case 'D' :
            if (perso->co.Y < MAXY && !collisionBlocs(perso->co.X, perso->co.Y + 4, blocs, nbBlocs)) {
                cacherCharPerso(perso);
                perso->co.Y += 4;
                gotoligcol(perso->co.X, perso->co.Y);
                printf("O");
            }
            break;
        case 'q' :
        case 'Q' :
            if (perso->co.Y > MINY && !collisionBlocs(perso->co.X, perso->co.Y - 4, blocs, nbBlocs)) {
                cacherCharPerso(perso);
                perso->co.Y -= 4;
                gotoligcol(perso->co.X, perso->co.Y);
                printf("O");
            }
            break;
        case 's' :
        case 'S' :
            if (perso->co.X < MAXX && !collisionBlocs(perso->co.X + 2, perso->co.Y, blocs, nbBlocs)) {
                cacherCharPerso(perso);
                perso->co.X += 2;
                gotoligcol(perso->co.X, perso->co.Y);
                printf("O");
            }
            break;
        case 'z' :
        case 'Z' :
            if (perso->co.X > MINX && !collisionBlocs(perso->co.X - 2, perso->co.Y, blocs, nbBlocs)) {
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

void cacherCharPerso(PERSONNAGE *perso) {
    gotoligcol(perso->co.X, perso->co.Y),
            printf(" ");
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

