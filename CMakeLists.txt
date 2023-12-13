cmake_minimum_required(VERSION 3.10)
project(PROJET C)

set(CMAKE_C_STANDARD 99)

add_executable(PROJET main.c entitees/personnage.h entitees/personnage.c consoleDebug/consoleDebug.c consoleDebug/consoleDebug.h Affichage/ecranConsole.c Affichage/ecranConsole.h Partie/partie.c Partie/partie.h Affichage/plateau.c Affichage/plateau.h entitees/balle.c entitees/balle.h entitees/blocs.c entitees/blocs.h Menu/menu.c Menu/menu.h
        Menu/regles.c
        Menu/regles.h)
add_executable(Exemple Affichage/exempleTableau.c entitees/personnage.h entitees/personnage.c consoleDebug/consoleDebug.c consoleDebug/consoleDebug.h Affichage/ecranConsole.c Affichage/ecranConsole.h Partie/partie.c Partie/partie.h Affichage/plateau.c Affichage/plateau.h entitees/balle.c entitees/balle.h entitees/blocs.c entitees/blocs.h Menu/menu.c Menu/menu.h
        Menu/regles.c
        Menu/regles.h)
