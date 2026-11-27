*This project has been created as part of the 42 curriculum by sywee.*

# so_long

## Description

**so_long** is a small top-down 2D game written in C with the **MiniLibX** graphics
library. The goal of the project is to practise window management, event handling,
textures and sprites, and basic algorithms such as flood fill. The memory handling
must stay rigorous, with no leaks on any exit path.

The player is a cat on calm aquamarine water. To win, the cat must pick up every
collectible on the map and then reach the exit. The exit stays closed until all
collectibles are collected. Every move is counted and printed in the terminal.

### Features

- Reads any rectangular map from a `.ber` file and fully validates it before
  opening a window.
- Checks for a valid path with a **flood fill**, which treats the exit as a dead end
  because the player cannot walk through it before collecting everything.
- Refuses maps that are wider or taller than the screen
  (`mlx_get_screen_size`).
- 32×32 px XPM textures, with a player sprite that faces left or right depending on
  the last horizontal move.
- Movement with **W A S D** or the **arrow keys**. The player cannot walk into walls.
- Closes cleanly with **ESC**, the window's **×** button, or by winning. Checked
  leak-free with valgrind.

### Map format

| Char | Meaning |
|------|---------|
| `0` | Empty space |
| `1` | Wall |
| `C` | Collectible |
| `E` | Exit |
| `P` | Player start |

A map is valid only if it:
- contains only these 5 characters
- has exactly **1 `P`**, exactly **1 `E`** and at least **1 `C`**
- is **rectangular**
- is **surrounded by walls**
- has a **valid path** from `P` to every `C` and to `E`
- fits on the screen

Example:
```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

If anything is wrong, the program prints `Error` followed by an explicit message
and exits with status 1, for example:
```
Error
Map is not surrounded by walls
```

## Instructions

### Requirements
- Linux with X11 (`libX11`, `libXext`), `cc` and `make`
- The MiniLibX archive **`minilibx-linux.tgz`** (available on the project page).
  It is not stored in this repository.

### Compilation
1. Place `minilibx-linux.tgz` in the root of the repository, next to the `Makefile`.
2. Run:
   ```
   make
   ```
   The first time, the Makefile unpacks the archive into `minilibx/`, builds
   MiniLibX, `libft` and `ft_printf`, then builds `so_long`.

Other rules:
| Rule | Effect |
|------|--------|
| `make clean` | Removes object files |
| `make fclean` | Also removes `so_long`, `libft.a` and `libftprintf.a` |
| `make re` | `fclean` then `make` |

### Execution
```
./so_long maps/valid/valid_big.ber
```

| Key | Action |
|-----|--------|
| `W` / `↑` | Move up |
| `A` / `←` | Move left |
| `S` / `↓` | Move down |
| `D` / `→` | Move right |
| `ESC` / window × | Quit |

Test maps are provided in `maps/valid/` (should open) and `maps/invalid/`
(should print `Error`). Example of a leak check:
```
valgrind --leak-check=full ./so_long maps/invalid/invalid_no_path.ber
```

## Resources

### References
- MiniLibX man pages, shipped with the library (`man/man3/mlx.3`, `mlx_new_window.3`,
  `mlx_loop.3`, `mlx_new_image.3`)
- [42 Docs – MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx): hooks,
  events, images
- X11 key codes: `/usr/include/X11/keysymdef.h` (`XK_Escape`, `XK_Left`, ...)
- [XPM image format](https://en.wikipedia.org/wiki/X_PixMap)
- [Flood fill algorithm](https://en.wikipedia.org/wiki/Flood_fill)
- [Valgrind Quick Start Guide](https://valgrind.org/docs/manual/quick-start.html)
- [GNU Make manual – order-only prerequisites](https://www.gnu.org/software/make/manual/html_node/Prerequisite-Types.html)

### AI usage
I used an AI assistant (Claude, by Anthropic) as a **tutor and test helper**, not to
write the game logic for me. Specifically:

- **Explanations and step-by-step guidance:** concepts such as MiniLibX hooks,
  flood fill, freeing memory in reverse order, uninitialised variables and Makefile
  prerequisites. Each feature was broken into small steps. I wrote the C code myself
  and was asked to explain each step back.
- **Code review:** pointing out bugs and norm issues in my code (for example `=`
  used instead of `==`, or a function going over 25 lines), which I then fixed.
- **Testing:** running norminette, valgrind on every invalid map, edge-case files
  (empty file, wrong extension, Windows line endings, ...) and a fresh-clone build
  test.
- **Assets:** generating the XPM textures (to my requests and after my approval) and
  several of the test maps in `maps/`.
- **Build setup:** the Makefile rule that unpacks `minilibx-linux.tgz` was suggested
  and applied by the AI, then explained and tested.
- **Documentation:** drafting this README and my personal evaluation notes.

I checked, tested and understood everything that went into the project.
