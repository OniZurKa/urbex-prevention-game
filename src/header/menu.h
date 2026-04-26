#ifndef MENU_H
#define MENU_H

#include <stdbool.h>
#include "main.h"

void menu_init_layout(int window_width, int window_height) ; // Initialise les positions et tailles des éléments du menu en fonction de la taille de la fenêtre
void menu_update(game_state_t *state, bool *is_running) ; // Met à jour le menu en fonction de l'état du jeu et de l'état d'exécution
void menu_draw(int window_width, int window_height) ; // Dessine le menu avec les dimensions de la fenêtre

#endif
