#include "Niveau1.h"


PARTIE niveau1() {
    PARTIE partie;
    partie.niveau = initNiveau(1);
    partie.niveauActuel = 1;
    jouerNiveau(&partie);
    return partie;
}