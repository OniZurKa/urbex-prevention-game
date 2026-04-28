# Urbex Prevention Game

Jeu narratif en C avec raylib, orienté prévention des risques liés à l'urbex.

## Vision du projet

Le joueur explore une usine abandonnée en vue FPS et prend des décisions implicites via ses déplacements et ses interactions.
L'objectif n'est pas un score, mais l'apprentissage par les conséquences.

## État actuel

Le projet est en phase prototype. Les éléments déjà présents:

- boucle principale et gestion des états de jeu
- menu principal interactif
- écran paramètres avec volume, sensibilité souris et option plein écran
- sauvegarde des paramètres dans settings.cfg
- base de modules séparés (audio, caméra, collisions, dangers, ending, etc.)

Les systèmes gameplay 3D complets (exploration, collisions avancées, fins dynamiques) sont encore à finaliser dans plusieurs modules.

## Stack technique

- langage: C
- rendu: raylib
- build: Makefile multi-plateforme (macOS, Linux, Windows)

## Structure du dépôt

- src: code source du jeu
- src/header: en-têtes des modules
- lib/raylib: sous-module/bibliothèque raylib incluse dans le dépôt
- obj: objets de compilation
- bin: exécutable final
- settings.cfg: configuration utilisateur (volume, souris, plein écran)
- Base.md: vision produit et scope gameplay
- ARCHITECTURE.md: découpage modulaire et responsabilités

## Prérequis

### macOS

- Xcode Command Line Tools (clang, make)
- frameworks système OpenGL/Cocoa/IOKit/CoreAudio/CoreVideo (déjà référencés dans le Makefile)

### Linux

- gcc
- make
- dépendances OpenGL usuelles (GL, pthread, dl, rt)

### Windows

- gcc/MinGW ou environnement compatible Makefile

## Compilation

Depuis la racine du projet:

make

L'exécutable est généré dans bin.

## Exécution

make run

## Nettoyage

make clean

Rebuild complet:

make re

## Configuration utilisateur

Les paramètres sont stockés dans settings.cfg:

- volume: 0.00 à 2.00
- mouse_sensitivity: 0.05 à 2.00
- fullscreen: 0 ou 1

## Contrôles actuellement disponibles

- menu principal: souris (clic gauche)
- retour/quitter: ESC selon l'écran
- écran paramètres: boutons souris pour ajuster les options

## Feuille de route recommandée

- finaliser input.c et camera.c pour un contrôle FPS complet
- implémenter le gameplay principal dans l'état PLAYING
- connecter dangers, collisions et endings aux choix du joueur
- améliorer l'adaptation du rendu à toutes les résolutions
- ajouter tests manuels de non-régression (menu, settings, transitions)

## Documentation complémentaire

- voir Base.md pour la direction design et pédagogique
- voir ARCHITECTURE.md pour le plan de modules et l'ordre d'implémentation

## Licence

Aucune licence explicite n'est définie pour le projet applicatif à ce stade.
La bibliothèque raylib conserve sa propre licence dans lib/raylib/LICENSE.
