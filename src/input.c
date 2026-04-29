#include "../lib/raylib/src/raylib.h"
#include "header/input.h"

/*
 * ===================================
 * INPUT - Gestion des entrées
 * ===================================
 */

static input_t input;
static Vector2 mouse_last_pos;
static bool mouse_last_pos_initialized = false;

void input_update() {
    input.key_forward = IsKeyDown(KEY_W) || IsKeyDown(KEY_Z);
    input.key_backward = IsKeyDown(KEY_S);
    input.key_left = IsKeyDown(KEY_A) || IsKeyDown(KEY_Q);
    input.key_right = IsKeyDown(KEY_D);
    input.key_jump = IsKeyDown(KEY_SPACE);
    input.key_interact = IsKeyDown(KEY_E);
    input.key_quit = IsKeyPressed(KEY_ESCAPE);

    input.mouse_x = (float)GetMouseX();
    input.mouse_y = (float)GetMouseY();

    if (!mouse_last_pos_initialized) {
        mouse_last_pos = (Vector2){input.mouse_x, input.mouse_y};
        mouse_last_pos_initialized = true;
    }
}

bool input_is_forward() {
    return input.key_forward;
}

bool input_is_backward() {
    return input.key_backward;
}

bool input_is_left() {
    return input.key_left;
}

bool input_is_right() {
    return input.key_right;
}

bool input_is_jump() {
    return input.key_jump;
}

bool input_is_interact() {
    return input.key_interact;
}

bool input_is_quit() {
    return input.key_quit;
}

Vector2 input_get_mouse_delta() {
    Vector2 current_pos = {input.mouse_x, input.mouse_y};
    Vector2 delta = {current_pos.x - mouse_last_pos.x, current_pos.y - mouse_last_pos.y};
    mouse_last_pos = current_pos;
    return delta;
}
