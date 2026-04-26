#ifndef PAUSE_H
#define PAUSE_H

#include <stdbool.h>

void pause_init(int window_width, int window_height) ; // Initialise les positions/boutons du menu pause et conserve les dimensions utiles
void pause_update(bool *is_running) ; // Toggle pause (ex: touche ESC), navigation clavier/souris des boutons (reprendre/quitter), modifier *is_running si le joueur choisit quitter
void pause_draw_overlay(void) ; // Dessine un voile semi-transparent, panneau PAUSE + boutons, utilise pause_window_width/pause_window_height pour le layout
bool pause_is_active(void) ; // Retourne si le menu pause est actif
void pause_set_active(bool active) ; // Active ou désactive le menu pause, implémente si besoin d'effets annexes

#endif
