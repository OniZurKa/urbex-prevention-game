#ifndef MENU_H
#define MENU_H

#include <stdbool.h>
#include "main.h"

void menu_init_layout(int window_width, int window_height);
void menu_update(game_state_t *state, bool *is_running);
void menu_draw(int window_width, int window_height);

#endif
