#include "raylib.h"
#include "header/core.h"
#include "header/player.h"
#include "header/camera.h"
#include "header/level.h"
#include "header/input.h"
#include "header/audio.h"
#include "header/ending.h"

/*
 * ===================================
 * CORE - Système principal du jeu
 * ===================================
 */

// Constantes de la fenêtre
#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define FPS 60
#define GAME_TITLE "Urbex Prevention Game"

// Variables globales (à implémenter)
// static game_state_t game_state;
// static bool is_running = false;

void game_init() {
    // À implémenter :
    // 1. InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, GAME_TITLE)
    // 2. SetTargetFPS(FPS)
    // 3. Appeler player_init()
    // 4. Appeler camera_init()
    // 5. Appeler level_init()
    // 6. Appeler audio_init()
    // 7. Appeler input_update()
    // 8. is_running = true
}

void game_run() {
    // À implémenter :
    // Boucle principale :
    // while (!WindowShouldClose()) {
    //     float delta_time = GetFrameTime()
    //     game_update(delta_time)
    //     game_draw()
    // }
}

void game_update(float delta_time) {
    // À implémenter :
    // 1. input_update() - Met à jour les contrôles
    // 2. camera_update() - Met à jour la caméra
    // 3. player_update() - Met à jour l'état du joueur
    // 4. danger_update() - Cherhce les dangers
    // 5. level_update() - Logique du niveau
    // 6. ending_check() - Vérifie si fin atteinte
}

void game_draw() {
    // À implémenter :
    // 1. BeginDrawing()
    // 2. ClearBackground(BLACK)
    // 3. BeginMode3D(camera)
    // 4. level_draw() - Dessine le niveau
    // 5. EndMode3D()
    // 6. // Affichage 2D (UI, debug)
    // 7. if (ending_is_reached()) ending_display()
    // 8. EndDrawing()
}

void game_cleanup() {
    // À implémenter :
    // 1. assets_unload_all() - Libère ressources
    // 2. audio_stop_ambient() - Arrête musique
    // 3. CloseWindow() - Ferme la fenêtre raylib
    // 4. is_running = false
}

bool game_is_running() {
    // À implémenter :
    // return is_running;
    return false;
}

// Point d'entrée du programme
int main(void) {
    game_init();
    game_run();
    game_cleanup();
    return 0;
}
