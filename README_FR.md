# cub3D

Un moteur de raycasting simple inspire de Wolfenstein 3D.

## Description

cub3D est un moteur de jeu 3D utilisant des techniques de raycasting pour afficher un labyrinthe en perspective a la premiere personne. Le projet utilise la bibliotheque graphique MiniLibX.

## Fonctionnalites

- Rendu 3D en temps reel par raycasting
- Murs textures
- Couleurs de sol et plafond configurables
- Navigation a la premiere personne
- Analyse de carte depuis fichiers .cub

## Prerequis

- Systeme d'exploitation Linux
- Compilateur gcc
- Bibliotheque MiniLibX
- Bibliotheque X11
- Bibliotheque Math

## Installation

```bash
make
```

## Utilisation

```bash
./cub3D maps/map_ok.cub
```

Remplacez `maps/map_ok.cub` par n'importe quel fichier de carte .cub valide.

## Controles

- **W/A/S/D**: Avancer/gauche/reculer/droite
- **Fleches directionnelles**: Rotation de la camera gauche/droite
- **ESC**: Quitter le jeu

## Configuration de carte

Les cartes doivent etre au format .cub avec:
- Chemins des textures (NO, SO, WE, EA)
- Couleur du sol (F)
- Couleur du plafond (C)
- Disposition de la carte (1 pour les murs, 0 pour l'espace vide, N/S/E/W pour le spawn du joueur)
