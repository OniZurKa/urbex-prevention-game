#ifndef ASSETS_H
#define ASSETS_H

#include <stdbool.h>
#include "../../lib/raylib/src/raylib.h"

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

#define ASSETS_MAX_MODELS 20
#define ASSETS_MAX_TEXTURES 20
#define ASSETS_MAX_SOUNDS 20

typedef struct assets_t {
	Model models[ASSETS_MAX_MODELS];
	Texture2D textures[ASSETS_MAX_TEXTURES];
	Sound sounds[ASSETS_MAX_SOUNDS];
	int model_count;
	int texture_count;
	int sound_count;
} assets_t;

void assets_load_models() ; // Charge tous les modèles 3D
void assets_load_textures() ; // Charge les textures
void assets_load_sounds() ; // Charge les sons
bool assets_check_all_loaded() ; // Vérifie que tout est chargé
Model assets_get_model(const char* name) ; // Retourne un modèle par nom
Texture2D assets_get_texture(const char* name) ; // Retourne une texture par nom
Sound assets_get_sound(const char* name) ; // Retourne un son par nom
void assets_unload_all() ; // Libère toutes les ressources

#endif
