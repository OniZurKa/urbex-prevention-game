#include "raylib.h"
#include "header/player.h"
#include "header/level.h"

/*
 * ===================================
 * PLAYER - État et conséquences
 * ===================================
 */

// À implémenter :
// typedef struct {
//     bool is_wet;
//     bool entered_danger_zone;
//     bool inhaled_gas;
//     bool ignored_warning;
//     int health;
//     Vector3 position;
//     Vector3 velocity;
// } player_t;
//
// static player_t player;

void player_init() {
    // À implémenter :
    // - Initialiser position au spawn point du niveau
    // - health = 100
    // - Tous les booléens = false
    // - velocity = {0, 0, 0}
}

void player_update() {
    // À implémenter :
    // - Met à jour position/velocity
    // - Applique gravité
    // - Vérifie si mouvement possible (collision)
    // - Applique conséquences si nécessaire
}

void player_set_wet() {
    // À implémenter :
    // player.is_wet = true;
}

void player_set_danger_zone() {
    // À implémenter :
    // player.entered_danger_zone = true;
}

void player_set_gas() {
    // À implémenter :
    // player.inhaled_gas = true;
}

void player_set_warning_ignored() {
    // À implémenter :
    // player.ignored_warning = true;
}

void player_take_damage(int amount) {
    // À implémenter :
    // player.health -= amount;
    // if (player.health < 0) player.health = 0;
}

bool player_is_alive() {
    // À implémenter :
    // return player.health > 0;
    return true;
}

void player_reset() {
    // À implémenter :
    // Appeler player_init() pour réinitialiser
    player_init();
}
