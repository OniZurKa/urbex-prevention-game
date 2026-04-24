========================
PROJET JEU URBEX - RÉSUMÉ
========================

CONCEPT
--------
Jeu d’exploration 3D en vue FPS dans une usine abandonnée.
Le joueur incarne un jeune qui fait de l’urbex.

Le jeu a un objectif de prévention :
montrer les dangers réels de l’urbex à travers l’expérience du joueur.

Le joueur explore librement et ses actions ont des conséquences.


OBJECTIF DU JEU
---------------
Le but n’est pas simplement de gagner, mais de :
- explorer un lieu abandonné
- observer l’environnement
- prendre des décisions
- survivre ou mourir selon ses choix

Le jeu doit faire réfléchir sans être moralisateur.


BOUCLE DE GAMEPLAY
------------------
1. Le joueur entre dans l’usine
2. Il explore librement
3. Il rencontre des situations dangereuses
4. Il agit (ou ignore les dangers)
5. Le jeu enregistre ses actions
6. Une fin est atteinte selon ses choix

Le joueur peut recommencer pour découvrir d’autres issues.


MÉCANIQUE PRINCIPALE
--------------------
Système de "choix invisibles"

Pas de menu de dialogue.
Les choix sont faits par :
- les déplacements
- les interactions
- l’attention du joueur

Exemples :
- marcher dans de l’eau
- ignorer un bruit suspect
- entrer dans une zone dangereuse


SYSTÈME DE CONSÉQUENCES
-----------------------
Variables internes simples :

- is_wet
- entered_danger_zone
- inhaled_gas
- ignored_warning

Ces variables influencent la fin du jeu.


LES FINS
--------
Bonne fin :
- joueur prudent
- observe son environnement
- évite les dangers
→ sort vivant

Fin neutre :
- erreurs mais survit
→ blessé ou choqué

Mauvaises fins :
- électrocution
- chute
- intoxication
→ mort du joueur

Chaque fin sert d’apprentissage.


LEVEL DESIGN (USINE)
--------------------
Structure simple :

1. Entrée
- grillage cassé
- panneau interdit

2. Hall principal
- grande zone ouverte
- plusieurs chemins

3. Zones dangereuses
- escalier instable (chute)
- eau + câble (électricité)
- salle avec gaz (intoxication)

4. Sortie
- accessible selon les décisions


AMBIANCE
--------
Très importante pour le jeu :

- sons (craquements, vent, métal)
- éclairage faible ou instable
- silence

L’immersion est prioritaire sur les graphismes.


DIRECTION ARTISTIQUE
--------------------
Style simple / low poly

Avantages :
- plus rapide à produire
- adapté à un projet solo
- efficace pour créer une ambiance


TECHNIQUE
---------
- langage : C
- bibliothèque : Raylib
- rendu : 3D FPS
- compilation : Makefile multi-OS
- dépendances incluses dans le repo


SCOPE (VERSION 1)
-----------------
- 1 bâtiment
- 3 à 4 zones
- 3 à 5 fins
- 10 à 20 minutes de jeu

Objectif : projet terminé et jouable.


POINTS FORTS DU PROJET
----------------------
- expérience immersive
- décisions naturelles
- message réel
- rejouabilité basée sur les choix


À ÉVITER
--------
- vouloir faire un jeu trop grand
- ajouter trop de systèmes
- interface trop complexe
- mélanger trop de technologies (ex : HTML)


Objectif : obtenir rapidement un prototype jouable.