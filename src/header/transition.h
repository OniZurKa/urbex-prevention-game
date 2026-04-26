#ifndef TRANSITION_H
#define TRANSITION_H

#include "main.h"

void transition_init(int window_width, int window_height);
void transition_update(game_state_t *current_state, game_state_t target_state);
void transition_draw(void);
void transition_start(game_state_t from, game_state_t to);
bool transition_is_playing(void);

#endif
