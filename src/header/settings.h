#ifndef SETTINGS_H
#define SETTINGS_H

#include <stdbool.h>
#include "main.h"

void settings_init_layout(int window_width, int window_height) ;
void settings_load(void) ;
void settings_apply(void) ;
void settings_update(game_state_t *state, bool *is_running) ;
void settings_draw(int window_width, int window_height) ;

#endif