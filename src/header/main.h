#ifndef MAIN_H
#define MAIN_H

/*
 * ===================================
 * MAIN - Système principal du jeu
 * ===================================
 * 
 * Responsabilités :
 * - Initialisation de la fenêtre et du contexte raylib
 * - Boucle principale du jeu
 * - Gestion des états globaux
 * - Cleanup et fermeture
 */

typedef enum {
	GAME_STATE_MENU,
	GAME_STATE_SETTINGS,
	GAME_STATE_PLAYING,
	GAME_STATE_PAUSED,
	GAME_STATE_ENDING,
	GAME_STATE_QUIT
} game_state_t;

void game_init() ; // Initialise tout (fenêtre, raylib, joueur, niveau)
void game_run() ; // Boucle principale du jeu
void game_update(float delta_time) ; // Met à jour la logique du jeu chaque frame
void game_draw() ; // Dessine tout à chaque frame
void game_cleanup() ; // Libère la mémoire et ferme le contexte
bool game_is_running() ; // Retourne si le jeu tourne toujours

#endif
