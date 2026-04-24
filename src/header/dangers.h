#ifndef DANGERS_H
#define DANGERS_H

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

// À implémenter :
// 1. typedef enum danger_type_t :
//    - DANGER_WET_FLOOR (eau sur le sol)
//    - DANGER_ELECTRICITY (câble électrique)
//    - DANGER_GAS (gaz toxique)
//    - DANGER_UNSTABLE (escalier/sol instable - chute)
//    - DANGER_HEIGHT (zone haute - chute si on tombe)
//
// 2. typedef struct danger_zone_t - Définit une zone dangereuse :
//    - type (danger_type_t)
//    - bounds (BoundingBox)
//    - is_active (booléen)
//    - damage_per_frame (ou effet instantané)
//
// 3. void danger_init() - Initialise tous les dangers du niveau
// 4. void danger_update(player_t* player) - Détecte si joueur est en danger
// 5. void danger_apply_wet_damage(player_t* player) - Ajoute eau sur joueur
// 6. void danger_apply_electricity(player_t* player) - Électrocute
// 7. void danger_apply_gas(player_t* player) - Intoxique
// 8. void danger_check_fall(player_t* player) - Détecte chute
// 9. int danger_count_active() - Retourne combien de zones dangereuses actives

#endif
