#ifndef ENDING_H
#define ENDING_H

/*
 * ===================================
 * ENDING - Système de fins du jeu
 * ===================================
 *
 * Responsabilités :
 * - Détermination de l'ending en fonction des choix
 * - Affichage de l'écran de fin
 * - Génération des messages
 */

// À implémenter :
// 1. typedef enum ending_type_t :
//    - ENDING_ALIVE (bonne fin - sort vivant sain et sauf)
//    - ENDING_INJURED (fin neutre - survit mais blessé)
//    - ENDING_ELECTROCUTION (mauvaise fin)
//    - ENDING_FALL (mauvaise fin)
//    - ENDING_INTOXICATION (mauvaise fin)
//    - ENDING_NONE (encore en jeu)
//
// 2. void ending_check(player_t* player) - Vérifie si conditions de fin sont atteintes
// 3. ending_type_t ending_get_current() - Retourne la fin actuelle
// 4. void ending_display() - Affiche l'écran de fin avec message
// 5. const char* ending_get_message() - Retourne le message d'ending
// 6. bool ending_is_reached() - Vérifie si une fin est atteinte
// 7. void ending_reset() - Réinitialise pour nouvelle partie
// 8. void ending_calculate(player_t* player) - Calcule l'ending basé sur player.state

#endif
