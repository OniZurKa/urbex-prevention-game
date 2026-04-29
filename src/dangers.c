#include "../lib/raylib/src/raylib.h"
#include "header/dangers.h"
#include "header/player.h"

/*
 * ===================================
 * DANGERS - Systèmes de dangers
 * ===================================
 */

static danger_zone_t dangers[20];
static int danger_count = 0;

void danger_init() {
    danger_count = 4;

    dangers[0].type = DANGER_WET_FLOOR;
    dangers[0].bounds = (BoundingBox){(Vector3){-1.5f, 0.0f, 11.0f}, (Vector3){6.0f, 2.0f, 17.5f}};
    dangers[0].is_active = true;
    dangers[0].damage_per_frame = 0.0f;

    dangers[1].type = DANGER_ELECTRICITY;
    dangers[1].bounds = (BoundingBox){(Vector3){1.0f, 0.0f, 12.0f}, (Vector3){3.5f, 2.5f, 15.0f}};
    dangers[1].is_active = true;
    dangers[1].damage_per_frame = 5.0f;

    dangers[2].type = DANGER_GAS;
    dangers[2].bounds = (BoundingBox){(Vector3){10.5f, 0.0f, 14.5f}, (Vector3){19.5f, 3.5f, 23.5f}};
    dangers[2].is_active = true;
    dangers[2].damage_per_frame = 2.0f;

    dangers[3].type = DANGER_UNSTABLE;
    dangers[3].bounds = (BoundingBox){(Vector3){16.0f, 0.0f, 5.5f}, (Vector3){20.5f, 5.0f, 12.5f}};
    dangers[3].is_active = true;
    dangers[3].damage_per_frame = 1.0f;
}

void danger_update(player_t* player) {
    if (!player) {
        return;
    }

    for (int i = 0; i < danger_count; i++) {
        if (!dangers[i].is_active) {
            continue;
        }

        if (player->position.x < dangers[i].bounds.min.x || player->position.x > dangers[i].bounds.max.x ||
            player->position.y < dangers[i].bounds.min.y || player->position.y > dangers[i].bounds.max.y ||
            player->position.z < dangers[i].bounds.min.z || player->position.z > dangers[i].bounds.max.z) {
            continue;
        }

        switch (dangers[i].type) {
            case DANGER_WET_FLOOR:
                danger_apply_wet_damage(player);
                break;
            case DANGER_ELECTRICITY:
                danger_apply_electricity(player);
                break;
            case DANGER_GAS:
                danger_apply_gas(player);
                break;
            case DANGER_UNSTABLE:
                danger_check_fall(player);
                break;
            case DANGER_HEIGHT:
                danger_check_fall(player);
                break;
        }
    }
}

void danger_apply_wet_damage(player_t* player) {
    if (!player) {
        return;
    }

    player_take_damage(1);
}

void danger_apply_electricity(player_t* player) {
    if (!player) {
        return;
    }

    player_set_danger_zone();
    player_take_damage(player->is_wet ? 30 : 10);
}

void danger_apply_gas(player_t* player) {
    if (!player) {
        return;
    }

    player_take_damage(3);
}

void danger_check_fall(player_t* player) {
    if (!player) {
        return;
    }

    if (player->position.y < 0.0f) {
        player_set_warning_ignored();
        player_take_damage(20);
    }
}

int danger_count_active() {
    return danger_count;
}
