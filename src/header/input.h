#ifndef INPUT_H
#define INPUT_H

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

// À implémenter :
// 1. typedef struct input_t :
//    - key_forward (W/Z) - booléen
//    - key_backward (S) - booléen
//    - key_left (A/Q) - booléen
//    - key_right (D) - booléen
//    - key_jump (SPACE) - booléen
//    - key_interact (E) - booléen
//    - key_quit (ESC) - booléen
//    - mouse_x (position X)
//    - mouse_y (position Y)
//
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
