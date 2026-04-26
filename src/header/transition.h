#ifndef TRANSITION_H
#define TRANSITION_H

#include "main.h"

void transition_init(int window_width, int window_height) ; // Initialise les dimensions et paramètres de transition
void transition_update(game_state_t *current_state, game_state_t target_state) ; // Met à jour la transition en cours, change current_state à target_state si terminé
void transition_draw(void) ; // Dessine l'effet de transition (fade, wipe, etc.) en fonction de la progression
void transition_start(game_state_t from, game_state_t to) ; // Démarre une transition entre les états 'from' et 'to', initialise les paramètres d'animation
bool transition_is_playing(void) ; // Retourne si une transition est actuellement en cours

#endif
