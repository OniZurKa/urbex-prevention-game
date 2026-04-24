#include "raylib.h"
#include "header/collision.h"

/*
 * ===================================
 * COLLISION - Système de collision
 * ===================================
 */

// À implémenter :
// typedef struct {
//     bool has_collision;
//     Vector3 collision_point;
//     Vector3 collision_normal;
//     int collision_object_id;
// } collision_t;

bool collision_check_sphere_box(Vector3 sphere_pos, float sphere_radius, BoundingBox box) {
    // À implémenter :
    // Algorithme AABB-Sphere collision :
    // 1. Trouver le point le plus proche de la sphère dans la boîte
    // 2. Calculer la distance entre ce point et le centre de la sphère
    // 3. Si distance <= rayon, collision
    // Utiliser CheckCollisionSphereBox() ou implémenter manuellement
    return false;
}

collision_t collision_raycast(Vector3 start, Vector3 end) {
    // À implémenter :
    // Lancer un rayon de start à end et détecter collision
    // Utiliser GetRayCollisionBox() ou GetRayCollisionSphere()
    // Retourner collision_t avec infos de collision
    collision_t col = {false, {0,0,0}, {0,0,0}, -1};
    return col;
}

bool collision_is_on_ground(Vector3 player_pos) {
    // À implémenter :
    // Lancer un rayon vers le bas (raycaster downward)
    // Vérifier s'il y a collision avec le sol en-dessous
    // Retourner true si joueur sur le sol
    return false;
}

Vector3 collision_resolve(Vector3 old_pos, Vector3 new_pos, float radius) {
    // À implémenter :
    // Si collision entre old_pos et new_pos :
    // - Recalculer la position pour éviter la collision
    // - Retourner nouvelle position sûre
    // Sinon :
    // - Retourner new_pos
    return new_pos;
}

void collision_init_level(level_t* level) {
    // À implémenter :
    // - Enregistrer les boîtes de collision du niveau
    // - Initialiser les structures de collision
}
