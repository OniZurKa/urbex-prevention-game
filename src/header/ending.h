#ifndef ENDING_H
#define ENDING_H

#include <stdbool.h>
#include "player.h"

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


typedef enum {
     ENDING_ALIVE, // bonne fin - sort vivant sain et sauf
     ENDING_INJURED, // fin neutre - survit mais blessé
     ENDING_ELECTROCUTION, // mauvaise fin
     ENDING_FALL, // mauvaise fin
     ENDING_INTOXICATION, // mauvaise fin
     ENDING_NONE // encore en jeu
} ending_type_t ;

void ending_check(player_t* player) ; // Vérifie si conditions de fin sont atteintes
ending_type_t ending_get_current() ; // Retourne la fin actuelle
void ending_display() ; // Affiche l'écran de fin avec message
const char* ending_get_message() ; // Retourne le message d'ending
bool ending_is_reached() ; // Vérifie si une fin est atteinte
void ending_reset() ; // Réinitialise pour nouvelle partie
void ending_calculate(player_t* player) ; // Calcule l'ending basé sur player.state

#endif
