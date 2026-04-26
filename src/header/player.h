#ifndef PLAYER_H
#define PLAYER_H

#include <stdbool.h>
#include "../../lib/raylib/src/raylib.h"

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

typedef struct player_t {
	bool is_wet;
	bool entered_danger_zone;
	bool inhaled_gas;
	bool ignored_warning;
	int health;
	Vector3 position;
	Vector3 velocity;
} player_t;

void player_init() ; // Initialise le joueur
void player_update() ; // Met à jour l'état du joueur
void player_set_wet() ; // Marque le joueur comme mouillé
void player_set_danger_zone() ; // Marque l'entrée dans une zone dangereuse
void player_set_gas() ; // Marque l'inhalation de gaz
void player_set_warning_ignored() ; // Marque l'ignorance d'un avertissement
void player_take_damage(int amount) ; // Inflige des dégâts
bool player_is_alive() ; // Vérifie si le joueur est vivant
void player_reset() ; // Réinitialise pour une nouvelle partie

#endif
