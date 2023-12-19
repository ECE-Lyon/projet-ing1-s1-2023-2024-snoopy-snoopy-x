#ifndef UNTITLED15_MENU_H
#define UNTITLED15_MENU_H
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include "regles.h"
#include "mdp.h"
#include "../niveaux/Niveau1/Niveau1.h"
#include "../niveaux/Niveau2/Niveau2.h"
#include "../niveaux/Niveau3/Niveau3.h"

#define ANSI_RESET "\x1b[0m"
#define ANSI_BLACK "\x1b[30m"
#define ANSI_RED "\x1b[31m"
#define ANSI_GREEN "\x1b[32m"
#define ANSI_YELLOW "\x1b[33m"
#define ANSI_BLUE "\x1b[34m"
#define ANSI_MAGENTA "\x1b[35m"
#define ANSI_CYAN "\x1b[36m"
#define ANSI_WHITE "\x1b[37m"

#define DOUBLEVERTICAL 186
#define DOUBLEHORIZONTAL 205
#define DOUBLEANGLEHAUTGAUCHE 201
#define DOUBLEANGLEHAUTDROIT 187
#define DOUBLEANGLEBASGAUCHE 200
#define DOUBLEANGLEBASDROITE 188
#define VERTICAL 179
#define HORIZONTAL 196
#define LINK 197


void quitter();
void afficherMenu();

#endif
