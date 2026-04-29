#include "../lib/raylib/src/raylib.h"
#include "header/main.h"
#include "header/player.h"
#include "header/camera.h"
#include "header/level.h"
#include "header/input.h"
#include "header/audio.h"
#include "header/ending.h"
#include "header/menu.h"
#include "header/settings.h"
#include "header/hud.h"
#include "header/pause.h"
#include "header/transition.h"
#include "header/assets.h"
#include "header/collision.h"
#include "header/dangers.h"

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
static game_state_t target_state;

void game_init() {
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, GAME_TITLE);
    SetTargetFPS(FPS);
    menu_init_layout(WINDOW_WIDTH, WINDOW_HEIGHT);
    settings_init_layout(WINDOW_WIDTH, WINDOW_HEIGHT);
    hud_init(WINDOW_WIDTH, WINDOW_HEIGHT);
    pause_init(WINDOW_WIDTH, WINDOW_HEIGHT);
    transition_init(WINDOW_WIDTH, WINDOW_HEIGHT);
    level_init();
    danger_init();
    ending_reset();
    pause_set_active(false);
    player_init();
    camera_init();
    audio_init();
    settings_apply();
    input_update();
    game_state = GAME_STATE_MENU;
    target_state = GAME_STATE_MENU;
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
            case GAME_STATE_MENU: {
                game_state_t prev_state = game_state;
                menu_update(&game_state, &is_running);
                if (game_state != prev_state) {
                  target_state = game_state;
                }
                break;
            }
            case GAME_STATE_SETTINGS: {
                game_state_t prev_state = game_state;
                settings_update(&game_state, &is_running);
                if (game_state != prev_state) {
                  target_state = game_state;
                }
                break;
            }
          case GAME_STATE_PLAYING:
                camera_update();
                if (!transition_is_playing() && input_is_quit()) {
                    target_state = GAME_STATE_PAUSED;
                    pause_set_active(true);
                    transition_start(game_state, target_state);
                }
                break;
          case GAME_STATE_PAUSED:
                pause_update(&is_running);
                // Reprise vers PLAYING via ESC si aucune transition n'est en cours
                if (!transition_is_playing() && input_is_quit()) {
                    target_state = GAME_STATE_PLAYING;
                    pause_set_active(false);
                    transition_start(game_state, target_state);
                }
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
          case GAME_STATE_SETTINGS:
              settings_draw(WINDOW_WIDTH, WINDOW_HEIGHT);
              break;
          case GAME_STATE_PLAYING:
              ClearBackground((Color){18, 24, 32, 255});
              {
                  Vector3 cam_position = camera_get_position();
                  Vector3 cam_forward = camera_get_forward();
                  Camera3D render_camera = {0};

                  render_camera.position = cam_position;
                  render_camera.target = (Vector3){cam_position.x + cam_forward.x, cam_position.y + cam_forward.y, cam_position.z + cam_forward.z};
                  render_camera.up = (Vector3){0.0f, 1.0f, 0.0f};
                  render_camera.fovy = 60.0f;
                  render_camera.projection = CAMERA_PERSPECTIVE;

                  BeginMode3D(render_camera);
                  DrawPlane((Vector3){12.0f, 0.0f, 12.0f}, (Vector2){40.0f, 40.0f}, (Color){55, 62, 68, 255});
                  DrawGrid(20, 1.0f);
                  level_draw();
                  DrawCube(level_get_spawn_point(), 0.5f, 0.5f, 0.5f, GREEN);
                  DrawCube(level_get_exit_point(), 0.7f, 0.7f, 0.7f, GOLD);
                  EndMode3D();
              }
              hud_draw_playing();
              break;
          case GAME_STATE_PAUSED:
              // dessiner la scene figée ou fond noir
              pause_draw_overlay();
              break;
          case GAME_STATE_ENDING:
              hud_draw_ending();
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
