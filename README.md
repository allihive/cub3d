# Cub3D

Welcome to **Cub3D** a.k.a Cute3D! 🎀

This project is part of the 42(Hive Helsinki) curriculum, aiming to create a dynamic 3D maze experience inspired by classic games like Wolfenstein 3D. It utilizes raycasting techniques to render a 3D perspective within a 2D map.


## Features

- **3D Rendering with Raycasting:**  
  Experience a pseudo-3D environment generated using efficient raycasting algorithms.

- **Player Movement:**  
  Navigate the maze with smooth controls for movement and rotation.

- **Texture Mapping:**  
  Walls and surfaces are enhanced with detailed textures for a realistic appearance.

- **Map Parsing:**  
  Load and interpret custom map files to define the game environment.

## Prerequisites

Before building and running Cub3D, ensure you have the following:

- **C Compiler:**  
  A C compiler such as GCC or Clang with support for C99 or higher.

- **MLX42:**  
  The MLX42 library is required for graphical rendering.

- **X11 Libraries (for Linux users):**  
  Ensure you have the necessary X11 libraries installed. On Debian-based systems, you can install them using:  
  `sudo apt-get install libx11-dev libxext-dev`

## Getting Started

To run Cub3D locally:

1. **Clone the Repository:**  
   ```bash
   git clone https://github.com/ito-miyuki/cub3d.git
2. **Navigate to the Project Directory:**  
   ```bash
   cd cub3d
3. **Initialize and Update Submodules (if applicable):**  
   ```bash
   git submodule update --init --recursive
4. **Build the Project:**
   ```bash
   make
5. **Run the Game:**  
   ```bash
   ./cub3d path/to/map.cub
Replace `path/to/map.cub` with the path to a valid map file.

## Controls

- **Move Forward:** `W`
- **Move Backward:** `S`
- **Strafe Left:** `A`
- **Strafe Right:** `D`
- **Rotate View Left:** Left Arrow Key
- **Rotate View Right:** Right Arrow Key
- **Exit Game:** `ESC` Key

## Map Configuration

Cub3D uses `.cub` files to define the game maps. A typical map file includes:

- **Textures:**  
  Paths to texture files for walls in different directions. Example:  
  `NO ./textures/north.png`  
  `SO ./textures/south.png`  
  `WE ./textures/west.png`  
  `EA ./textures/east.png`

- **Colors:**  
  RGB values for the floor and ceiling colors. Example:  
  `F 220,100,0`  
  `C 225,30,0`

- **Map Layout:**  
  A grid representing walls (`1`), empty spaces (`0`), and the player's starting position (`N`, `S`, `E`, `W`).

## Acknowledgements

This project was created in collaboration with my school bestie, [Alice](https://github.com/allihive). Working together on Cub3D has been an incredible learning journey and a lot of fun!✨

---

Thank you for exploring Cub3D. Dive into the maze and enjoy the adventure! 🚀
