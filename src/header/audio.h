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

// À implémenter :
// 1. typedef enum sound_type_t :
//    - SOUND_AMBIENT_WIND (vent constant)
//    - SOUND_AMBIENT_METAL (grincement métal)
//    - SOUND_AMBIENT_CRACK (craquements)
//    - SOUND_EFFECT_SPLASH (bruit eau)
//    - SOUND_EFFECT_ELECTRIC (bourdonnement électricité)
//    - SOUND_EFFECT_DEATH (mort)
//    - SOUND_EFFECT_STEP (pas)
//
// 2. void audio_init() - Initialise le contexte audio raylib
// 3. void audio_load_sounds() - Charge tous les fichiers sons
// 4. void audio_play_ambient() - Lance les sons ambiants en boucle
// 5. void audio_play_sound(sound_type_t type) - Joue un son
// 6. void audio_stop_ambient() - Arrête les sons ambiants
// 7. void audio_set_volume(float volume) - Ajuste le volume global
// 8. void audio_update() - Met à jour les sons (3D si nécessaire)
// 9. void audio_cleanup() - Libère tous les sons

#endif
