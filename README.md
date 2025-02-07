<h1 align="center"> So_long | 
  <picture>
  <source media="(prefers-color-scheme: dark)" srcset="https://cdn.simpleicons.org/42/white">
  <img alt="42" width=40 align="center" src="https://cdn.simpleicons.org/42/Black">
 </picture>
 Cursus 
</h1>

> A project to create a ***small 2D game*** programmed with C and MiniLibX, the 42 graphical library.

<div align="center">
<img align="center"  width="600" src="https://github.com/Abdullah-Alawad/imgs/blob/main/so_long_game.png">
  <br>
  <br>
<img align="center"  width="600" src="https://github.com/Abdullah-Alawad/imgs/blob/main/so_long_game_2.png">
</div>
<br>
<br>
 <img align="right" width="150" src="https://github.com/Abdullah-Alawad/imgs/blob/main/100_Success.png">
 
### About the project

This project is about developing a 2D game that can be interacted with using your keyboard. We have three main things to do and check: Error Handling, Memory Management, and Game Logic, each should be done carefully  

## Instructions
* Makefile will compile your source files. It should not relink.
* You are required to use MiniLibX for this project.
* The program should be compiled using the following commands:
* If not compiled, you should compile the minilibx library in its folder 'mlx_linux':
```shell
> ./configure
```
* After that you're ready to compile the project using these commands respectivley:
```shell
> make
> ./so_long <map_file> <map_number>
```
> [!WARNING]
> Maps must have the ***.ber*** extension
> 
> Map number can be 1 or 2

## How To Play
* The number of movements must be displayed in the terminal.
* Pressing <kbd>ESC</kbd> or closing the window should result in quitting the program.

<img align="right" width="150" src="https://github.com/Abdullah-Alawad/imgs/blob/main/ber_map.png">

* The map must be constructed using five components: **walls**, **collectibles** (at least one), **floor**, **exits** (at least one), and **the player** (only one). These five characters compose the map: 
  * **0** for a floor
  * **1** for a wall
  * **C** for a collectible
  * **E** for a map exit
  * **P** for the player’s starting position

* To move the main character, use the <kbd>W</kbd> <kbd>A</kbd> <kbd>S</kbd> <kbd>D</kbd> keys or arrows keys:
  * <kbd>W</kbd> or <kbd>↑</kbd> to move up ↑
  * <kbd>S</kbd> or <kbd>↓</kbd> to move down ↓
  * <kbd>D</kbd> or <kbd>➞</kbd> to move right ➞
  * <kbd>A</kbd> or <kbd>←</kbd> to move left ←
 
 ### And That's it, hope you to have fun playing this game!
