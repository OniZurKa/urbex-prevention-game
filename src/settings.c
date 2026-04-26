#include "../lib/raylib/src/raylib.h"
#include <stdio.h>
#include "header/audio.h"
#include "header/camera.h"
#include "header/settings.h"

static Rectangle back_button = {0};
static Rectangle volume_minus_button = {0};
static Rectangle volume_plus_button = {0};
static Rectangle sensitivity_minus_button = {0};
static Rectangle sensitivity_plus_button = {0};
static Rectangle fullscreen_button = {0};
static Rectangle reset_button = {0};
static Rectangle save_button = {0};
static Rectangle panel_rect = {0};
static float settings_volume = 1.0f;
static float settings_mouse_sensitivity = 1.0f;
static bool settings_fullscreen = false;
static float save_message_timer = 0.0f;

#define SETTINGS_PANEL_WIDTH 700.0f
#define SETTINGS_PANEL_HEIGHT 530.0f
#define SETTINGS_MARGIN_X 60.0f
#define SETTINGS_LABEL_X_OFFSET 60.0f
#define SETTINGS_ROW_START_Y 110.0f
#define SETTINGS_ROW_STEP_Y 80.0f
#define SETTINGS_TEXT_SIZE 28
#define SETTINGS_BUTTON_W 56.0f
#define SETTINGS_BUTTON_H 56.0f
#define SETTINGS_ACTION_W 300.0f
#define SETTINGS_ACTION_H 56.0f

static const char *settings_file_path = "settings.cfg";

static void settings_clamp_values(void) {
    if (settings_volume < 0.0f) {
        settings_volume = 0.0f;
    }
    if (settings_volume > 2.0f) {
        settings_volume = 2.0f;
    }

    if (settings_mouse_sensitivity < 0.05f) {
        settings_mouse_sensitivity = 0.05f;
    }
    if (settings_mouse_sensitivity > 2.0f) {
        settings_mouse_sensitivity = 2.0f;
    }
}

static void settings_save(void) {
    FILE *file = fopen(settings_file_path, "w");
    if (!file) {
        return;
    }

    fprintf(file, "volume=%.2f\n", settings_volume);
    fprintf(file, "mouse_sensitivity=%.3f\n", settings_mouse_sensitivity);
    fprintf(file, "fullscreen=%d\n", settings_fullscreen ? 1 : 0);
    fclose(file);
    save_message_timer = 1.5f;
}

static void settings_set_defaults(void) {
    settings_volume = 1.0f;
    settings_mouse_sensitivity = 1.0f;
    settings_fullscreen = false;
}

static void settings_apply_values(void) {
    settings_clamp_values();
    audio_set_volume(settings_volume);
    camera_set_mouse_sensitivity(settings_mouse_sensitivity);

    if (settings_fullscreen != IsWindowFullscreen()) {
        ToggleFullscreen();
    }
}

void settings_load(void) {
    FILE *file = fopen(settings_file_path, "r");
    char line[128];

    settings_set_defaults();

    if (!file) {
        settings_clamp_values();
        return;
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        float float_value = 0.0f;
        int int_value = 0;

        if (sscanf(line, "volume=%f", &float_value) == 1) {
            settings_volume = float_value;
        } else if (sscanf(line, "mouse_sensitivity=%f", &float_value) == 1) {
            settings_mouse_sensitivity = float_value;
        } else if (sscanf(line, "fullscreen=%d", &int_value) == 1) {
            settings_fullscreen = (int_value != 0);
        }
    }

    fclose(file);
    settings_clamp_values();
}

void settings_apply(void) {
    settings_apply_values();
}

void settings_init_layout(int window_width, int window_height) {
    EnableCursor();

    float center_x = window_width * 0.5f;
    float center_y = window_height * 0.5f;

    settings_load();

    panel_rect = (Rectangle){
        center_x - SETTINGS_PANEL_WIDTH * 0.5f,
        center_y - SETTINGS_PANEL_HEIGHT * 0.5f,
        SETTINGS_PANEL_WIDTH,
        SETTINGS_PANEL_HEIGHT
    };

    float label_x = panel_rect.x + SETTINGS_LABEL_X_OFFSET;
    float controls_right_x = panel_rect.x + panel_rect.width - 60.0f;
    float row_y = panel_rect.y + SETTINGS_ROW_START_Y;
    float button_y = row_y - 10.0f;

    volume_minus_button = (Rectangle){controls_right_x - 180.0f, button_y, SETTINGS_BUTTON_W, SETTINGS_BUTTON_H};
    volume_plus_button = (Rectangle){controls_right_x - 120.0f, button_y, SETTINGS_BUTTON_W, SETTINGS_BUTTON_H};
    sensitivity_minus_button = (Rectangle){controls_right_x - 180.0f, button_y + SETTINGS_ROW_STEP_Y, SETTINGS_BUTTON_W, SETTINGS_BUTTON_H};
    sensitivity_plus_button = (Rectangle){controls_right_x - 120.0f, button_y + SETTINGS_ROW_STEP_Y, SETTINGS_BUTTON_W, SETTINGS_BUTTON_H};
    fullscreen_button = (Rectangle){label_x, button_y + SETTINGS_ROW_STEP_Y * 2.0f, SETTINGS_ACTION_W, SETTINGS_ACTION_H};
    reset_button = (Rectangle){label_x, button_y + SETTINGS_ROW_STEP_Y * 3.0f, SETTINGS_ACTION_W, SETTINGS_ACTION_H};
    save_button = (Rectangle){panel_rect.x + 35.0f + panel_rect.width - SETTINGS_ACTION_W - SETTINGS_LABEL_X_OFFSET, panel_rect.y + panel_rect.height - 88.0f, SETTINGS_ACTION_W, SETTINGS_ACTION_H};
    back_button = (Rectangle){label_x, panel_rect.y + panel_rect.height - 88.0f, SETTINGS_ACTION_W, SETTINGS_ACTION_H};
}

void settings_update(game_state_t *state, bool *is_running) {
    (void)is_running;

    Vector2 mouse = GetMousePosition();
    bool hover_back = CheckCollisionPointRec(mouse, back_button);
    bool hover_volume_minus = CheckCollisionPointRec(mouse, volume_minus_button);
    bool hover_volume_plus = CheckCollisionPointRec(mouse, volume_plus_button);
    bool hover_sensitivity_minus = CheckCollisionPointRec(mouse, sensitivity_minus_button);
    bool hover_sensitivity_plus = CheckCollisionPointRec(mouse, sensitivity_plus_button);
    bool hover_fullscreen = CheckCollisionPointRec(mouse, fullscreen_button);
    bool hover_reset = CheckCollisionPointRec(mouse, reset_button);
    bool hover_save = CheckCollisionPointRec(mouse, save_button);

    if (IsKeyPressed(KEY_ESCAPE) || (hover_back && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))) {
        *state = GAME_STATE_MENU;
        return;
    }

    if (hover_volume_minus && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        settings_volume -= 0.1f;
        settings_clamp_values();
        audio_set_volume(settings_volume);
    }

    if (hover_volume_plus && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        settings_volume += 0.1f;
        settings_clamp_values();
        audio_set_volume(settings_volume);
    }

    if (hover_sensitivity_minus && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        settings_mouse_sensitivity -= 0.1f;
        settings_clamp_values();
        camera_set_mouse_sensitivity(settings_mouse_sensitivity);
    }

    if (hover_sensitivity_plus && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        settings_mouse_sensitivity += 0.1f;
        settings_clamp_values();
        camera_set_mouse_sensitivity(settings_mouse_sensitivity);
    }

    if (hover_fullscreen && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        ToggleFullscreen();
        settings_fullscreen = IsWindowFullscreen();
    }

    if (hover_reset && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        bool fullscreen_was = IsWindowFullscreen();
        settings_set_defaults();
        settings_fullscreen = fullscreen_was;
        settings_apply_values();
    }

    if (hover_save && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        settings_fullscreen = IsWindowFullscreen();
        settings_save();
    }

    if (save_message_timer > 0.0f) {
        save_message_timer -= GetFrameTime();
        if (save_message_timer < 0.0f) {
            save_message_timer = 0.0f;
        }
    }
}

static void draw_button(Rectangle btn, const char *text, bool hover, Color base) {
    Color fill = hover ? Fade(base, 0.95f) : Fade(base, 0.75f);
    Color border = hover ? RAYWHITE : Fade(RAYWHITE, 0.65f);
    int font_size = 28;
    int text_width = MeasureText(text, font_size);

    DrawRectangleRounded(btn, 0.25f, 8, fill);
    DrawRectangleRoundedLinesEx(btn, 0.25f, 8, 2.0f, border);
    DrawText(text,
             (int)(btn.x + (btn.width - text_width) * 0.5f),
             (int)(btn.y + (btn.height - font_size) * 0.5f),
             font_size,
             RAYWHITE);
}

void settings_draw(int window_width, int window_height) {
    Vector2 mouse = GetMousePosition();
    bool hover_back = CheckCollisionPointRec(mouse, back_button);
    bool hover_volume_minus = CheckCollisionPointRec(mouse, volume_minus_button);
    bool hover_volume_plus = CheckCollisionPointRec(mouse, volume_plus_button);
    bool hover_sensitivity_minus = CheckCollisionPointRec(mouse, sensitivity_minus_button);
    bool hover_sensitivity_plus = CheckCollisionPointRec(mouse, sensitivity_plus_button);
    bool hover_fullscreen = CheckCollisionPointRec(mouse, fullscreen_button);
    bool hover_reset = CheckCollisionPointRec(mouse, reset_button);
    bool hover_save = CheckCollisionPointRec(mouse, save_button);

    DrawRectangleGradientV(0, 0, window_width, window_height,
                           (Color){10, 18, 28, 255},
                           (Color){28, 40, 54, 255});

    DrawCircle((int)(window_width * 0.82f), (int)(window_height * 0.18f), 130.0f, Fade(SKYBLUE, 0.08f));
    DrawCircle((int)(window_width * 0.12f), (int)(window_height * 0.78f), 200.0f, Fade(DARKBLUE, 0.10f));

    DrawRectangleRounded(panel_rect, 0.06f, 8, Fade(BLACK, 0.38f));
    DrawRectangleRoundedLinesEx(panel_rect, 0.06f, 8, 2.0f, Fade(RAYWHITE, 0.18f));

    DrawText("PARAMETRES", (int)(panel_rect.x + 60.0f), (int)(panel_rect.y + 40.0f), 42, RAYWHITE);
    DrawText("Volume", (int)(panel_rect.x + 60.0f), (int)(panel_rect.y + SETTINGS_ROW_START_Y), SETTINGS_TEXT_SIZE, Fade(LIGHTGRAY, 0.95f));
    DrawText(TextFormat("%.0f%%", settings_volume * 100.0f), (int)(panel_rect.x + 390.0f), (int)(panel_rect.y + SETTINGS_ROW_START_Y), SETTINGS_TEXT_SIZE, RAYWHITE);
    DrawText("Sensibilite souris", (int)(panel_rect.x + 60.0f), (int)(panel_rect.y + SETTINGS_ROW_START_Y + SETTINGS_ROW_STEP_Y), SETTINGS_TEXT_SIZE, Fade(LIGHTGRAY, 0.95f));
    DrawText(TextFormat("%.2f", settings_mouse_sensitivity), (int)(panel_rect.x + 390.0f), (int)(panel_rect.y + SETTINGS_ROW_START_Y + SETTINGS_ROW_STEP_Y), SETTINGS_TEXT_SIZE, RAYWHITE);

    draw_button(volume_minus_button, "-", hover_volume_minus, (Color){80, 80, 80, 255});
    draw_button(volume_plus_button, "+", hover_volume_plus, (Color){80, 80, 80, 255});
    draw_button(sensitivity_minus_button, "-", hover_sensitivity_minus, (Color){80, 80, 80, 255});
    draw_button(sensitivity_plus_button, "+", hover_sensitivity_plus, (Color){80, 80, 80, 255});
    draw_button(fullscreen_button, IsWindowFullscreen() ? "PLEIN ECRAN : OUI" : "PLEIN ECRAN : NON", hover_fullscreen, (Color){60, 96, 140, 255});
    draw_button(reset_button, "REINITIALISER", hover_reset, (Color){140, 100, 40, 255});
    draw_button(save_button, "SAUVEGARDER", hover_save, (Color){44, 120, 88, 255});
    draw_button(back_button, "RETOUR", hover_back, (Color){44, 120, 88, 255});

    if (save_message_timer > 0.0f) {
        DrawText("Sauvegarde appliquee", (int)(panel_rect.x + 60.0f), (int)(panel_rect.y + panel_rect.height - 28.0f), 20, Fade(RAYWHITE, 0.85f));
    }
}