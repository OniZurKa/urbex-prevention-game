#ifndef AUDIO_H
#define AUDIO_H

/*
 * ===================================
 * AUDIO - Système sonore et ambiance
 * ===================================
 *
 * Responsabilités :
 * - Gestion des sons ambiants
 * - Effets sonores (craquements, vent, métal)
 * - Gestion du volume
 * - Création d'ambiance immersive
 */

typedef enum {
    SOUND_AMBIENT_WIND,
    SOUND_AMBIENT_METAL,
    SOUND_AMBIENT_CRACK,
    SOUND_EFFECT_SPLASH,
    SOUND_EFFECT_ELECTRIC,
    SOUND_EFFECT_DEATH,
    SOUND_EFFECT_STEP
} sound_type_t;

typedef struct {
    Sound sounds[20];
    int sound_count;
    Music ambient_music;
} audio_system_t;

// À implémenter :
// 2. void audio_init() - Initialise le contexte audio raylib
// 3. void audio_load_sounds() - Charge tous les fichiers sons
// 4. void audio_play_ambient() - Lance les sons ambiants en boucle
// 5. void audio_play_sound(sound_type_t type) - Joue un son
// 6. void audio_stop_ambient() - Arrête les sons ambiants
// 7. void audio_set_volume(float volume) - Ajuste le volume global
// 8. void audio_update() - Met à jour les sons (3D si nécessaire)
// 9. void audio_cleanup() - Libère tous les sons

#endif
