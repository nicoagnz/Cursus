*This project has been created as part of the 42 curriculum by nacuna-g, ctaboada.*

# cub3D

## Description

cub3D is a graphics project based on the raycasting technique, inspired by early 3D games such as Wolfenstein 3D. The goal is to render a pseudo-3D environment from a 2D map using the MLX42 graphical library.

The program parses a `.cub` configuration file that defines textures, colors, and the map layout. It then simulates a first-person perspective by casting rays for each vertical stripe of the screen to determine wall distances and render them accordingly.

This project focuses on:
- File parsing and validation
- Memory management
- Mathematical concepts (trigonometry, projection)
- Real-time rendering
- Event handling

## Instructions

### Compilation

```bash
make
```

### Available rules
```bash
make
make clean
make fclean
make re
```

### Execution
```bash
./cub3d maps/../..
```

## Controls

- W, A, S, D: Move the player
- ←, →: Rotate the camera
- ESC: Exit the program

## Map format
The .cub file must contain:

- Texture paths:
```bash
NO ./path_to_north_texture
SO ./path_to_south_texture
WE ./path_to_west_texture
EA ./path_to_east_texture
```

- Colors:
```bash
F R,G,B
C R,G,B
```

- Map layout:
```bash
111111
100001
10N001
100001
111111
```

Valid characters:
- ```1```: wall
- ```0```: empty space
- ```N, S, E, W```: player starting position

## Resources
Documentation and references:

- [Raycasting](https://lodev.org/cgtutor/raycasting.html)
- [MLX42 (github)](https://github.com/codam-coding-college/MLX42)

## Use of AI
AI tools were used for:
- Clarifying theoretical concepts related to raycasting and projection
- Reviewing parsing strategies and edge cases
- Assisting in debugging specific issues

All implementation decisions, code structure, and final validation were done manually.
