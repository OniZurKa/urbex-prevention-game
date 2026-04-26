#include "../lib/raylib/src/raylib.h"
#include "header/pause.h"

static bool pause_active = false;
static int pause_window_width = 0;
static int pause_window_height = 0;

void pause_init(int window_width, int window_height) {
    // A vous d'implementer :
    // - Initialiser les positions/boutons du menu pause
    // - Conserver les dimensions utiles
    pause_window_width = window_width;
    pause_window_height = window_height;
    pause_active = false;
}

void pause_update(bool *is_running) {
    // A vous d'implementer :
    // - Toggle pause (ex: touche ESC)
    // - Navigation clavier/souris des boutons (reprendre/quitter)
    // - Modifier *is_running si le joueur choisit quitter
    (void)is_running;
}

void pause_draw_overlay(void) {
    // A vous d'implementer :
    // - Dessiner un voile semi-transparent
    // - Dessiner panneau PAUSE + boutons
    // - Utiliser pause_window_width/pause_window_height pour le layout
    (void)pause_window_width;
    (void)pause_window_height;
}

bool pause_is_active(void) {
    // A vous d'implementer si besoin d'une logique plus complexe
    return pause_active;
}

void pause_set_active(bool active) {
    // A vous d'implementer si besoin d'effets annexes
    pause_active = active;
}
