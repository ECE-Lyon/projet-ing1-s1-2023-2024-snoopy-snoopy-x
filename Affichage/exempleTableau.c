#include "../niveaux/Niveau1/Niveau1.h"

int main() {
    ShowWindow(GetConsoleWindow(), SW_SHOWMAXIMIZED);
    SetConsoleTitle("SNOOPY X");
    PARTIE partie = chargerNiveau(selectFichier());
    printf("\33[?25l");
    jouerNiveau(&partie);
    while(1);
}
