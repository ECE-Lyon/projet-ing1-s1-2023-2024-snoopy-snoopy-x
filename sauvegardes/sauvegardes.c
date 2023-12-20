#include "sauvegardes.h"

FILE *selectFichier() {
    clearConsole();
    gotoligcol(MINX_MENU_SAVE, MINY_MENU_SAVE);
    printf("Quel fichier de sauvegarde voulez vous utiliser ?");
    gotoligcol(MINX_MENU_SAVE + 1, MINY_MENU_SAVE);
    FILE *fichierSaveTemp = fopen("../sauvegardes/save1.txt", "r");
    assert(fichierSaveTemp);
    printf("1. ");
    if (fgetc(fichierSaveTemp) == -1) {
        printf("Fichier vide");
    } else {
        printf("Sauvegarde disponible");
    }
    fclose(fichierSaveTemp);

    gotoligcol(MINX_MENU_SAVE + 2, MINY_MENU_SAVE);
    fichierSaveTemp = fopen("../sauvegardes/save2.txt", "r");
    assert(fichierSaveTemp);
    printf("2. ");
    if (fgetc(fichierSaveTemp) == -1) {
        printf("Fichier vide");
    } else {
        printf("Sauvegarde disponible");
    }
    fclose(fichierSaveTemp);

    gotoligcol(MINX_MENU_SAVE + 3, MINY_MENU_SAVE);
    fichierSaveTemp = fopen("../sauvegardes/save3.txt", "r");
    assert(fichierSaveTemp);
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
            return fopen("../sauvegardes/save1.txt", "r+");
        case 2 :
            return fopen("../sauvegardes/save2.txt", "r+");
        case 3 :
            return fopen("../sauvegardes/save3.txt", "r+");
        default :
            return NULL;
    }
}

PARTIE chargerNiveau(FILE *fichier) {
    PARTIE partie;
    partie.niveauActuel = -1;
    if (fichier == NULL) return partie;
    NIVEAU varNiveau;

    initOiseaux(varNiveau.oiseaux);

    fscanf(fichier, "niveau %hd\n", &partie.niveauActuel);
    gotoligcol(15, 0);
    printf("\n%hd", partie.niveauActuel);

    fscanf(fichier, "coActuelles %hd %hd\n", &varNiveau.perso.co.X, &varNiveau.perso.co.Y);
    fscanf(fichier, "pv %hd\n", &varNiveau.perso.vies);
    fscanf(fichier, "oiseaux");
    for(int i = 0; i < 4; i++) {
        fscanf(fichier, " %hd", &varNiveau.oiseaux[i].recup);
    }
    fscanf(fichier, "\n");
    fscanf(fichier, "tpsBalle %hd\n", &varNiveau.tpsBalle);
    fscanf(fichier, "tpsRestant %d\n", &varNiveau.tempsRestant);
    fscanf(fichier, "coDepart %hd %hd\n", &varNiveau.perso.initX, &varNiveau.perso.initY);

    fscanf(fichier, "nbBalles %hd :\n", &varNiveau.nbBalles);
    varNiveau.tabBalles = calloc(varNiveau.nbBalles, sizeof(BALLE));
    for (int i = 0; i < varNiveau.nbBalles; i++) {
        fscanf(fichier, "co %hd %hd dir %hd\n", &varNiveau.tabBalles[i].co.X, &varNiveau.tabBalles[i].co.Y, &varNiveau.tabBalles[i].direction);
     }

    // Chargement des blocs :
    varNiveau.nbBlocs = 0;
    unsigned char plateau[10][10];
    for (int i = 0; i < 10; i++) {
        fgets(plateau[i], 11, fichier);
        fgetc(fichier);
    }
    BLOC tabBlocs[81];
    for (short x = 0; x < 10; x++) { // Chargement des blocs depuis le .txt
        for (short y = 0; y < 10; y++) {
            if (plateau[x][y] != '0') {
                varNiveau.nbBlocs++;
                tabBlocs[varNiveau.nbBlocs] = initBloc(plateau[x][y]-65, x, y);
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
    //assert(fichier);
    fprintf(fichier, "niveau %hd\n", partie.niveauActuel);
    fprintf(fichier, "coActuelles %hd %hd\n", partie.niveau.perso.co.X, partie.niveau.perso.co.Y);
    fprintf(fichier, "pv %d\n", partie.niveau.perso.vies);
    fprintf(fichier, "oiseaux");
    for(int i = 0; i < 4; i++) {
        fprintf(fichier, " %hd", partie.niveau.oiseaux[i].recup);
    }
    fprintf(fichier, "\n");
    fprintf(fichier, "tpsBalle %hd\n", partie.niveau.tpsBalle);
    fprintf(fichier, "tpsRestant %d\n", partie.niveau.tempsRestant);
    fprintf(fichier, "coDepart %hd %hd\n", partie.niveau.perso.initX, partie.niveau.perso.initY);
    fprintf(fichier, "nbBalles %hd :\n", partie.niveau.nbBalles);
    for (int i = 0; i < partie.niveau.nbBalles; i++) {
        fprintf(fichier, "co %hd %hd dir %hd\n", partie.niveau.tabBalles[i].co.X, partie.niveau.tabBalles[i].co.Y,
                partie.niveau.tabBalles[i].direction);
    }
    int nbBlocs = 0;
    char tabBlocs[10][10];
    for(int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            tabBlocs[x][y] = '0';
            for(int i = 0; i < partie.niveau.nbBlocs; i++) {
                if (partie.niveau.tabBlocs[i].co.X == convCoX(x) && partie.niveau.tabBlocs[i].co.Y == convCoY(y) && partie.niveau.tabBlocs[i].existe) {
                    tabBlocs[x][y] = partie.niveau.tabBlocs[i].type+65;
                    nbBlocs++;
                }
            }
        }
    }
    for(int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            fprintf(fichier, "%c", tabBlocs[x][y]);
        }
        fprintf(fichier, "\n");
    }
    fprintf(fichier, "nbBlocs %d :\n", nbBlocs);

    fclose(fichier);
}