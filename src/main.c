#include "../lib/raylib/src/raylib.h"
#include "header/main.h"
#include "header/player.h"
#include "header/camera.h"
#include "header/level.h"
#include "header/input.h"
#include "header/audio.h"
#include "header/ending.h"
#include "header/menu.h"
#include "header/hud.h"
#include "header/pause.h"
#include "header/transition.h"

/*
 * ===================================
 * MAIN - Système principal du jeu
 * ===================================
 */

// Constantes de la fenêtre
#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define FPS 60
#define GAME_TITLE "Urbex Prevention Game"

// Variables globales
static game_state_t game_state;
static bool is_running = false;

void game_init() {
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, GAME_TITLE);
    SetTargetFPS(FPS);
    menu_init_layout(WINDOW_WIDTH, WINDOW_HEIGHT);
    hud_init(WINDOW_WIDTH, WINDOW_HEIGHT);
    pause_init(WINDOW_WIDTH, WINDOW_HEIGHT);
    transition_init(WINDOW_WIDTH, WINDOW_HEIGHT);
    player_init();
    camera_init();
    level_init();
    audio_init();
    input_update();
    game_state = GAME_STATE_MENU;
    is_running = true;
}

void game_run() {
    while (!WindowShouldClose() && is_running) {
         float delta_time = GetFrameTime();
         game_update(delta_time);
         game_draw();
     }
}

void game_update(float delta_time) {

    input_update() ; // Met à jour les contrôles
    transition_update(&game_state, target_state) ; // Gère transitions entre etats
    switch (game_state) {
          case GAME_STATE_MENU:
              menu_update(&game_state, &is_running);
              break;
          case GAME_STATE_PLAYING:
              // game logic...
              // Si ESC -> transition_start(GAME_STATE_PLAYING, GAME_STATE_PAUSED); game_state = GAME_STATE_PAUSED;
              break;
          case GAME_STATE_PAUSED:
              pause_update(&is_running);
              // Selon choix du joueur: transition vers PLAYING, MENU ou QUIT
              break;
          case GAME_STATE_ENDING:
              // ending logic...
              break;
          case GAME_STATE_QUIT:
              is_running = false;
              break;
        }
    hud_update(game_state, delta_time);
    (void)delta_time;
}

void game_draw() {
    BeginDrawing() ;
    switch (game_state) {
          case GAME_STATE_MENU:
              menu_draw(WINDOW_WIDTH, WINDOW_HEIGHT);
              break;
          case GAME_STATE_PLAYING:
              // rendu 3D du jeu + HUD
              // hud_draw_playing();
              break;
          case GAME_STATE_PAUSED:
              // dessiner la scene figée ou fond noir
              // pause_draw_overlay();
              break;
          case GAME_STATE_ENDING:
              // hud_draw_ending();
              break;
          default:
              ClearBackground(BLACK);
              break;
        }
    transition_draw() ; // Affiche l'effet de transition par-dessus
    EndDrawing() ;
}

void game_cleanup() {

    assets_unload_all() ; // Libère ressources
    audio_stop_ambient() ; // Arrête musique
    CloseWindow() ; // Ferme la fenêtre raylib
    is_running = false ;
}

bool game_is_running() {
    return is_running;
}

// Point d'entrée du programme
int main(void) {
    game_init();
    game_run();
    game_cleanup();
    return 0;
}
