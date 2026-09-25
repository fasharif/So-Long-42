# so_long

[![CI](https://github.com/fasharif/So-Long-42/actions/workflows/ci.yml/badge.svg)](https://github.com/fasharif/So-Long-42/actions/workflows/ci.yml)

A small 2D game in C, built on MiniLibX for the 42 Abu Dhabi curriculum. You move around a tile
map, pick up every collectible, then reach the exit. The bonus version adds an enemy, animated
walls, and the move count shown in the window.

## Play

The bundled MiniLibX uses OpenGL and AppKit, so the game runs on macOS.

```bash
cd so_long            # or so_long_bonus
make                  # builds ../minilibx first
./so_long maps/map.ber
```

| Key | Action |
| --- | --- |
| W, A, S, D | Move |
| Esc, or the window's close button | Quit |

Each move is counted in the terminal. You win by reaching the exit after picking up every
collectible. In the bonus version, walking into the enemy loses the game.

## Maps

Maps are text files ending in `.ber`, one row per line:

| Character | Meaning |
| --- | --- |
| `1` | Wall |
| `0` | Floor |
| `P` | Where the player starts |
| `C` | Collectible |
| `E` | Exit |
| `N` | Enemy (bonus version only) |

A valid map is rectangular, closed in by walls, and has a start, an exit and at least one
collectible. This is `so_long/maps/map.ber`:

```
11111111111111111111111111111
10100101001000001010010000001
10100100101010100010010000001
1P0000000C00C000000C000000001
1E0000000000000C00000C0000001
1010010100100C001010010000001
10100100101010100010010000001
1C0000000C00100C00000C0000001
11111111111111111111111111111
```

Anything else (a wrong number of arguments, a missing file, a name without `.ber`, or an invalid
map) prints `Error` and a short explanation on standard error, and the program exits with status 1.

## Testing

[`tests/run_map_checks.sh`](tests/run_map_checks.sh) runs both versions against bad input and checks
that each one prints `Error` and exits with status 1 rather than crashing. The bad input covers
wrong arguments, a wrong extension, a missing file, and invalid maps, including an empty file and
one larger than the map buffer. GitHub Actions builds MiniLibX and both versions on macOS with
warnings treated as errors, then runs these checks. A valid map opens a window, so the gameplay
itself is tested by hand.

## Limitations

- macOS only. Linux would need the X11 version of MiniLibX (minilibx-linux) and X11 key codes.
- A map file can be at most 9,998 bytes.

## Credits and license

`minilibx/` is 42's MiniLibX graphics library, included so that the game builds, and is not
covered by this project's licence. The game's own code is under the [MIT licence](LICENSE).
