#include "../lib/raylib/src/raylib.h"
#include "header/input.h"

/*
 * ===================================
 * INPUT - Gestion des entrées
 * ===================================
 */

static input_t input;

void input_update() {
    input.key_forward = IsKeyDown(KEY_W) || IsKeyDown(KEY_Z);
    input.key_backward = IsKeyDown(KEY_S);
    input.key_left = IsKeyDown(KEY_A) || IsKeyDown(KEY_Q);
    input.key_right = IsKeyDown(KEY_D);
    input.key_jump = IsKeyPressed(KEY_SPACE);
    input.key_interact = IsKeyDown(KEY_E);
    input.key_quit = IsKeyPressed(KEY_ESCAPE);

    input.mouse_x = (float)GetMouseX();
    input.mouse_y = (float)GetMouseY();
}

bool input_is_forward() {
    return input.key_forward;
}

bool input_is_backward() {
    return input.key_backward;
}

bool input_is_left() {
    // Note: Inversion des touches gauche/droite pour correspondre à la perspective de la caméra    
    return input.key_right;
}

bool input_is_right() {
    // Note: Inversion des touches gauche/droite pour correspondre à la perspective de la caméra    
    return input.key_left;
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
    return GetMouseDelta();
}
