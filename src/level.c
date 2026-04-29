#include <stddef.h>
#include <string.h>
#include "../lib/raylib/src/raylib.h"
#include "header/level.h"
#include "header/assets.h"

/*
 * ===================================
 * LEVEL - Gestion des niveaux/zones
 * ===================================
 */

static level_t level;

void level_init() {
    level.zone_count = 6;
    level.spawn_point = (Vector3){0.0f, 1.7f, 0.0f};
    level.exit_point = (Vector3){24.0f, 1.7f, 18.0f};

    level.zones[0].type = 0;
    level.zones[0].bounds = (BoundingBox){(Vector3){-4.0f, 0.0f, -4.0f}, (Vector3){4.0f, 4.0f, 4.0f}};
    level.zones[0].position = (Vector3){0.0f, 2.0f, 0.0f};
    strcpy(level.zones[0].name, "Entrance");

    level.zones[1].type = 1;
    level.zones[1].bounds = (BoundingBox){(Vector3){6.0f, 0.0f, -4.0f}, (Vector3){16.0f, 4.0f, 6.0f}};
    level.zones[1].position = (Vector3){11.0f, 2.0f, 1.0f};
    strcpy(level.zones[1].name, "Main Hall");

    level.zones[2].type = 2;
    level.zones[2].bounds = (BoundingBox){(Vector3){16.0f, 0.0f, 6.0f}, (Vector3){20.0f, 5.0f, 12.0f}};
    level.zones[2].position = (Vector3){18.0f, 2.5f, 9.0f};
    strcpy(level.zones[2].name, "Stairs");

    level.zones[3].type = 3;
    level.zones[3].bounds = (BoundingBox){(Vector3){-2.0f, 0.0f, 10.0f}, (Vector3){8.0f, 3.0f, 18.0f}};
    level.zones[3].position = (Vector3){3.0f, 1.5f, 14.0f};
    strcpy(level.zones[3].name, "Water Room");

    level.zones[4].type = 4;
    level.zones[4].bounds = (BoundingBox){(Vector3){10.0f, 0.0f, 14.0f}, (Vector3){20.0f, 4.0f, 24.0f}};
    level.zones[4].position = (Vector3){15.0f, 2.0f, 19.0f};
    strcpy(level.zones[4].name, "Gas Room");

    level.zones[5].type = 5;
    level.zones[5].bounds = (BoundingBox){(Vector3){22.0f, 0.0f, 14.0f}, (Vector3){28.0f, 4.0f, 22.0f}};
    level.zones[5].position = (Vector3){25.0f, 2.0f, 18.0f};
    strcpy(level.zones[5].name, "Exit");
}

void level_draw() {
    for (int i = 0; i < level.zone_count; i++) {
        BoundingBox box = level.zones[i].bounds;
        Vector3 size = (Vector3){box.max.x - box.min.x, box.max.y - box.min.y, box.max.z - box.min.z};
        Vector3 center = (Vector3){(box.min.x + box.max.x) * 0.5f, (box.min.y + box.max.y) * 0.5f, (box.min.z + box.max.z) * 0.5f};
        Color color = Fade((Color){80, 120, 160, 255}, 0.35f);

        DrawCubeV(center, size, color);
        DrawCubeWiresV(center, size, Fade(RAYWHITE, 0.25f));
    }
}

void level_update() {
}

zone_t* level_get_zone_at(Vector3 pos) {
    for (int i = 0; i < level.zone_count; i++) {
        BoundingBox box = level.zones[i].bounds;
        if (pos.x >= box.min.x && pos.x <= box.max.x &&
            pos.y >= box.min.y && pos.y <= box.max.y &&
            pos.z >= box.min.z && pos.z <= box.max.z) {
            return &level.zones[i];
        }
    }
    return NULL;
}

bool level_is_collision(Vector3 before, Vector3 after) {
    (void)before;
    if (after.y < 1.7f) {
        return true;
    }
    return false;
}

Vector3 level_get_spawn_point() {
    return level.spawn_point;
}

Vector3 level_get_exit_point() {
    return level.exit_point;
}
