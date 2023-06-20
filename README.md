Okay, here is the updated README.md:

# Tic-Tac-Toe Game

This project is a C program that implements a tic-tac-toe game with two versions: a standard 3x3 board and a customizable board size and winning line. The game can be played by two human players or by one human player against the computer. The game uses a dynamically allocated 2D array to store the board and checks for the validity of the moves and the end of the game. The project is modular and consists of several files: `board.h`, `board.c`, `game.h`, `game.c`, `main.c`, `main2.c`, and `Makefile`.

## How to compile and run

The project is organized into two folders: `3x3` and `customizable`. Each folder contains the files for the corresponding version of the game and a Makefile to compile them.

To compile the project, navigate to the desired folder and use the make command with the following options:

- `make all`: compiles the game and creates an executable file in the `bin` folder
- `make clean`: removes the executable file

To run the game, navigate to the `bin` folder and use the following command:

`./tictactoe`

For the customizable version, you also need to provide two arguments: the board size (between 3 and 8) and the winning line (between 3 and the board size):

`./tictactoe <board_size> <winning_line>`

For example, if you want to play on a 5x5 board with a winning line of 4, you can run the program as follows:

`./tictactoe 5 4`

## Author and license

This project was made by Karim Amr Elsayed Khater. It is not licensed and is free to use and modify.

## Known issues and future work

There is a memory leak issue in the program that needs to be fixed. The board array is not freed properly at the end of the game. A possible solution is to use a global pointer to store the address of the board and free it in a separate function.
