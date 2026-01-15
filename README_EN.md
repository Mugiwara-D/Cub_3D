# cub3D

A simple raycasting engine inspired by Wolfenstein 3D.

## Description

cub3D is a 3D game engine using raycasting techniques to render a first-person perspective maze. The project uses the MiniLibX graphics library.

## Features

- Real-time raycasting 3D rendering
- Textured walls
- Configurable floor and ceiling colors
- First-person navigation
- Map parsing from .cub files

## Requirements

- Linux operating system
- gcc compiler
- MiniLibX library
- X11 library
- Math library

## Installation

```bash
make
```

## Usage

```bash
./cub3D maps/map_ok.cub
```

Replace `maps/map_ok.cub` with any valid .cub map file.

## Controls

- **W/A/S/D**: Move forward/left/backward/right
- **Arrow Keys**: Rotate camera left/right
- **ESC**: Exit the game

## Map Configuration

Maps must be in .cub format with:
- Texture paths (NO, SO, WE, EA)
- Floor color (F)
- Ceiling color (C)
- Map layout (1 for walls, 0 for empty space, N/S/E/W for player spawn)
