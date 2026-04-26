#ifndef HUD_H
#define HUD_H

#include "main.h"

void hud_init(int window_width, int window_height) ; // Initialise le HUD avec les dimensions de la fenêtre
void hud_update(game_state_t state, float delta_time) ; // Met à jour le HUD en fonction de l'état du jeu et du temps écoulé
void hud_draw_playing(void) ; // Affiche les éléments du HUD pendant le jeu (crosshair, infos joueur, aides contextuelles)
void hud_draw_ending(void) ; // Affiche le panneau de fin avec le message d'ending et les options (recommencer/quitter)

#endif
