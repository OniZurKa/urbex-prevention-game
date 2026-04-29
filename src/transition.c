#include "../lib/raylib/src/raylib.h"
#include "header/transition.h"

static int transition_window_width = 0;
static int transition_window_height = 0;
static bool transition_playing = false;
static float transition_duration = 0.0f;
static float transition_elapsed = 0.0f;

void transition_init(int window_width, int window_height) {
    transition_window_width = window_width;
    transition_window_height = window_height;
    transition_playing = false;
    transition_elapsed = 0.0f;
    transition_duration = 0.5f;
}

void transition_update(game_state_t *current_state, game_state_t target_state) {
    if (!transition_playing || !current_state) {
        return;
    }

    transition_elapsed += GetFrameTime();

    if (transition_elapsed >= transition_duration * 0.5f && *current_state != target_state) {
        *current_state = target_state;
    }

    if (transition_elapsed >= transition_duration) {
        transition_playing = false;
        transition_elapsed = 0.0f;
    }
}

void transition_draw(void) {
    if (!transition_playing) {
        return;
    }

    float half_duration = transition_duration * 0.5f;
    float alpha = 0.0f;

    if (transition_elapsed <= half_duration) {
        alpha = transition_elapsed / half_duration;
    } else {
        alpha = 1.0f - ((transition_elapsed - half_duration) / half_duration);
    }

    if (alpha < 0.0f) {
        alpha = 0.0f;
    }
    if (alpha > 1.0f) {
        alpha = 1.0f;
    }

    DrawRectangle(0, 0, transition_window_width, transition_window_height, Fade(BLACK, alpha));
}

void transition_start(game_state_t from, game_state_t to) {
    (void)from;
    (void)to;
    transition_playing = true;
    transition_elapsed = 0.0f;
}

bool transition_is_playing(void) {
    return transition_playing;
}
