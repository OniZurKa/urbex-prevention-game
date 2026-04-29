#include "../lib/raylib/src/raylib.h"
#include "header/ending.h"
#include "header/player.h"

/*
 * ===================================
 * ENDING - Système de fins du jeu
 * ===================================
 */

static ending_type_t current_ending = ENDING_NONE;

void ending_check(player_t* player) {
    ending_calculate(player);
}

ending_type_t ending_get_current() {
    return current_ending;
}

void ending_display() {
    const char *message = ending_get_message();

    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(BLACK, 0.8f));
    DrawText("FIN DE PARTIE", 60, 60, 48, RAYWHITE);
    DrawText(message, 60, 130, 28, LIGHTGRAY);
    DrawText("R - Recommencer", 60, 210, 24, RAYWHITE);
    DrawText("Q - Quitter", 60, 245, 24, RAYWHITE);
}

const char* ending_get_message() {
    switch (current_ending) {
        case ENDING_ALIVE:
            return "Tu as explore intelligemment... Tu as survecu !";
        case ENDING_INJURED:
            return "Tu as survecu, mais blesse.";
        case ENDING_ELECTROCUTION:
            return "Erreur fatale... Electrocution.";
        case ENDING_FALL:
            return "Chute mortelle.";
        case ENDING_INTOXICATION:
            return "Intoxication par les gaz.";
        case ENDING_NONE:
        default:
            return "Aucune fin atteinte.";
    }
}

bool ending_is_reached() {
    return current_ending != ENDING_NONE;
}

void ending_reset() {
    current_ending = ENDING_NONE;
}

void ending_calculate(player_t* player) {
    if (!player) {
        return;
    }

    if (player->health <= 0) {
        if (player->is_wet && player->ignored_warning) {
            current_ending = ENDING_ELECTROCUTION;
        } else if (player->inhaled_gas) {
            current_ending = ENDING_INTOXICATION;
        } else {
            current_ending = ENDING_FALL;
        }
        return;
    }

    if (player->is_wet || player->entered_danger_zone || player->inhaled_gas || player->ignored_warning) {
        current_ending = ENDING_INJURED;
    } else {
        current_ending = ENDING_ALIVE;
    }
}
