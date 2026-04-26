#include "../lib/raylib/src/raylib.h"
#include "header/assets.h"

/*
 * ===================================
 * ASSETS - Gestion des ressources
 * ===================================
 */

static assets_t assets;

void assets_load_models() {
    // À implémenter :
    // Charger tous les modèles 3D depuis assets/models/ :
    // assets.models[0] = LoadModel("assets/models/wall.obj")
    // assets.models[1] = LoadModel("assets/models/stairs.obj")
    // assets.models[2] = LoadModel("assets/models/floor.obj")
    // assets.models[3] = LoadModel("assets/models/doors.obj")
    // etc...
    //
    // assets.model_count = nombre de modèles chargés
}

void assets_load_textures() {
    // À implémenter :
    // Charger toutes les textures depuis assets/textures/ :
    // assets.textures[0] = LoadTexture("assets/textures/rust.png")
    // assets.textures[1] = LoadTexture("assets/textures/concrete.png")
    // assets.textures[2] = LoadTexture("assets/textures/metal.png")
    // etc...
    //
    // assets.texture_count = nombre de textures chargées
}

void assets_load_sounds() {
    // À implémenter :
    // Charger sons depuis assets/sounds/ :
    // assets.sounds[0] = LoadSound("assets/sounds/wind.wav")
    // assets.sounds[1] = LoadSound("assets/sounds/metal_creak.wav")
    // etc...
    //
    // assets.sound_count = nombre de sons chargés
}

bool assets_check_all_loaded() {
    // À implémenter :
    // Vérifier que tous les assets sont chargés :
    // return (assets.model_count > 0 && assets.texture_count > 0 && assets.sound_count > 0)
    return false;
}

Model assets_get_model(const char* name) {
    // À implémenter :
    // Rechercher le modèle par son nom
    // Si trouvé, retourner le Model
    // Sinon, retourner un modèle par défaut ou NULL
    return (Model){0};
}

Texture2D assets_get_texture(const char* name) {
    // À implémenter :
    // Rechercher la texture par son nom
    // Si trouvé, retourner la Texture2D
    // Sinon, retourner texture par défaut (blanche)
    return (Texture2D){0};
}

Sound assets_get_sound(const char* name) {
    // À implémenter :
    // Rechercher le son par son nom
    // Si trouvé, retourner le Sound
    // Sinon, retourner NULL ou silence
    return (Sound){0};
}

void assets_unload_all() {
    // À implémenter :
    // Pour chaque Model chargé :
    //   UnloadModel(assets.models[i])
    // Pour chaque Texture :
    //   UnloadTexture(assets.textures[i])
    // Pour chaque Sound :
    //   UnloadSound(assets.sounds[i])
}
