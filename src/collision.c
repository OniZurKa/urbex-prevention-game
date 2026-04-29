#include "../lib/raylib/src/raylib.h"
#include "header/collision.h"

/*
 * ===================================
 * COLLISION - Système de collision
 * ===================================
 */

bool collision_check_sphere_box(Vector3 sphere_pos, float sphere_radius, BoundingBox box) {
    float closest_x = sphere_pos.x;
    float closest_y = sphere_pos.y;
    float closest_z = sphere_pos.z;

    if (closest_x < box.min.x) closest_x = box.min.x;
    if (closest_x > box.max.x) closest_x = box.max.x;
    if (closest_y < box.min.y) closest_y = box.min.y;
    if (closest_y > box.max.y) closest_y = box.max.y;
    if (closest_z < box.min.z) closest_z = box.min.z;
    if (closest_z > box.max.z) closest_z = box.max.z;

    float dx = sphere_pos.x - closest_x;
    float dy = sphere_pos.y - closest_y;
    float dz = sphere_pos.z - closest_z;
    float distance_squared = dx * dx + dy * dy + dz * dz;

    return distance_squared <= sphere_radius * sphere_radius;
}

collision_t collision_raycast(Vector3 start, Vector3 end) {
    collision_t col = {false, {0,0,0}, {0,0,0}, -1};
    if ((start.y >= 1.7f && end.y <= 1.7f) || (start.y <= 1.7f && end.y >= 1.7f)) {
        float denom = end.y - start.y;
        float t = 0.0f;

        if (denom != 0.0f) {
            t = (1.7f - start.y) / denom;
        }

        if (t >= 0.0f && t <= 1.0f) {
            col.has_collision = true;
            col.collision_point = (Vector3){
                start.x + (end.x - start.x) * t,
                start.y + (end.y - start.y) * t,
                start.z + (end.z - start.z) * t
            };
            col.collision_point.y = 1.7f;
            col.collision_normal = (Vector3){0.0f, 1.0f, 0.0f};
            col.collision_object_id = 0;
        }
    }
    return col;
}

bool collision_is_on_ground(Vector3 player_pos) {
    return player_pos.y <= 1.7f + 0.05f;
}

Vector3 collision_resolve(Vector3 old_pos, Vector3 new_pos, float radius) {
    (void)old_pos;
    if (new_pos.y < 1.7f + radius) {
        new_pos.y = 1.7f + radius;
    }
    return new_pos;
}

void collision_init_level(level_t* level) {
    (void)level;
}
