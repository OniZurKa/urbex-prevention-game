#ifndef CAMERA_H
#define CAMERA_H

#include "../../lib/raylib/src/raylib.h"

/*
 * ===================================
 * CAMERA - Gestion caméra FPS
 * ===================================
 *
 * Responsabilités :
 * - Caméra première personne
 * - Mouvements avant/arrière/gauche/droite
 * - Rotation de la vue (souris)
 * - Collision avec les murs
 */

typedef struct camera_fps_t {
	Vector3 position;
	Vector3 target;
	Vector3 up;
	float fovy;
	int projection;
	float speed;
	float mouse_sens;
} camera_fps_t;

void camera_init() ; // Initialise la caméra FPS
void camera_update() ; // Gère les inputs clavier/souris pour déplacer la caméra
void camera_move_forward(float distance) ; // Avance la caméra
void camera_move_backward(float distance) ; // Recule la caméra
void camera_move_left(float distance) ; // Déplace à gauche
void camera_move_right(float distance) ; // Déplace à droite
void camera_rotate(float dx, float dy) ; // Tourne la vue selon la souris
void camera_set_mouse_sensitivity(float mouse_sensitivity) ; // Définit la sensibilité souris
Vector3 camera_get_position() ; // Retourne la position actuelle
Vector3 camera_get_forward() ; // Retourne le vecteur avant (direction)

#endif
