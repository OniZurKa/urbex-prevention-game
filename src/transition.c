#include "../lib/raylib/src/raylib.h"
#include "header/transition.h"

static int transition_window_width = 0;
static int transition_window_height = 0;
static bool transition_playing = false;
static float transition_duration = 0.0f;
static float transition_elapsed = 0.0f;

void transition_init(int window_width, int window_height) {
    // A vous d'implementer :
    // - Stocker les dimensions
    // - Initialiser parametres de transition (duree, couleur, type, etc.)
    // - Precharger assets transition si necessaire
    transition_window_width = window_width;
    transition_window_height = window_height;
    transition_playing = false;
    transition_elapsed = 0.0f;
    transition_duration = 0.5f;
}

void transition_update(game_state_t *current_state, game_state_t target_state) {
    // A vous d'implementer :
    // - Si transition_playing :
    //   * Incrementer transition_elapsed selon GetFrameTime()
    //   * Si transition_elapsed >= transition_duration :
    //     - *current_state = target_state
    //     - transition_playing = false
    // - Gerer les cas ou plusieurs transitions se chevauchent
    (void)current_state;
    (void)target_state;
}

void transition_draw(void) {
    // A vous d'implementer :
    // - Si transition_playing :
    //   * Calculer progression (0.0 -> 1.0)
    //   * Dessiner effet de transition (fade, wipe, etc.)
    //   * Utiliser transition_window_width/transition_window_height
    (void)transition_window_width;
    (void)transition_window_height;
}

void transition_start(game_state_t from, game_state_t to) {
    // A vous d'implementer :
    // - Verifier que de l'etat 'from' on peut aller a 'to'
    // - Initialiser les parametres de transition selon couple (from, to)
    // - Commencer l'animation
    // - Adapter duree/style selon destination
    (void)from;
    (void)to;
    transition_playing = true;
    transition_elapsed = 0.0f;
}

bool transition_is_playing(void) {
    // A vous d'implementer si besoin d'une logique plus complexe
    return transition_playing;
}
