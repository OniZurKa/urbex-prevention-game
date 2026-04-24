# 🏗️ Architecture du Projet Urbex Prevention Game

## Structure des fichiers

```
src/
├── main.c                   (ANCIENNEMENT - à ignorer)
├── core.c                   ⭐ Point d'entrée principal
├── player.c                 État du joueur et conséquences
├── camera.c                 Caméra FPS
├── level.c                  Gestion du niveau/zones
├── collision.c              Système de collision
├── dangers.c                Détection des dangers
├── ending.c                 Système de fins
├── audio.c                  Système sonore
├── input.c                  Gestion des entrées
├── assets.c                 Chargement des ressources
└── header/
    ├── core.h
    ├── player.h
    ├── camera.h
    ├── level.h
    ├── collision.h
    ├── dangers.h
    ├── ending.h
    ├── audio.h
    ├── input.h
    └── assets.h
```

---

## 📋 Responsabilités de chaque module

### **core.c / core.h**
**Point d'entrée du jeu** - Contrôle principal

```
À implémenter :
- game_init()       → Initialise tout (fenêtre, joueur, caméra, niveau)
- game_run()        → Boucle principale
- game_update()     → Mise à jour chaque frame
- game_draw()       → Rendu chaque frame
- game_cleanup()    → Libère la mémoire
- main()            → Point d'entrée du programme
```

**Dépend de :** Tous les autres modules

---

### **input.c / input.h**
**Gestion des entrées clavier/souris**

```
À implémenter :
- input_update()              → Met à jour l'état des touches
- input_is_forward()          → Retourne si W/Z pressé
- input_is_backward()         → Retourne si S pressé
- input_is_left()             → Retourne si A/Q pressé
- input_is_right()            → Retourne si D pressé
- input_is_jump()             → Retourne si SPACE pressé
- input_is_interact()         → Retourne si E pressé
- input_is_quit()             → Retourne si ESC pressé
- input_get_mouse_delta()     → Retourne mouvement souris
```

**Ordre d'exécution :** 1️⃣ PREMIER (avant tout mouvement)

---

### **camera.c / camera.h**
**Caméra première personne FPS**

```
À implémenter :
- camera_init()               → Initialise caméra
- camera_update()             → Traite inputs pour bouger
- camera_move_forward(dist)   → Avance
- camera_move_backward(dist)  → Recule
- camera_move_left(dist)      → Gauche
- camera_move_right(dist)     → Droite
- camera_rotate(dx, dy)       → Rotation souris
- camera_get_position()       → Retourne position actuelle
- camera_get_forward()        → Retourne vecteur avant
```

**Dépend de :** input.c, collision.c

**Ordre d'exécution :** 2️⃣ Deuxième (après inputs)

---

### **player.c / player.h**
**État du joueur et conséquences**

```
À implémenter :
- player_init()               → Initialise au spawn
- player_update()             → Met à jour position
- player_set_wet()            → Marque comme mouillé
- player_set_danger_zone()    → Marque entrée zone dangers
- player_set_gas()            → Marque inhalation gaz
- player_set_warning_ignored()→ Marque avertissement ignoré
- player_take_damage(amt)     → Inflige dégâts
- player_is_alive()           → Vérifie si vivant
- player_reset()              → Réinitialise pour nouvelle partie
```

**Structure à créer (variables internes) :**
```c
struct {
    bool is_wet;                // Joueur mouillé ?
    bool entered_danger_zone;   // A visité zone dangereuse ?
    bool inhaled_gas;           // A inhalé du gaz ?
    bool ignored_warning;       // A ignoré avertissement ?
    int health;                 // Points de vie (0-100)
    Vector3 position;           // Position actuelle
    Vector3 velocity;           // Vitesse/direction
}
```

**Dépend de :** Rien

---

### **level.c / level.h**
**Gestion du niveau et zones**

```
À implémenter :
- level_init()                → Crée les zones de l'usine
- level_draw()                → Dessine tous les modèles
- level_update()              → Logique du niveau
- level_get_zone_at(pos)      → Retourne zone à position
- level_is_collision(b, a)    → Vérifie collision entre 2 points
- level_get_spawn_point()     → Retourne point d'entrée
- level_get_exit_point()      → Retourne point de sortie
```

**Zones à créer :**
1. **Entrée** - Grillage cassé, panneau interdit
2. **Hall principal** - Zone ouverte avec chemins
3. **Escalier instable** - Danger: chute
4. **Salle eau+câble** - Danger: électrocution si mouillé
5. **Salle gaz** - Danger: intoxication
6. **Sortie** - Accessible selon choix

**Dépend de :** assets.c, collision.c

---

### **collision.c / collision.h**
**Système de collision**

```
À implémenter :
- collision_check_sphere_box(pos, r, box)  → Collision sphère/boîte
- collision_raycast(start, end)            → Rayon de collision
- collision_is_on_ground(pos)              → Joueur sur sol ?
- collision_resolve(old, new, r)           → Calcule position sûre
- collision_init_level(level)              → Enregistre collisions niveau
```

**Utilisé par :** camera.c, player.c

---

### **dangers.c / dangers.h**
**Systèmes de dangers**

```
À implémenter :
- danger_init()               → Crée zones dangereuses
- danger_update()             → Détecte dangers actifs
- danger_apply_wet_damage()   → Applique eau
- danger_apply_electricity()  → Électrocution
- danger_apply_gas()          → Intoxication
- danger_check_fall()         → Détecte chute
- danger_count_active()       → Nombre de dangers actifs
```

**Types de dangers :**
- `DANGER_WET_FLOOR` - Eau sur sol → `is_wet = true`
- `DANGER_ELECTRICITY` - Câble électrique → Électrocution si mouillé
- `DANGER_GAS` - Gaz toxique → `inhaled_gas = true`
- `DANGER_UNSTABLE` - Escalier/sol instable → Chute possible
- `DANGER_HEIGHT` - Zone haute → Dégâts si chute

**Dépend de :** player.c, level.c

---

### **ending.c / ending.h**
**Système de fins du jeu**

```
À implémenter :
- ending_check()              → Vérifie si fin atteinte
- ending_get_current()        → Retourne type de fin actuelle
- ending_display()            → Affiche écran de fin
- ending_get_message()        → Retourne message d'ending
- ending_is_reached()         → Fin atteinte ?
- ending_reset()              → Réinitialise pour nouvelle partie
- ending_calculate()          → Calcule ending selon player state
```

**Fins possibles :**
- `ENDING_ALIVE` - Bonne fin (prudent, survit vivant)
- `ENDING_INJURED` - Fin neutre (survit mais blessé)
- `ENDING_ELECTROCUTION` - Mauvaise fin (électrocution)
- `ENDING_FALL` - Mauvaise fin (chute)
- `ENDING_INTOXICATION` - Mauvaise fin (intoxication)
- `ENDING_NONE` - Jeu en cours

**Dépend de :** player.c

---

### **audio.c / audio.h**
**Système sonore**

```
À implémenter :
- audio_init()                → Initialise système audio
- audio_load_sounds()         → Charge fichiers sons
- audio_play_ambient()        → Lance sons ambiants
- audio_play_sound(type)      → Joue son d'effet
- audio_stop_ambient()        → Arrête ambiance
- audio_set_volume(vol)       → Ajuste volume
- audio_update()              → Met à jour sons
- audio_cleanup()             → Libère ressources audio
```

**Sons à implémenter :**
- Ambiants: vent, grincement métal, craquements
- Effets: splash eau, électricité, pas, mort

---

### **assets.c / assets.h**
**Gestion des ressources**

```
À implémenter :
- assets_load_models()        → Charge modèles 3D
- assets_load_textures()      → Charge textures
- assets_load_sounds()        → Charge sons
- assets_check_all_loaded()   → Vérifie tout chargé
- assets_get_model(name)      → Retourne modèle par nom
- assets_get_texture(name)    → Retourne texture par nom
- assets_get_sound(name)      → Retourne son par nom
- assets_unload_all()         → Libère tout
```

**À créer :**
- Dossier `assets/models/` - Fichiers .obj
- Dossier `assets/textures/` - Fichiers .png
- Dossier `assets/sounds/` - Fichiers .wav/.ogg

---

## 🔄 Ordre d'exécution dans la boucle principale

```
game_run()
├─ BOUCLE PRINCIPALE (tant que !WindowShouldClose())
│  ├─ 1️⃣ input_update()              ← INPUTS (PREMIER)
│  ├─ 2️⃣ camera_update()             ← CAMÉRA (utilise inputs)
│  ├─ 3️⃣ player_update()             ← JOUEUR (utilise caméra)
│  ├─ 4️⃣ danger_update()             ← DANGERS (affecte joueur)
│  ├─ 5️⃣ level_update()              ← NIVEAU
│  ├─ 6️⃣ ending_check()              ← VÉRIFIER FIN
│  │
│  ├─ 7️⃣ game_draw()
│  │  ├─ BeginDrawing()
│  │  ├─ ClearBackground()
│  │  ├─ BeginMode3D(camera)
│  │  ├─ level_draw()
│  │  ├─ EndMode3D()
│  │  ├─ Si fin atteinte: ending_display()
│  │  └─ EndDrawing()
│  │
│  └─ Suivant frame...
```

---

## 🎯 Dépendances entre modules

```
core.c (contrôle tout)
├── input.c
├── camera.c ← input.c, collision.c
├── player.c ← collision.c
├── level.c ← assets.c, collision.c
├── collision.c (utilisé par camera + player)
├── dangers.c ← player.c, level.c
├── ending.c ← player.c
├── audio.c
└── assets.c (chargement seul)
```

---

## 📝 Commentaires dans le code

Chaque fichier .c/. h contient :
- Commentaire en haut expliquant le module
- Pour chaque fonction : commentaire avec ce qu'il faut implémenter
- Exemple souvent donné

**Vous devez coder les fonctions et structures marquées "À implémenter"**

---

## 🚀 Par où commencer ?

**Ordre recommandé :**

1. ✅ `core.c` - Structure principale
2. ✅ `input.c` - Gestion entrées
3. ✅ `camera.c` - Caméra FPS simple
4. ✅ `level.c` - Premiers modèles 3D
5. ✅ `collision.c` - Basic collision
6. ✅ `player.c` - État joueur
7. ✅ `dangers.c` - Zones dangereuses
8. ✅ `ending.c` - Système de fins
9. ✅ `audio.c` - Sons (dernier)
10. ✅ `assets.c` - Ressources (parfois parallèle au reste)

---

## 📚 Ressources Raylib

Voir le fichier **RAYLIB_REFERENCE.txt** pour toutes les fonctions Raylib.

---

**Bon coding ! 🎮**
