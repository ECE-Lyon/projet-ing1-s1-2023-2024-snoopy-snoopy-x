#include "Niveau1.h"
#include "../../Menu/menu.h"

NIVEAU initNiveau(short int niveau){
    NIVEAU varNiveau;

    // Initialisations ne dépendant pas du niveau
    varNiveau.perso.vies = 3;
    varNiveau.tempsMillis = 0;
    for(int i = 0; i < 4; i++) {
        varNiveau.oiseaux[i].recup = 0;
    }
    varNiveau.oiseaux[0].co.X = 0;
    varNiveau.oiseaux[0].co.Y = 0;

    varNiveau.oiseaux[1].co.X = 0;
    varNiveau.oiseaux[1].co.Y = 9;

    varNiveau.oiseaux[2].co.X = 9;
    varNiveau.oiseaux[2].co.Y = 9;

    varNiveau.oiseaux[3].co.X = 9;
    varNiveau.oiseaux[3].co.Y = 0;


    // Init dépendant de la mémoire : TODO:
    FILE *fichierNiveau = NULL;
    switch (niveau) {
        case 1 :
            fichierNiveau = fopen("../Niveaux/niveau1.txt", "r"); break;
        case 2 :
            fichierNiveau = fopen("../Niveaux/niveau2.txt", "r"); break;
        case 3 :
            fichierNiveau = fopen("../Niveaux/niveau3.txt", "r"); break;
        case 4 :
            fichierNiveau = fopen("../Niveaux/niveau4.txt", "r"); break;

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
    
    return varNiveau;
}


void niveau() {
    clearConsole();
    int finJeu = 0;
    time_t start, end;
    int difMillis = 0, difPrecMillis = 0, difPrecMillisBalle = 0;
    struct timeval stop, startT;
    double dif;
    gettimeofday(&startT, NULL);
    time(&start);
    const short nbBlocs = 3;
    BLOC blocs[] = {
            initBloc(poussable, 1, 0),
            initBloc(cassable, 0, 4),
            initBloc(piege, 5, 7)
    };

    time(&end);
    PERSONNAGE perso;
    initPersonnage(&perso, 0, 0);
    BALLE balle;
    initBalle(&balle, 19, 85);
    afficherCase();

    gotoligcol(perso.co.X, perso.co.Y);
    printf("O");
    gotoligcol(balle.co.X, balle.co.Y);
    printf("%c", 207);

    do {
        time(&end);
        gettimeofday(&stop, NULL);
        dif = difftime(end, start);
        gotoligcol(0, 0);
        if (difMillis >= difPrecMillisBalle + 125) {
            difPrecMillisBalle = difMillis;
            checkDeplacementBalle(&balle, &perso, blocs, nbBlocs);
        }
        char a;
        gotoligcol(0, 0);
        afficherTousLesBlocs(blocs, 3);
        if (_kbhit()) {
            a = (char) getch();
            switch (a) {
                case 'x' :
                case 'X' :
                    quitter();
                    break;
                case 't' :
                case 'T' :
                    break;
                case 'm' :
                case 'M' :
                    afficherMenu();
                default :
                    deplacementPerso(&perso, a, blocs, nbBlocs);
                    break;
            }
            if (difMillis >= difPrecMillis + 100) {
                difPrecMillis = difMillis;
                gotoligcol(perso.co.X, perso.co.Y);
                printf("O");
                gotoligcol(balle.co.X, balle.co.Y);
                printf("%c", 207);
                gotoligcol(23, 21);
                printf("PV : %d", perso.vies);
            }
        }
        if (perso.vies == 0) {
            finJeu = 1;
        }
        gotoligcol(21, 21);
        printf("Temps : %.2f\n", dif);
        difMillis = ((stop.tv_sec - startT.tv_sec) * 1000000 + stop.tv_usec - startT.tv_usec) / 1000;
        gotoligcol(22, 21);
        printf("Temps : %d\n", difMillis);
        gotoligcol(24, 21);
        printf("%d, %d", perso.co.X, perso.co.Y);
    } while (!finJeu);
}