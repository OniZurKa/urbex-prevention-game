#ifndef CAMERA_H
#define CAMERA_H

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

// À implémenter :
// 1. typedef struct camera_fps_t - Structure contenant :
//    - position (Vector3)
//    - target (Vector3 - où regarde la caméra)
//    - up (Vector3)
//    - fovy (angle de vision vertical)
//    - projection (PERSPECTIVE ou ORTHOGRAPHIC)
//    - vitesse de mouvement
//    - sensibilité souris
//
// 2. void camera_init() - Initialise la caméra FPS
// 3. void camera_update() - Gère les inputs clavier/souris pour déplacer la caméra
// 4. void camera_move_forward(float distance) - Avance la caméra
// 5. void camera_move_backward(float distance) - Recule la caméra
// 6. void camera_move_left(float distance) - Déplace à gauche
// 7. void camera_move_right(float distance) - Déplace à droite
// 8. void camera_rotate(float dx, float dy) - Tourne la vue selon la souris
// 9. Vector3 camera_get_position() - Retourne la position actuelle
// 10. Vector3 camera_get_forward() - Retourne le vecteur avant (direction)

#endif
