#ifndef DANGERS_H
#define DANGERS_H

#include <stdbool.h>
#include "../../lib/raylib/src/raylib.h"

typedef struct player_t player_t;

/*
 * ===================================
 * DANGERS - Systèmes de dangers
 * ===================================
 *
 * Responsabilités :
 * - Détection des zones dangereuses
 * - Application des conséquences
 * - Gestion des effets (électrocution, chute, gaz)
 */


typedef enum {
     DANGER_WET_FLOOR, // eau sur le sol
     DANGER_ELECTRICITY, // câble électrique
     DANGER_GAS, // gaz toxique
     DANGER_UNSTABLE, // escalier / sol instable - chute
     DANGER_HEIGHT // zone haute - chute si on tombe
} danger_type_t ;

typedef struct danger_zone_t {
     danger_type_t type;
     BoundingBox bounds;
     bool is_active;
     float damage_per_frame;
} danger_zone_t;
//
// 3. void danger_init() - Initialise tous les dangers du niveau
// 4. void danger_update(player_t* player) - Détecte si joueur est en danger
// 5. void danger_apply_wet_damage(player_t* player) - Ajoute eau sur joueur
// 6. void danger_apply_electricity(player_t* player) - Électrocute
// 7. void danger_apply_gas(player_t* player) - Intoxique
// 8. void danger_check_fall(player_t* player) - Détecte chute
// 9. int danger_count_active() - Retourne combien de zones dangereuses actives

#endif
