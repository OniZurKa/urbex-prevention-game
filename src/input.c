#include "raylib.h"
#include "header/input.h"

/*
 * ===================================
 * INPUT - Gestion des entrées
 * ===================================
 */

// À implémenter :
// typedef struct {
//     bool key_forward;
//     bool key_backward;
//     bool key_left;
//     bool key_right;
//     bool key_jump;
//     bool key_interact;
//     bool key_quit;
//     float mouse_x;
//     float mouse_y;
// } input_t;
//
// static input_t input;
// static Vector2 mouse_last_pos;

void input_update() {
    // À implémenter :
    // Chaque frame, vérifier l'état des touches :
    // input.key_forward = IsKeyDown(KEY_W) || IsKeyDown(KEY_Z)
    // input.key_backward = IsKeyDown(KEY_S)
    // input.key_left = IsKeyDown(KEY_A) || IsKeyDown(KEY_Q)
    // input.key_right = IsKeyDown(KEY_D)
    // input.key_jump = IsKeyDown(KEY_SPACE)
    // input.key_interact = IsKeyDown(KEY_E)
    // input.key_quit = IsKeyDown(KEY_ESCAPE)
    //
    // input.mouse_x = GetMouseX()
    // input.mouse_y = GetMouseY()
}

bool input_is_forward() {
    // À implémenter :
    // return input.key_forward;
    return false;
}

bool input_is_backward() {
    // À implémenter :
    // return input.key_backward;
    return false;
}

bool input_is_left() {
    // À implémenter :
    // return input.key_left;
    return false;
}

bool input_is_right() {
    // À implémenter :
    // return input.key_right;
    return false;
}

bool input_is_jump() {
    // À implémenter :
    // return input.key_jump;
    return false;
}

bool input_is_interact() {
    // À implémenter :
    // return input.key_interact;
    return false;
}

bool input_is_quit() {
    // À implémenter :
    // return input.key_quit;
    return false;
}

Vector2 input_get_mouse_delta() {
    // À implémenter :
    // Retourner le mouvement de la souris depuis la dernière frame
    // delta = current_pos - last_pos
    // mouse_last_pos = current_pos
    // return delta
    return (Vector2){0, 0};
}
