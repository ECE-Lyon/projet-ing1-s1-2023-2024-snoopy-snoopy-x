#include "Niveau2.h"

PARTIE niveau2(PARTIE partie) {
    partie.niveau = initNiveau(2);
    partie.niveauActuel = 2;
    jouerNiveau(&partie);
    return partie;
}