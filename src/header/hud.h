#ifndef HUD_H
#define HUD_H

#include "main.h"

void hud_init(int window_width, int window_height);
void hud_update(game_state_t state, float delta_time);
void hud_draw_playing(void);
void hud_draw_ending(void);

#endif
