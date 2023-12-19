#include "sauvegardes.h"

FILE *selectFichier() {
    clearConsole();
    gotoligcol(MINX_MENU_SAVE, MINY_MENU_SAVE);
    printf("Quel fichier de sauvegarde voulez vous utiliser ?");
    gotoligcol(MINX_MENU_SAVE + 1, MINY_MENU_SAVE);
    FILE *fichierSaveTemp = fopen("../sauvegardes/save1", "r");
    printf("1. ");
    if (fgetc(fichierSaveTemp) == -1) {
        printf("Fichier vide");
    } else {
        printf("Sauvegarde disponible");
    }
    fclose(fichierSaveTemp);
    gotoligcol(MINX_MENU_SAVE + 2, MINY_MENU_SAVE);
    fichierSaveTemp = fopen("../sauvegardes/save2.txt", "r");
    printf("2. ");
    if (fgetc(fichierSaveTemp) == -1) {
        printf("Fichier vide");
    } else {
        printf("Sauvegarde disponible");
    }
    fclose(fichierSaveTemp);
    gotoligcol(MINX_MENU_SAVE + 3, MINY_MENU_SAVE);
    fichierSaveTemp = fopen("../sauvegardes/save3.txt", "r");
    printf("3. ");
    if (fgetc(fichierSaveTemp) == -1) {
        printf("Fichier vide");
    } else {
        printf("Sauvegarde disponible");
    }
    fclose(fichierSaveTemp);

    gotoligcol(MINX_MENU_SAVE + 4, MINY_MENU_SAVE);
    int choix;
    scanf("%d", &choix);
    switch (choix) {
        case 1 :
            return fopen("../sauvegardes/save1", "r+");
        case 2 :
            return fopen("../sauvegardes/save2", "r+");
        case 3 :
            return fopen("../sauvegardes/save3", "r+");
        default :
            return NULL;
    }
}

PARTIE chargerNiveau(FILE *fichier) {
    assert(fichier);
    NIVEAU varNiveau;
    PARTIE partie;

    initOiseaux(varNiveau.oiseaux);

    fscanf(fichier, "niveau %hd\n", &partie.niveauActuel);
    gotoligcol(15, 0);
    printf("\n%hd", partie.niveauActuel);

    fscanf(fichier, "coActuelles %hd %hd\n", &varNiveau.perso.co.X, &varNiveau.perso.co.Y);
    printf("\nco : %hd %hd", varNiveau.perso.co.X, varNiveau.perso.co.Y);
    varNiveau.perso.co.X = (short) convCoX(varNiveau.perso.co.X);
    varNiveau.perso.co.Y = (short) convCoY(varNiveau.perso.co.Y);
    printf("\nco : %hd %hd", varNiveau.perso.co.X, varNiveau.perso.co.Y);

    fscanf(fichier, "tpsBalle %hd\n", &varNiveau.tpsBalle);

    fscanf(fichier, "\ncoDepart %hd %hd", &varNiveau.perso.initX, &varNiveau.perso.initY);
    varNiveau.perso.initX = (short) convCoX(varNiveau.perso.initX);
    varNiveau.perso.initY = (short) convCoY(varNiveau.perso.initY);
    gotoligcol(1, 0);
    printf("Co depart 1 : %d, %d", varNiveau.perso.co.X, varNiveau.perso.co.Y);

    fscanf(fichier, "\nnbBalles %hd :", &varNiveau.nbBalles);
    varNiveau.tabBalles = calloc(varNiveau.nbBalles,
                                 sizeof(BALLE)); // tableau de taille dynamique (ya ptetr le cours sur boostcamp)
    fscanf(fichier, "\n");
    for (int i = 0; i < varNiveau.nbBalles; i++) {
        short X, Y;
        fscanf(fichier, "co %hd %hd dir %hd\n", &X, &Y, &varNiveau.tabBalles[i].direction);
        varNiveau.tabBalles[i].co.X = convCoX(X);
        varNiveau.tabBalles[i].co.Y = convCoY(Y);
    }

    // Chargement des blocs :
    varNiveau.nbBlocs = 0;
    unsigned char plateau[10][10];
    for (int i = 0; i < 10; i++) {
        fgets(plateau[i], 11, fichier);
        fgetc(fichier);
    }
    //varNiveau.perso.co.X = varNiveau.perso.initX; // Sert à résoudre un bug inexplicable la co X se change toute
    //varNiveau.perso.co.Y = varNiveau.perso.initY; // seule à la ligne fgets(...) juste au dessus (10eme itération)


    BLOC tabBlocs[81];
    for (short x = 0; x < 10; x++) { // Chargement des blocs depuis le .txt
        for (short y = 0; y < 10; y++) {
            if (plateau[x][y] != '0') {
                varNiveau.nbBlocs++;
                switch (plateau[x][y]) {
                    case 'A' :
                        tabBlocs[varNiveau.nbBlocs] = initBloc(cassable, x, y);
                        break;
                    case 'B' :
                        tabBlocs[varNiveau.nbBlocs] = initBloc(pieges, x, y);
                        break;
                    case 'C' :
                        tabBlocs[varNiveau.nbBlocs] = initBloc(poussable, x, y);
                        break;
                    case 'D' :
                        tabBlocs[varNiveau.nbBlocs] = initBloc(fixe, x, y);
                        break;
                    case 'E' :
                        tabBlocs[varNiveau.nbBlocs] = initBloc(tapisroulantbas, x, y);
                        break;
                    case 'F' :
                        tabBlocs[varNiveau.nbBlocs] = initBloc(tapisroulantgauche, x, y);
                        break;
                    case 'G' :
                        tabBlocs[varNiveau.nbBlocs] = initBloc(tapisroulanthaut, x, y);
                        break;
                    case 'H' :
                        tabBlocs[varNiveau.nbBlocs] = initBloc(tapisroulantdroit, x, y);
                        break;
                };
            }
        }
    }
    varNiveau.tabBlocs = calloc(varNiveau.nbBlocs, sizeof(BLOC));
    for (int i = 0; i < varNiveau.nbBlocs; i++) {
        varNiveau.tabBlocs[i] = tabBlocs[i + 1];
    }

    partie.niveau = varNiveau;
    fclose(fichier);
    return partie;
}


void sauvegarder(PARTIE partie, FILE *fichier) {

    assert(fichier);
    fprintf(fichier, "niveau %hd\n", partie.niveauActuel);
    fprintf(fichier, "coActuelles %hd %hd\n", partie.niveau.perso.co.X, partie.niveau.perso.co.Y);
    fprintf(fichier, "tpsBalle %hd", partie.niveau.tpsBalle);
    fprintf(fichier, "\ncoDepart %hd %hd", partie.niveau.perso.initX, partie.niveau.perso.initY);
    fprintf(fichier, "\nnbBalles %hd :", partie.niveau.nbBalles);
    fprintf(fichier, "\n");
    for (int i = 0; i < partie.niveau.nbBalles; i++) {
        fprintf(fichier, "co %hd %hd dir %hd\n", partie.niveau.tabBalles[i].co.X, partie.niveau.tabBalles[i].co.Y,
                partie.niveau.tabBalles[i].direction);
    }
    char tabBlocs[10][10];
    for(int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            tabBlocs[y][x] = 0;
            for(int i = 0; i < partie.niveau.nbBlocs; i++) {
                if (partie.niveau.tabBlocs[i].co.X == x && partie.niveau.tabBlocs[i].co.Y == y) {
                    tabBlocs[y][x] = (char) (partie.niveau.tabBlocs[i].type+65);
                }
            }
        }
    }
    for(int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            fprintf(fichier, "%c", &tabBlocs[x][y]);
        }
        fprintf(fichier, "\n");
    }
    fclose(fichier);
}