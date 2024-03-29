#include "personnage.h"


void cacherCharPerso(PERSONNAGE *perso) {
    gotoligcol(perso->co.X, perso->co.Y);
    printf(" ");
}

void resetPosition(PERSONNAGE *perso){
    perso->co.X = perso->initX;
    perso->co.Y = perso->initY;
}

void tapisRoulant(PERSONNAGE *perso, BLOC blocs[], int nbBlocs){
    for (int i = 0; i < nbBlocs; i++) {
        if((blocs[i].co.X == perso->co.X && blocs[i].co.Y == perso->co.Y && blocs[i].existe == 1)){
            switch(blocs[i].type){
                case(tapisroulantbas) :
                    perso->co.X += 2;
                    gotoligcol(perso->co.X, perso->co.Y);
                    printf("O");
                    break;
                case(tapisroulanthaut) :
                    perso->co.X -= 2;
                    gotoligcol(perso->co.X, perso->co.Y);
                    printf("O");
                    break;
                case(tapisroulantdroit) :
                    perso->co.Y += 4;
                    gotoligcol(perso->co.X, perso->co.Y);
                    printf("O");
                    break;
                case(tapisroulantgauche) :
                    perso->co.Y -= 4;
                    gotoligcol(perso->co.X, perso->co.Y);
                    printf("O");
                    break;
                default : break;
            }
        }
    }
}

void blocPiege(PERSONNAGE *perso, BLOC blocs[], int nbBlocs){
    for (int i = 0; i < nbBlocs; i++) {
        if((blocs[i].co.X == perso->co.X && blocs[i].co.Y == perso->co.Y && blocs[i].existe == 1)){
            if(blocs[i].type == pieges){
                perso->vies--;
                resetPosition(perso);
                gotoligcol(perso->co.X, perso->co.Y);
                printf("O");
            }
        }
    }
}

void blocPoussable(PERSONNAGE *perso, BLOC blocs[], int nbBlocs){
    for (int i = 0; i < nbBlocs; i++) {
        if (blocs[i].co.X == perso->co.X - 2 && blocs[i].co.Y == perso->co.Y && blocs[i].type == poussable && blocs[i].deplacementRestant >= 1) {
            blocs[i].deplacementRestant--;
            gotoligcol(blocs[i].co.X, blocs[i].co.Y);
            printf(" ");
            blocs[i].co.X = blocs[i].co.X - 2;
            gotoligcol(blocs[i].co.X, blocs[i].co.Y);
            printf("%s%c%s", ANSI_WHITE, CHAR_BLOC_POUSSABLE, ANSI_GREEN);
        }
        if (blocs[i].co.X == perso->co.X + 2 && blocs[i].co.Y == perso->co.Y && blocs[i].type == poussable && blocs[i].deplacementRestant >= 1) {
            blocs[i].deplacementRestant--;
            gotoligcol(blocs[i].co.X, blocs[i].co.Y);
            printf(" ");
            blocs[i].co.X = blocs[i].co.X + 2;
            gotoligcol(blocs[i].co.X, blocs[i].co.Y);
            printf("%s%c%s", ANSI_WHITE, CHAR_BLOC_POUSSABLE, ANSI_GREEN);
        }
        if (blocs[i].co.X == perso->co.X && blocs[i].co.Y == perso->co.Y + 4 && blocs[i].type == poussable && blocs[i].deplacementRestant >= 1) {
            blocs[i].deplacementRestant--;
            gotoligcol(blocs[i].co.X, blocs[i].co.Y);
            printf(" ");
            blocs[i].co.Y = blocs[i].co.Y + 4;
            gotoligcol(blocs[i].co.X, blocs[i].co.Y);
            printf("%s%c%s", ANSI_WHITE, CHAR_BLOC_POUSSABLE, ANSI_GREEN);
        }
        if (blocs[i].co.X == perso->co.X && blocs[i].co.Y == perso->co.Y - 4 && blocs[i].type == poussable && blocs[i].deplacementRestant >= 1) {
            blocs[i].deplacementRestant--;
            gotoligcol(blocs[i].co.X, blocs[i].co.Y);
            printf(" ");
            blocs[i].co.Y = blocs[i].co.Y - 4;
            gotoligcol(blocs[i].co.X, blocs[i].co.Y);
            printf("%s%c%s", ANSI_WHITE, CHAR_BLOC_POUSSABLE, ANSI_GREEN);
        }
    }
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
        case 'e' :
        case 'E' :
            chercherCasserBlocs(perso->co, blocs, nbBlocs);
            blocPoussable(perso, blocs, nbBlocs);
            break;
        default :
            break;
    }
}