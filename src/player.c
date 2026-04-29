#include "../lib/raylib/src/raylib.h"
#include "header/player.h"
#include "header/level.h"

/*
 * ===================================
 * PLAYER - État et conséquences
 * ===================================
 */

static player_t player;

void player_init() {
    player.is_wet = false;
    player.entered_danger_zone = false;
    player.inhaled_gas = false;
    player.ignored_warning = false;
    player.health = 100;
    player.position = level_get_spawn_point();
    player.velocity = (Vector3){0.0f, 0.0f, 0.0f};
}

void player_update() {
    player.position = level_get_spawn_point();
    player.velocity = (Vector3){0.0f, 0.0f, 0.0f};
}

void player_set_wet() {
    player.is_wet = true;
}

void player_set_danger_zone() {
    player.entered_danger_zone = true;
}

void player_set_gas() {
    player.inhaled_gas = true;
}

void player_set_warning_ignored() {
    player.ignored_warning = true;
}

void player_take_damage(int amount) {
    player.health -= amount;
    if (player.health < 0) player.health = 0;
}

bool player_is_alive() {
    return player.health > 0;
}

void player_reset() {
    player_init();
}
