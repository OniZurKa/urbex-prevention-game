#ifndef INPUT_H
#define INPUT_H

#include <stdbool.h>
#include "../../lib/raylib/src/raylib.h"

/*
 * ===================================
 * INPUT - Gestion des entrées
 * ===================================
 *
 * Responsabilités :
 * - Gestion des touches clavier
 * - Gestion de la souris
 * - Détection d'interações
 */

typedef struct input_t {
	bool key_forward;
	bool key_backward;
	bool key_left;
	bool key_right;
	bool key_jump;
	bool key_interact;
	bool key_quit;
	float mouse_x;
	float mouse_y;
} input_t;

void input_update() ; // Met à jour l'état des entrées chaque frame
bool input_is_forward() ; // Retourne si avant est pressé
bool input_is_backward() ; // Retourne si arrière est pressé
bool input_is_left() ; // Retourne si gauche est pressé
bool input_is_right() ; // Retourne si droite est pressé
bool input_is_jump() ; // Retourne si saut est pressé
bool input_is_interact() ; // Retourne si E est pressé
bool input_is_quit() ; // Retourne si ESC est pressé
Vector2 input_get_mouse_delta() ; // Retourne mouvement souris

#endif
