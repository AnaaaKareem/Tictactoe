# Tic-Tac-Toe Game

Tic-tac-toe is a simple and popular game that involves two players taking turns to mark the spaces in a grid with Xs and Os. The player who succeeds in placing three or more of their marks in a horizontal, vertical, or diagonal row wins the game.

This project is a C program that implements a tic-tac-toe game with two versions: a standard 3x3 board and a customizable board size and winning line. The game can be played by two human players or by one human player against the computer. The game uses a dynamically allocated 2D array to store the board and checks for the validity of the moves and the end of the game. The project is modular and consists of several files: `main.c`, `playGame.c`, `playGame.h`, `initGame.c`, `initGame.h`, `endGame.c`, `endGame.h`, `game.h` and `Makefile`.

## How to compile and run

The project is organized into two folders: `3x3` and `customizable`. Each folder contains the files for the corresponding version of the game and a Makefile to compile them.

To compile the project, follow these steps:

1. Navigate to the desired folder (`3x3` or `customizable`) using the terminal.
2. Use the command `make all` to compile the game and create an executable file in the `bin` folder.
3. Use the command `make clean` to remove the executable file if needed.

To run the game, follow these steps:

1. Navigate to the `bin` folder using the terminal.
2. Use the command `./tictactoe` to run the game.
3. For the customizable version, you also need to provide two arguments: the board size (between 3 and 8) and the winning line (between 3 and the board size). For example, if you want to play on a 5x5 board with a winning line of 4, you can use the command `./tictactoe 5 4`.

## Game rules

The game rules are as follows:

- The game starts with an empty board and asks the players to choose their marks (X or O).
- The players take turns to enter their moves by typing the row and column numbers of an empty space on the board.
- The game checks if the move is valid (within the board boundaries and not already occupied) and updates the board accordingly.
- The game displays the board after each move and announces if there is a winner or a tie.
- The game ends when either one player has formed a winning line of their marks or there are no more empty spaces on the board.
- The game asks if the players want to play again or quit.

## Author and license

This project was made by Karim Amr Elsayed Khater. It is not licensed and is free to use and modify.

## Known issues and future work

There is a memory leak issue in the program that needs to be fixed. The board array is not freed properly at the end of the game. A possible solution is to use a global pointer to store the address of the board and free it in a separate function.

The project uses a structure to store game information in game.h:

```c
typedef struct _game {
  char **board;    // board for storing the game state
  int boardSize;       // board size 
  int winLength;       // length of a winning line
  int maxTurns;        // maximum possible moves
  int turns;           // current number of moves
} Game;
```

The project consists of several files with different functions:

- `main.c`: contains the main function that calls other functions from different modules
- `playGame.c` and `playGame.h`: contain the functions for playing the game, such as getting the player's input, validating the move, updating the board, and displaying the board
- `initGame.c` and `initGame.h`: contain the functions for initializing the game, such as allocating memory for the board, choosing the marks, and setting the game parameters
- `endGame.c` and `endGame.h`: contain the functions for ending the game, such as checking for a winner, announcing the result, and freeing the memory
- `game.h`: contains the structure definition and some constants for the game
