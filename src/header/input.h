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

// 2. void input_update() - Met à jour l'état des entrées chaque frame
// 3. bool input_is_forward() - Retourne si avant est pressé
// 4. bool input_is_backward() - Retourne si arrière est pressé
// 5. bool input_is_left() - Retourne si gauche est pressé
// 6. bool input_is_right() - Retourne si droite est pressé
// 7. bool input_is_jump() - Retourne si saut est pressé
// 8. bool input_is_interact() - Retourne si E est pressé
// 9. bool input_is_quit() - Retourne si ESC est pressé
// 10. Vector2 input_get_mouse_delta() - Retourne mouvement souris

#endif
