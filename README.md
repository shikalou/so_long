
# 42 project - so_long

## My first very small 2D game in C !

Its purpose is to make you work with textures, sprites,
and some other very basic gameplay elements.
We had to use the minilibx graphic library.

The player’s goal is to collect every collectible present on the map, then escape via an exit !

You can use the ``WASD`` keys AND/OR the ``UP, DOWN, LEFT and RIGHT`` arrows to move your player.


### How to run the program

```bash
  ./so_long [map]
```

To start the program you need a map, some are already ready in the maps/ folder.
Maps need to be a ``.ber`` file, with some specific rules. 
 ### How to create a valid map ?

|elements|value|
| ----------------- | ------------------------------------------------------------------ |
| Walls | 1 |
| Floor | 0 |
| Player | P |
| Collectible | C |
| Exit | E |
| Ennemy | B |

• The map must contain at least 1 exit, at least 1 collectible, and only 1 starting position to
be valid.

• The map must be rectangular.

• The map must be closed/surrounded by walls. If it’s not, the program must return
an error.

here is an exemple of a simple basic map :

```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```


### Screenshots

![solong_game_screenshot](https://github.com/shikalou/so_long/assets/94800038/54eacff4-68eb-4099-93dd-e30aede90012)

### Features

- Map generator made by [@Anonylouis](https://github.com/anonylouis)
