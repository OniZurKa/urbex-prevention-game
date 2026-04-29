#include <math.h>
#include "../lib/raylib/src/raylib.h"
#include "header/camera.h"
#include "header/input.h"
#include "header/collision.h"
#include "header/level.h"

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
static float camera_move_speed = CAMERA_SPEED;

void camera_init() {
    Vector3 spawn = level_get_spawn_point();

    camera.position = spawn;
    camera.target = (Vector3){spawn.x, spawn.y, spawn.z + 1.0f};
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    camera.fovy = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    yaw = 0.0f;
    pitch = 0.0f;
}

void camera_update() {
    Vector2 mouse_delta = input_get_mouse_delta();

    camera_rotate(mouse_delta.x, -mouse_delta.y);

    if (input_is_forward()) {
        camera_move_forward(camera_move_speed);
    }
    if (input_is_backward()) {
        camera_move_backward(camera_move_speed);
    }
    if (input_is_left()) {
        camera_move_left(camera_move_speed);
    }
    if (input_is_right()) {
        camera_move_right(camera_move_speed);
    }
}

void camera_move_forward(float distance) {
    Vector3 forward = camera_get_forward();
    Vector3 next_position = {
        camera.position.x + forward.x * distance,
        camera.position.y + forward.y * distance,
        camera.position.z + forward.z * distance
    };

    if (!level_is_collision(camera.position, next_position)) {
        camera.position = next_position;
    }

    camera.target = (Vector3){camera.position.x + forward.x, camera.position.y + forward.y, camera.position.z + forward.z};
}

void camera_move_backward(float distance) {
    camera_move_forward(-distance);
}

void camera_move_left(float distance) {
    Vector3 forward = camera_get_forward();
    forward.y = 0.0f;
    float forward_length = sqrtf(forward.x * forward.x + forward.z * forward.z);
    if (forward_length > 0.0f) {
        forward.x /= forward_length;
        forward.z /= forward_length;
    } else {
        forward = (Vector3){0.0f, 0.0f, 1.0f};
    }

    Vector3 right = (Vector3){forward.z, 0.0f, -forward.x};
    Vector3 next_position = {
        camera.position.x - right.x * distance,
        camera.position.y - right.y * distance,
        camera.position.z - right.z * distance
    };

    if (!level_is_collision(camera.position, next_position)) {
        camera.position = next_position;
    }

    forward = camera_get_forward();
    camera.target = (Vector3){camera.position.x + forward.x, camera.position.y + forward.y, camera.position.z + forward.z};
}

void camera_move_right(float distance) {
    camera_move_left(-distance);
}

void camera_rotate(float dx, float dy) {
    yaw += dx * camera_mouse_sensitivity;
    pitch += dy * camera_mouse_sensitivity;

    if (pitch > 85.0f) pitch = 85.0f;
    if (pitch < -85.0f) pitch = -85.0f;

    Vector3 forward = camera_get_forward();
    camera.target = (Vector3){camera.position.x + forward.x, camera.position.y + forward.y, camera.position.z + forward.z};
}

void camera_set_mouse_sensitivity(float mouse_sensitivity) {
    camera_mouse_sensitivity = mouse_sensitivity;
}

Vector3 camera_get_position() {
    return camera.position;
}

Vector3 camera_get_forward() {
    float yaw_rad = yaw * DEG2RAD;
    float pitch_rad = pitch * DEG2RAD;
    Vector3 forward = {
        cosf(pitch_rad) * sinf(yaw_rad),
        sinf(pitch_rad),
        cosf(pitch_rad) * cosf(yaw_rad)
    };

    float length = sqrtf(forward.x * forward.x + forward.y * forward.y + forward.z * forward.z);
    if (length <= 0.0f) {
        return (Vector3){0.0f, 0.0f, 1.0f};
    }

    return (Vector3){forward.x / length, forward.y / length, forward.z / length};
}
