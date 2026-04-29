#include "header/ending.h"
#include "../lib/raylib/src/raylib.h"
#include "header/hud.h"

static int hud_window_width = 0;
static int hud_window_height = 0;

void hud_init(int window_width, int window_height) {
    hud_window_width = window_width;
    hud_window_height = window_height;
}

void hud_update(game_state_t state, float delta_time) {
    (void)state;
    (void)delta_time;
}

void hud_draw_playing(void) {
    int center_x = hud_window_width / 2;
    int center_y = hud_window_height / 2;

    DrawLine(center_x - 8, center_y, center_x + 8, center_y, RAYWHITE);
    DrawLine(center_x, center_y - 8, center_x, center_y + 8, RAYWHITE);
    DrawText("ZQSD deplacement | ESC pause", 20, 20, 20, RAYWHITE);
}

void hud_draw_ending(void) {
    DrawRectangle(0, 0, hud_window_width, hud_window_height, Fade(BLACK, 0.25f));
    DrawText(ending_get_message(), 40, hud_window_height - 80, 24, RAYWHITE);
}
