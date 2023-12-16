#include "Niveau1.h"

NIVEAU initNiveau(short int niveau){
    NIVEAU varNiveau;

    // Initialisations ne dépendant pas du niveau
    varNiveau.perso.vies = 3;
    varNiveau.tempsMillis = 0;
    for(int i = 0; i < 4; i++) {
        varNiveau.oiseaux[i].recup = 0;
    }
    {
        varNiveau.oiseaux[0].co.X = 0;
        varNiveau.oiseaux[0].co.Y = 0;

        varNiveau.oiseaux[1].co.X = 0;
        varNiveau.oiseaux[1].co.Y = 9;

        varNiveau.oiseaux[2].co.X = 9;
        varNiveau.oiseaux[2].co.Y = 9;

        varNiveau.oiseaux[3].co.X = 9;
        varNiveau.oiseaux[3].co.Y = 0;
    }


    // Init dépendant de la mémoire :
    FILE *fichierNiveau = NULL;
    switch (niveau) {
        case 1 :
            fichierNiveau = fopen("..\\niveaux\\Niveau1\\niveau1.txt", "r"); break;
        case 2 :
            //fichierNiveau = fopen("../niveaux/Niveau2.txt", "r"); break;
        case 3 :
            //fichierNiveau = fopen("../niveaux/Niveau3.txt", "r"); break;
        case 4 :
            //fichierNiveau = fopen("../niveaux/Niveau4.txt", "r"); break;

        default :
            assert(!"Niveau non existant");
    }

    assert(fichierNiveau);
    fscanf(fichierNiveau, "tpsBalle %hd", &varNiveau.tpsBalle);
    fscanf(fichierNiveau, "\ncoDepart %hd %hd", &varNiveau.perso.co.X, &varNiveau.perso.co.Y);
    fscanf(fichierNiveau, "\nnbBalles %hd :", &varNiveau.nbBalles);
    varNiveau.tabBalles = calloc(varNiveau.nbBalles, sizeof(BALLE)); // tableau de taille dynamique (ya ptetr le cours sur boostcamp)
    fscanf(fichierNiveau, "\n");
    for(int i = 0; i < varNiveau.nbBalles; i++){
        fscanf(fichierNiveau, "co %hd %hd dir %hd\n", &varNiveau.tabBalles[i].co.X, &varNiveau.tabBalles[i].co.Y, &varNiveau.tabBalles[i].direction);
    }

    // Chargement des blocs :
    varNiveau.nbBlocs = 0;
    unsigned char plateau[10][10];
    for(int i = 0; i < 10; i++) {
        fgets(plateau[i], 11, fichierNiveau);
        fgetc(fichierNiveau);
        printf("%s\n", plateau[i]);
    }
    BLOC tabBlocs[70];
    for (short x = 0; x < 10; x++) {
        for (short y = 0; y < 10; y++) {
            if (plateau[x][y] != '0') {
                varNiveau.nbBlocs++;
                switch (plateau[x][y]) {
                    case 'A' :
                        tabBlocs[varNiveau.nbBlocs] = initBloc(cassable, x, y);
                        break;
                    case 'B' :
                        tabBlocs[varNiveau.nbBlocs] = initBloc(piege, x, y);
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
    printf("\nnbBlocs : %d", varNiveau.nbBlocs);
    //afficherTousLesBlocs(tabBlocs, varNiveau.nbBlocs+1);
    afficherTousLesBlocs(varNiveau.tabBlocs, varNiveau.nbBlocs);
    gotoligcol(10, 0);
    return varNiveau;
}


void niveau() {
    NIVEAU niveau;
    niveau = initNiveau(1);
    clearConsole();
    time_t start, end;
    int difMillis = 0, difPrecMillis = 0, difPrecMillisBalle = 0;
    struct timeval stop, startT;
    double dif;
    gettimeofday(&startT, NULL);
    time(&start);

    time(&end);
    PERSONNAGE perso;
    initPersonnage(&perso, 0, 0);
    BALLE balle;
    initBalle(&balle, convCoX(5), convCoY(5));
    afficherCase();
    gotoligcol(perso.co.X, perso.co.Y);
    printf("O");
    gotoligcol(balle.co.X, balle.co.Y);
    printf("%c", 27);

    do {
        time(&end);
        gettimeofday(&stop, NULL);
        dif = difftime(end, start);
        gotoligcol(0, 0);
        if (difMillis >= difPrecMillisBalle + 125) {
            difPrecMillisBalle = difMillis;
            checkDeplacementBalle(&balle, &perso, niveau.tabBlocs, niveau.nbBlocs);
        }
        char a;
        tapisRoulant(&perso, niveau.tabBlocs, niveau.nbBlocs);
        afficherTousLesBlocs(niveau.tabBlocs, niveau.nbBlocs);
        if (_kbhit()) {
            a = (char) getch();
            switch (a) {
                case 'x' :
                case 'X' :
                    quitter();
                    break;
                case 't' :
                case 'T' :
                    //consoleDebug(fichierLogs, &perso, &balle);
                    break;
                case 'm' :
                case 'M' :
                    afficherMenu();
                default :
                    deplacementPerso(&perso, a, niveau.tabBlocs, niveau.nbBlocs);
                    break;
            }
            if (difMillis >= difPrecMillis + 100) {
                difPrecMillis = difMillis;
                gotoligcol(balle.co.X, balle.co.Y);
                printf("%c", 207);
                gotoligcol(23, 21);
                printf("PV : %d", perso.vies);
            }
        }
        if (perso.vies == 0) {
            gameOver();
        }
        gotoligcol(21, 21);
        printf("Temps : %.2f\n", dif);
        difMillis = ((stop.tv_sec - startT.tv_sec) * 1000000 + stop.tv_usec - startT.tv_usec) / 1000;
        gotoligcol(22, 21);
        printf("Temps : %d\n", difMillis);
        gotoligcol(24, 21);
        printf("%d, %d", perso.co.X, perso.co.Y);
    } while (1);
    //debugFinJeu(fichierLogs, &perso, &balle);
}