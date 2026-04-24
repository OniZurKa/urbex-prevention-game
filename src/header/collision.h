#ifndef COLLISION_H
#define COLLISION_H

/*
 * ===================================
 * COLLISION - Système de collision
 * ===================================
 *
 * Responsabilités :
 * - Détection de collision
 * - Réaction aux collisions
 * - Gestion des murs, objets, sol
 */

// À implémenter :
// 1. typedef struct collision_t - Structure collision :
//    - has_collision (booléen)
//    - collision_point (Vector3)
//    - collision_normal (Vector3)
//    - collision_object_id (pour savoir ce qu'on a heurté)
//
// 2. bool collision_check_sphere_box(Vector3 sphere_pos, float sphere_radius, BoundingBox box)
//    - Vérifie collision sphère/boîte (joueur/mur)
//
// 3. collision_t collision_raycast(Vector3 start, Vector3 end)
//    - Vérifie collision sur un rayon (pour mouvements)
//
// 4. bool collision_is_on_ground(Vector3 player_pos)
//    - Vérifie si joueur est sur le sol
//
// 5. Vector3 collision_resolve(Vector3 old_pos, Vector3 new_pos, float radius)
//    - Résout une collision (retourne nouvelle position correcte)
//
// 6. void collision_init_level(level_t* level)
//    - Initialise le système avec les collisions du niveau

#endif
