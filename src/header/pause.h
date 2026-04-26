#ifndef PAUSE_H
#define PAUSE_H

#include <stdbool.h>

void pause_init(int window_width, int window_height);
void pause_update(bool *is_running);
void pause_draw_overlay(void);
bool pause_is_active(void);
void pause_set_active(bool active);

#endif
