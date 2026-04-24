#ifndef LEVEL_H
#define LEVEL_H

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

// À implémenter :
// 1. typedef struct zone_t - Définit une zone :
//    - type (ENTRANCE, MAIN_HALL, STAIRS, WATER_ROOM, GAS_ROOM, EXIT)
//    - bounds (BoundingBox pour les collisions)
//    - position
//    - name (pour debug)
//
// 2. typedef struct level_t - Contient :
//    - zones[] - Tableau de zones
//    - zone_count - Nombre de zones
//    - objets 3D (modèles chargés)
//    - positions/rotations des objets
//    - spawn_point (Vector3)
//
// 3. void level_init() - Crée et initialise le niveau
// 4. void level_draw() - Dessine tous les modèles du niveau
// 5. void level_update() - Met à jour la logique du niveau
// 6. zone_t* level_get_zone_at(Vector3 pos) - Retourne la zone à une position
// 7. bool level_is_collision(Vector3 before, Vector3 after) - Vérifie collision
// 8. Vector3 level_get_spawn_point() - Retourne le point de départ
// 9. Vector3 level_get_exit_point() - Retourne l'exit

#endif
