#include "raylib.h"
#include "header/ending.h"
#include "header/player.h"

/*
 * ===================================
 * ENDING - Système de fins du jeu
 * ===================================
 */

// À implémenter :
// typedef enum {
//     ENDING_ALIVE,
//     ENDING_INJURED,
//     ENDING_ELECTROCUTION,
//     ENDING_FALL,
//     ENDING_INTOXICATION,
//     ENDING_NONE
// } ending_type_t;
//
// static ending_type_t current_ending = ENDING_NONE;

void ending_check(player_t* player) {
    // À implémenter :
    // Arrêter le jeu et déterminer la fin selon l'état du joueur
    // Appeler ending_calculate(player)
}

ending_type_t ending_get_current() {
    // À implémenter :
    // return current_ending;
    return 0;
}

void ending_display() {
    // À implémenter :
    // Afficher un écran avec :
    // - Le type de fin (texte + couleur)
    // - Message explicatif
    // - Bouton "Recommencer"
    // - Bouton "Quitter"
}

const char* ending_get_message() {
    // À implémenter :
    // Retourner le message correspondant à l'ending :
    // "Tu as exploré intelligemment... Tu as survécu!"  (ALIVE)
    // "Tu as survécu mais blessé..."  (INJURED)
    // "Erreur fatale... Électrocution"  (ELECTROCUTION)
    // "Chute mortelle..."  (FALL)
    // "Intoxication par les gaz..."  (INTOXICATION)
    return "";
}

bool ending_is_reached() {
    // À implémenter :
    // return current_ending != ENDING_NONE;
    return false;
}

void ending_reset() {
    // À implémenter :
    // current_ending = ENDING_NONE;
}

void ending_calculate(player_t* player) {
    // À implémenter :
    // Logique complexe pour déterminer l'ending :
    //
    // Si joueur est mort (health <= 0) :
    //   - Si electrocuted && wet = ENDING_ELECTROCUTION
    //   - Si fall = ENDING_FALL
    //   - Si intoxicated = ENDING_INTOXICATION
    //
    // Si joueur vivant mais a touché plusieurs dangers :
    //   = ENDING_INJURED
    //
    // Si joueur a été prudent (pas de dégâts majeurs) :
    //   = ENDING_ALIVE
    //
    // Sinon = ENDING_HURT ou variante
}
