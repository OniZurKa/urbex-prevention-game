#include "../lib/raylib/src/raylib.h"
#include "header/camera.h"
#include "header/input.h"
#include "header/collision.h"

/*
 * ===================================
 * CAMERA - Gestion caméra FPS
 * ===================================
 */

#define CAMERA_SPEED 0.2f
#define CAMERA_HEIGHT 1.7f

static Camera3D camera;
static float yaw = 0.0f;
static float pitch = 0.0f;
static float camera_mouse_sensitivity = 0.1f;

void camera_init() {
    // À implémenter :
    // - Initialiser position : spawn point du joueur
    // - Initialiser up = {0, 1, 0}
    // - Initialiser fovy = 60.0f
    // - Initialiser projection = CAMERA_PERSPECTIVE
    // - yaw = 0.0f
    // - pitch = 0.0f
}

void camera_update() {
    // À implémenter :
    // 1. Récupérer inputs (W/A/S/D, souris)
    // 2. Appliquer mouvement (forward/backward/left/right)
    // 3. Appliquer rotation (yaw/pitch selon souris)
    // 4. Limiter pitch entre -85° et 85°
    // 5. Mettre à jour target selon yaw/pitch
    // 6. Vérifier collisions et corriger position
}

void camera_move_forward(float distance) {
    // À implémenter :
    // Vector3 forward = direction calculée depuis yaw/pitch
    // Nouvelle position = position + (forward * distance)
    // Vérifier collision et appliquer
}

void camera_move_backward(float distance) {
    // À implémenter :
    // camera_move_forward(-distance)
}

void camera_move_left(float distance) {
    // À implémenter :
    // Vector3 right = direction de droite (perpendiculaire à forward)
    // Nouvelle position = position - (right * distance)
}

void camera_move_right(float distance) {
    // À implémenter :
    // camera_move_left(-distance)
}

void camera_rotate(float dx, float dy) {
    // À implémenter :
    // yaw += dx * camera_mouse_sensitivity
    // pitch += dy * camera_mouse_sensitivity
    // Limiter pitch entre -85 et 85
}

void camera_set_mouse_sensitivity(float mouse_sensitivity) {
    camera_mouse_sensitivity = mouse_sensitivity;
}

Vector3 camera_get_position() {
    // À implémenter :
    // return camera.position;
    return (Vector3){0, 0, 0};
}

Vector3 camera_get_forward() {
    // À implémenter :
    // Calculer et retourner le vecteur avant (direction)
    return (Vector3){0, 0, 1};
}
