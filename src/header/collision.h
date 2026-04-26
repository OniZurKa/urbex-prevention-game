#ifndef COLLISION_H
#define COLLISION_H

#include <stdbool.h>
#include "../../lib/raylib/src/raylib.h"

typedef struct level_t level_t;

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

typedef struct collision_t {
	bool has_collision;
	Vector3 collision_point;
	Vector3 collision_normal;
	int collision_object_id;
} collision_t;

bool collision_check_sphere_box(Vector3 sphere_pos, float sphere_radius, BoundingBox box) ; // Vérifie collision sphère/boîte (joueur/mur)
collision_t collision_raycast(Vector3 start, Vector3 end) ; // Vérifie collision sur un rayon (pour mouvements)
bool collision_is_on_ground(Vector3 player_pos) ; // Vérifie si joueur est sur le sol
Vector3 collision_resolve(Vector3 old_pos, Vector3 new_pos, float radius) ; // Résout une collision (retourne nouvelle position correcte)
void collision_init_level(level_t* level) ; // Initialise le système avec les collisions du niveau

#endif
