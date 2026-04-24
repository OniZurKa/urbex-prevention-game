#ifndef ASSETS_H
#define ASSETS_H

/*
 * ===================================
 * ASSETS - Gestion des ressources
 * ===================================
 *
 * Responsabilités :
 * - Chargement des modèles 3D
 * - Chargement des textures
 * - Chargement des sons
 * - Gestion de la mémoire des ressources
 */

// À implémenter :
// 1. typedef struct assets_t :
//    - modèles[] (Model - structures Raylib)
//    - textures[] (Texture2D - images Raylib)
//    - sounds[] (Sound - sons Raylib)
//    - model_count
//    - texture_count
//    - sound_count
//
// 2. void assets_load_models() - Charge tous les modèles 3D
// 3. void assets_load_textures() - Charge les textures
// 4. void assets_load_sounds() - Charge les sons
// 5. bool assets_check_all_loaded() - Vérifie que tout est chargé
// 6. Model assets_get_model(const char* name) - Retourne un modèle par nom
// 7. Texture2D assets_get_texture(const char* name) - Retourne une texture par nom
// 8. Sound assets_get_sound(const char* name) - Retourne un son par nom
// 9. void assets_unload_all() - Libère toutes les ressources

#endif
