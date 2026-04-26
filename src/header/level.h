#ifndef LEVEL_H
#define LEVEL_H

#include <stdbool.h>
#include "../../lib/raylib/src/raylib.h"

/*
 * ===================================
 * LEVEL - Gestion des niveaux/zones
 * ===================================
 *
 * Responsabilités :
 * - Chargement et structure du niveau
 * - Zones du bâtiment (entrée, hall, zones dangereuses, sortie)
 * - Modèles et positions des objets
 * - Gestion des points de spawn
 */

typedef struct zone_t {
	int type; // ENTRANCE, MAIN_HALL, STAIRS, WATER_ROOM, GAS_ROOM, EXIT
	BoundingBox bounds;
	Vector3 position;
	char name[64];
} zone_t;

typedef struct level_t {
	zone_t zones[10];
	int zone_count;
	Vector3 spawn_point;
	Vector3 exit_point;
} level_t;

void level_init() ; // Crée et initialise le niveau
void level_draw() ; // Dessine tous les modèles du niveau
void level_update() ; // Met à jour la logique du niveau
zone_t* level_get_zone_at(Vector3 pos) ; // Retourne la zone à une position
bool level_is_collision(Vector3 before, Vector3 after) ; // Vérifie collision
Vector3 level_get_spawn_point() ; // Retourne le point de départ
Vector3 level_get_exit_point() ; // Retourne l'exit

#endif
