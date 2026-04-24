#ifndef PLAYER_H
#define PLAYER_H

/*
 * ===================================
 * PLAYER - État et conséquences
 * ===================================
 *
 * Responsabilités :
 * - Suivi des variables de conséquences
 * - Détection des actions dangereuses
 * - Mise à jour de l'état du joueur
 * - Vérification des conditions de fin
 */

// À implémenter :
// 1. typedef struct player_t - Structure contenant :
//    - is_wet (booléen)
//    - entered_danger_zone (booléen)
//    - inhaled_gas (booléen)
//    - ignored_warning (booléen)
//    - health (points de vie)
//    - position (Vector3)
//    - autres variables nécessaires
//
// 2. void player_init() - Initialise le joueur
// 3. void player_update() - Met à jour l'état du joueur
// 4. void player_set_wet() - Marque le joueur comme mouillé
// 5. void player_set_danger_zone() - Marque l'entrée dans une zone dangereuse
// 6. void player_set_gas() - Marque l'inhalation de gaz
// 7. void player_set_warning_ignored() - Marque l'ignorance d'un avertissement
// 8. void player_take_damage(int amount) - Inflige des dégâts
// 9. bool player_is_alive() - Vérifie si le joueur est vivant
// 10. void player_reset() - Réinitialise pour une nouvelle partie

#endif
