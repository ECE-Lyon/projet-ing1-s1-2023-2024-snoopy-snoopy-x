cmake_minimum_required(VERSION 3.10)
project(PROJET C)

set(CMAKE_C_STANDARD 99)

add_executable(PROJET main.c
        entitees/personnage.h entitees/personnage.c
        consoleDebug/consoleDebug.c consoleDebug/consoleDebug.h
        Affichage/ecranConsole.c Affichage/ecranConsole.h
        Niveaux/Niveau1/Niveau1.c Niveaux/Niveau1/Niveau1.h
        Affichage/plateau.c Affichage/plateau.h
        entitees/balle.c entitees/balle.h
        entitees/blocs.c entitees/blocs.h
        Menu/menu.c Menu/menu.h
        Menu/regles.c
        Menu/regles.h
        Menu/mdp.c
        Menu/mdp.h
        Niveaux/Niveau3/Niveau3.c
        Niveaux/Niveau3/Niveau3.h
        Niveaux/Niveau2/Niveau2.c
        Niveaux/Niveau2/Niveau2.h
        niveaux/Scores.c
        niveaux/Scores.h
        entitees/conversionCoordonnees.c
        entitees/conversionCoordonnees.h

        )
add_executable(Exemple Affichage/exempleTableau.c
        entitees/personnage.h entitees/personnage.c
        consoleDebug/consoleDebug.c consoleDebug/consoleDebug.h
        Affichage/ecranConsole.c Affichage/ecranConsole.h
        Affichage/plateau.c Affichage/plateau.h
        entitees/balle.c entitees/balle.h
        entitees/blocs.c entitees/blocs.h
        Menu/menu.c Menu/menu.h
        Menu/regles.c
        Menu/regles.h
        Menu/mdp.c
        Menu/mdp.h
        Niveaux/Niveau1/Niveau1.c Niveaux/Niveau1/Niveau1.h
        Niveaux/Niveau3/Niveau3.c Niveaux/Niveau3/Niveau3.h
        Niveaux/Niveau2/Niveau2.c Niveaux/Niveau2/Niveau2.h
        Niveaux/Niveau4/Niveau3.c Niveaux/Niveau4/Niveau3.h
        niveaux/Scores.c niveaux/Scores.h
        entitees/conversionCoordonnees.c entitees/conversionCoordonnees.h)
