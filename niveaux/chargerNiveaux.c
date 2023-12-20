#include "chargerNiveaux.h"


NIVEAU initNiveau(short int niveau){
    NIVEAU varNiveau;

    // Initialisations ne dépendant pas du niveau
    varNiveau.perso.vies = 3;
    initOiseaux(varNiveau.oiseaux);

    // Init dépendant de la mémoire :
    FILE *fichierNiveau = NULL;
    switch (niveau) {
        case 1 :
            fichierNiveau = fopen("..\\niveaux\\Niveau1\\niveau1.txt", "r"); break;
        case 2 :
            fichierNiveau = fopen("..\\niveaux\\Niveau2\\niveau2.txt", "r"); break;
        case 3 :
            fichierNiveau = fopen("..\\niveaux\\Niveau3\\niveau3.txt", "r"); break;
        case 4 :
            //fichierNiveau = fopen("../niveaux/Niveau4.txt", "r"); break;
        default :
            assert(!"Niveau non existant");
    }

    assert(fichierNiveau);
    fscanf(fichierNiveau, "tpsBalle %hd\n", &varNiveau.tpsBalle);
    fscanf(fichierNiveau, "\ncoDepart %hd %hd", &varNiveau.perso.co.X, &varNiveau.perso.co.Y);
    varNiveau.perso.co.X = (short) convCoX(varNiveau.perso.co.X);
    varNiveau.perso.co.Y = (short) convCoY(varNiveau.perso.co.Y);
    varNiveau.perso.initX = varNiveau.perso.co.X;
    varNiveau.perso.initY = varNiveau.perso.co.Y;

    fscanf(fichierNiveau, "\nnbBalles %hd :", &varNiveau.nbBalles);
    varNiveau.tabBalles = calloc(varNiveau.nbBalles, sizeof(BALLE)); // tableau de taille dynamique (ya ptetr le cours sur boostcamp)
    fscanf(fichierNiveau, "\n");
    for(int i = 0; i < varNiveau.nbBalles; i++){
        short X, Y;
        fscanf(fichierNiveau, "co %hd %hd dir %hd\n", &X, &Y, &varNiveau.tabBalles[i].direction);
        varNiveau.tabBalles[i].co.X = convCoX(X);
        varNiveau.tabBalles[i].co.Y = convCoY(Y);
    }

    // Chargement des blocs :
    varNiveau.nbBlocs = 0;
    unsigned char plateau[10][10];
    for(int i = 0; i < 10; i++) {
        fgets(plateau[i], 11, fichierNiveau);
        fgetc(fichierNiveau);
    }
    varNiveau.perso.co.X = varNiveau.perso.initX; // Sert à résoudre un bug inexplicable la co X se change toute
    varNiveau.perso.co.Y = varNiveau.perso.initY; // seule à la ligne fgets(...) juste au dessus (10eme itération)


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
        varNiveau.tabBlocs[i] = tabBlocs[i+1];
    }
    varNiveau.tempsRestant = 120;

    return varNiveau;
}
