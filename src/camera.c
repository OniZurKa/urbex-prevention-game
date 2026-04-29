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

#define CAMERA_SPEED 12.0f
#define CAMERA_HEIGHT 1.7f
#define CAMERA_JUMP_SPEED 5.5f
#define CAMERA_GRAVITY 14.0f
#define CAMERA_COLLISION_RADIUS 0.30f

static Camera3D camera;
static float yaw = 0.0f;
static float pitch = 0.0f;
static float camera_mouse_sensitivity = 0.1f;
static float camera_move_speed = CAMERA_SPEED;
static float camera_vertical_velocity = 0.0f;
static float camera_ground_height = CAMERA_HEIGHT;

static Vector3 camera_get_flat_forward(void) {
    Vector3 forward = camera_get_forward();
    forward.y = 0.0f;

    float length = sqrtf(forward.x * forward.x + forward.z * forward.z);
    if (length <= 0.0f) {
        return (Vector3){0.0f, 0.0f, 1.0f};
    }

    return (Vector3){forward.x / length, 0.0f, forward.z / length};
}

static Vector3 camera_get_flat_right(void) {
    Vector3 forward = camera_get_flat_forward();
    return (Vector3){-forward.z, 0.0f, forward.x};
}

static void camera_sync_target(void) {
    Vector3 forward = camera_get_forward();
    camera.target = (Vector3){camera.position.x + forward.x, camera.position.y + forward.y, camera.position.z + forward.z};
}

static void camera_apply_collision(Vector3 next_position) {
    Vector3 resolved_position = collision_resolve(camera.position, next_position, CAMERA_COLLISION_RADIUS);
    camera.position = resolved_position;
}

void camera_init() {
    Vector3 spawn = level_get_spawn_point();

    camera.position = spawn;
    camera.target = (Vector3){spawn.x, spawn.y, spawn.z + 1.0f};
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    camera.fovy = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    yaw = 0.0f;
    pitch = 0.0f;
    camera_vertical_velocity = 0.0f;
    camera_ground_height = spawn.y;
}

void camera_update() {
    float delta_time = GetFrameTime();
    Vector2 mouse_delta = input_get_mouse_delta();

    camera_rotate(-mouse_delta.x, -mouse_delta.y);

    if (input_is_forward()) {
        camera_move_forward(camera_move_speed * delta_time);
    }
    if (input_is_backward()) {
        camera_move_backward(camera_move_speed * delta_time);
    }
    if (input_is_left()) {
        camera_move_left(camera_move_speed * delta_time);
    }
    if (input_is_right()) {
        camera_move_right(camera_move_speed * delta_time);
    }

    if (input_is_jump() && camera.position.y <= camera_ground_height + 0.01f) {
        camera_vertical_velocity = CAMERA_JUMP_SPEED;
    }

    camera_vertical_velocity -= CAMERA_GRAVITY * delta_time;

    Vector3 next_position = camera.position;
    next_position.y += camera_vertical_velocity * delta_time;

    if (next_position.y <= camera_ground_height + CAMERA_COLLISION_RADIUS) {
        next_position.y = camera_ground_height + CAMERA_COLLISION_RADIUS;
        camera_vertical_velocity = 0.0f;
    }

    camera_apply_collision(next_position);
    camera_sync_target();
}

void camera_move_forward(float distance) {
    Vector3 forward = camera_get_flat_forward();
    Vector3 next_position = {
        camera.position.x + forward.x * distance,
        camera.position.y + forward.y * distance,
        camera.position.z + forward.z * distance
    };

    camera_apply_collision(next_position);

    camera_sync_target();
}

void camera_move_backward(float distance) {
    camera_move_forward(-distance);
}

void camera_move_left(float distance) {
    Vector3 right = camera_get_flat_right();
    Vector3 next_position = {
        camera.position.x + right.x * distance,
        camera.position.y + right.y * distance,
        camera.position.z + right.z * distance
    };

    camera_apply_collision(next_position);

    camera_sync_target();
}

void camera_move_right(float distance) {
    Vector3 right = camera_get_flat_right();
    Vector3 next_position = {
        camera.position.x - right.x * distance,
        camera.position.y - right.y * distance,
        camera.position.z - right.z * distance
    };

    camera_apply_collision(next_position);

    camera_sync_target();
}

void camera_rotate(float dx, float dy) {
    yaw += dx * camera_mouse_sensitivity;
    pitch += dy * camera_mouse_sensitivity;

    if (pitch > 85.0f) pitch = 85.0f;
    if (pitch < -85.0f) pitch = -85.0f;

    camera_sync_target();
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
