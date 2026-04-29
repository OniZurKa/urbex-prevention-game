#include "../lib/raylib/src/raylib.h"
#include "header/audio.h"

/*
 * ===================================
 * AUDIO - Système sonore et ambiance
 * ===================================
 */

 static audio_system_t audio;

void audio_init() {
    InitAudioDevice() ; // Initialise Raylib audio
    SetMasterVolume(0.8f);
    audio.sound_count = 0 ;
    audio.ambient_music = (Music){0};
}

void audio_load_sounds() {
    // À implémenter :
    // Charger des fichiers sons (.mp3, .wav, .ogg) :
    // - Sons ambiants (vent, métal, craquements)
    // - Effets sonores (splash eau, électricité, pas)
    // - Sons de mort
    // 
    // Structure :
    // audio.sounds[0] = LoadSound("assets/wind.wav")
    // audio.sounds[1] = LoadSound("assets/metal.wav")
    // etc...
}

void audio_play_ambient() {
    // À implémenter :
    // - Jouer les sons ambiants en boucle
    // - PlaySoundMulti() pour plusieurs sons simultanés
    // - Ou PlayMusicStream() pour ambient_music
}

void audio_play_sound(sound_type_t type) {
    // À implémenter :
    // switch(type) {
    //   case SOUND_EFFECT_SPLASH : PlaySound(audio.sounds[SPLASH_ID]) break
    //   case SOUND_EFFECT_ELECTRIC : PlaySound(audio.sounds[ELECTRIC_ID]) break
    //   etc...
    // }
}

void audio_stop_ambient() {
    // À implémenter :
    // - StopSoundMulti()
    // - Ou StopMusicStream()
}

void audio_set_volume(float volume) {
    if (volume < 0.0f) {
        volume = 0.0f;
    }
    if (volume > 1.0f) {
        volume = 1.0f;
    }

    SetMasterVolume(volume);
}

void audio_update() {
    // À implémenter :
    // - UpdateMusicStream() si musique jouée
    // - Mettre à jour sons 3D si relevant
    // - Faire jouer sons selon position joueur
}

void audio_cleanup() {
    // À implémenter :
    // - Pour chaque son :
    //   UnloadSound(audio.sounds[i])
    // - UnloadMusicStream() si remusicstream
    // - CloseAudioDevice()
}
