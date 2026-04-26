#include "../lib/raylib/src/raylib.h"
#include "header/hud.h"

static int hud_window_width = 0;
static int hud_window_height = 0;

void hud_init(int window_width, int window_height) {
    // A vous d'implémenter :
    // - Stocker dimensions utiles au layout HUD
    // - Initialiser styles, couleurs, positions, etc.
    hud_window_width = window_width;
    hud_window_height = window_height;
}

void hud_update(game_state_t state, float delta_time) {
    // A vous d'implémenter :
    // - Mettre a jour animations HUD
    // - Mettre a jour timers, transitions, notifications
    // - Adapter selon l'etat (MENU/PLAYING/ENDING)
    (void)state;
    (void)delta_time;
}

void hud_draw_playing(void) {
    // A vous d'implémenter :
    // - Afficher crosshair / infos joueur / aides contextuelles
    // - Afficher debug minimal si necessaire
    // - Utiliser hud_window_width/hud_window_height pour le placement
    (void)hud_window_width;
    (void)hud_window_height;
}

void hud_draw_ending(void) {
    // A vous d'implémenter :
    // - Afficher panneau de fin (titre, message, options)
    // - Afficher boutons recommencer / quitter
    (void)hud_window_width;
    (void)hud_window_height;
}
