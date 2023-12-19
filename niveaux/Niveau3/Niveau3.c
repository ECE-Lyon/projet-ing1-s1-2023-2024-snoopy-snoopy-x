#include "Niveau3.h"

PARTIE niveau3(PARTIE partie) {
    partie.niveau = initNiveau(3);
    partie.niveauActuel = 3;
    jouerNiveau(&partie);
    return partie;
}