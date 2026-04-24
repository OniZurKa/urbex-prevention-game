#include "raylib.h"
#include "header/dangers.h"
#include "header/player.h"

/*
 * ===================================
 * DANGERS - Systèmes de dangers
 * ===================================
 */

// À implémenter :
// typedef enum {
//     DANGER_WET_FLOOR,
//     DANGER_ELECTRICITY,
//     DANGER_GAS,
//     DANGER_UNSTABLE,
//     DANGER_HEIGHT
// } danger_type_t;
//
// typedef struct {
//     danger_type_t type;
//     BoundingBox bounds;
//     bool is_active;
//     float damage_per_frame;
// } danger_zone_t;
//
// static danger_zone_t dangers[20];
// static int danger_count = 0;

void danger_init() {
    // À implémenter :
    // - Créer danger_zone_t pour chaque danger du niveau
    // - Eau + câble (électricité)
    // - Gaz toxique (salle)
    // - Escalier instable (chute)
    // - Zones hautes (chute si tombent)
    // - Enregistrer dans le tableau dangers[]
}

void danger_update(player_t* player) {
    // À implémenter :
    // - Pour chaque zone dangereuse active :
    //   1. Vérifier si joueur est dedans
    //   2. Appliquer les conséquences appropriées
    //   3. Marquer variables du joueur
}

void danger_apply_wet_damage(player_t* player) {
    // À implémenter :
    // - player_set_wet()
    // - Ajouter dégâts si conséquence majeure
}

void danger_apply_electricity(player_t* player) {
    // À implémenter :
    // - Si joueur mouillé ET près du câble = électrocution
    // - player_take_damage() important
}

void danger_apply_gas(player_t* player) {
    // À implémenter :
    // - player_set_gas()
    // - Dégâts progressifs si reste trop longtemps
}

void danger_check_fall(player_t* player) {
    // À implémenter :
    // - Vérifier si joueur tombe d'une hauteur
    // - Calculer dégâts selon hauteur
    // - player_take_damage()
}

int danger_count_active() {
    // À implémenter :
    // Compter combien de zones dangereuses sont actives
    // return danger_count;
    return 0;
}
