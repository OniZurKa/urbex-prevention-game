#include "../lib/raylib/src/raylib.h"
#include "header/pause.h"

static bool pause_active = false;
static int pause_window_width = 0;
static int pause_window_height = 0;

void pause_init(int window_width, int window_height) {
    pause_window_width = window_width;
    pause_window_height = window_height;
    pause_active = false;
}

void pause_update(bool *is_running) {
    if (!is_running) {
        return;
    }

    if (IsKeyPressed(KEY_Q)) {
        *is_running = false;
    }
}

void pause_draw_overlay(void) {
    if (!pause_active) {
        return;
    }

    DrawRectangle(0, 0, pause_window_width, pause_window_height, Fade(BLACK, 0.5f));
    DrawRectangleRounded((Rectangle){pause_window_width * 0.5f - 180.0f, pause_window_height * 0.5f - 100.0f, 360.0f, 200.0f}, 0.15f, 8, Fade(DARKGRAY, 0.9f));
    DrawText("PAUSE", (int)(pause_window_width * 0.5f - 70.0f), (int)(pause_window_height * 0.5f - 40.0f), 40, RAYWHITE);
    DrawText("ESC pour reprendre", (int)(pause_window_width * 0.5f - 115.0f), (int)(pause_window_height * 0.5f + 10.0f), 20, LIGHTGRAY);
    DrawText("Q pour quitter", (int)(pause_window_width * 0.5f - 85.0f), (int)(pause_window_height * 0.5f + 40.0f), 20, LIGHTGRAY);
}

bool pause_is_active(void) {
    return pause_active;
}

void pause_set_active(bool active) {
    pause_active = active;
}
