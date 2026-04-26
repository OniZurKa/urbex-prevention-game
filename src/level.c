#include <stddef.h>
#include "../lib/raylib/src/raylib.h"
#include "header/level.h"
#include "header/assets.h"

/*
 * ===================================
 * LEVEL - Gestion des niveaux/zones
 * ===================================
 */

static level_t level;

void level_init() {
    // À implémenter :
    // 1. Créer et initialiser les zones de l'usine :
    //    - Entrée
    //    - Hall principal
    //    - Escalier instable
    //    - Salle avec eau/câble
    //    - Salle avec gaz
    //    - Sortie
    // 2. Définir spawn_point (entrée)
    // 3. Définir exit_point
    // 4. Charger les modèles 3D des zones
    // 5. Initialiser les collisions
}

void level_draw() {
    // À implémenter :
    // Pour chaque zone du niveau :
    // - Appeler DrawModel() avec le bon modèle
    // - Positionner et afficher l'objet
    // 
    // Optionnel : utiliser DrawModelEx() pour rotation/scaling
}

void level_update() {
    // À implémenter :
    // - Mise à jour des animations si relevant
    // - Changements d'éclairage
    // - Logique spécifique aux zones
}

zone_t* level_get_zone_at(Vector3 pos) {
    // À implémenter :
    // - Parcourir les zones
    // - Vérifier si position se trouve dans bounds d'une zone
    // - Retourner la zone encontrée ou NULL
    return NULL;
}

bool level_is_collision(Vector3 before, Vector3 after) {
    // À implémenter :
    // - Vérifier collision entre before et after
    // - Utiliser collision_raycast() ou collision_check_sphere_box()
    // - Retourner true si collision
    return false;
}

Vector3 level_get_spawn_point() {
    // À implémenter :
    // return level.spawn_point;
    return (Vector3){0, 0, 0};
}

Vector3 level_get_exit_point() {
    // À implémenter :
    // return level.exit_point;
    return (Vector3){0, 0, 0};
}
