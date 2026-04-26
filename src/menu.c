#include "../lib/raylib/src/raylib.h"
#include "header/menu.h"

static Rectangle start_button = {0};
static Rectangle quit_button = {0};

void menu_init_layout(int window_width, int window_height) {
    float center_x = window_width * 0.5f;
    float base_y = window_height * 0.58f;

    start_button = (Rectangle){center_x - 150.0f, base_y, 300.0f, 56.0f};
    quit_button = (Rectangle){center_x - 150.0f, base_y + 74.0f, 300.0f, 56.0f};
}

void menu_update(game_state_t *state, bool *is_running) {
    Vector2 mouse = GetMousePosition();
    bool hover_start = CheckCollisionPointRec(mouse, start_button);
    bool hover_quit = CheckCollisionPointRec(mouse, quit_button);

    if (IsKeyPressed(KEY_ENTER) || (hover_start && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))) {
        *state = GAME_STATE_PLAYING;
        DisableCursor();
        return;
    }

    if (IsKeyPressed(KEY_Q) || (hover_quit && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))) {
        *state = GAME_STATE_QUIT;
        *is_running = false;
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

void menu_draw(int window_width, int window_height) {
    Vector2 mouse = GetMousePosition();
    bool hover_start = CheckCollisionPointRec(mouse, start_button);
    bool hover_quit = CheckCollisionPointRec(mouse, quit_button);

    DrawRectangleGradientV(0, 0, window_width, window_height,
                           (Color){10, 18, 28, 255},
                           (Color){28, 40, 54, 255});

    DrawCircle((int)(window_width * 0.82f), (int)(window_height * 0.18f), 130.0f, Fade(SKYBLUE, 0.08f));
    DrawCircle((int)(window_width * 0.12f), (int)(window_height * 0.78f), 200.0f, Fade(DARKBLUE, 0.10f));

    DrawRectangleRounded((Rectangle){180, 90, window_width - 360, window_height - 180}, 0.05f, 8, Fade(BLACK, 0.38f));
    DrawRectangleRoundedLinesEx((Rectangle){180, 90, window_width - 360, window_height - 180}, 0.05f, 8, 2.0f, Fade(RAYWHITE, 0.18f));

    DrawText("URBEX PREVENTION", 340, 170, 64, RAYWHITE);
    DrawText("Explore. Observe. Decide.", 460, 250, 28, Fade(LIGHTGRAY, 0.95f));

    DrawText("Un jeu narratif FPS dans une usine abandonnee", 360, 320, 24, Fade(LIGHTGRAY, 0.80f));
    DrawText("Faites des choix invisibles et assumez les consequences", 310, 355, 24, Fade(LIGHTGRAY, 0.80f));

    draw_button(start_button, "COMMENCER", hover_start, (Color){44, 120, 88, 255});
    draw_button(quit_button, "QUITTER", hover_quit, (Color){140, 64, 64, 255});

    DrawText("ENTREE: jouer   |   Q: quitter", 470, 620, 22, Fade(RAYWHITE, 0.75f));
}
