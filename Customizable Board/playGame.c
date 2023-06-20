
#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "playGame.h"
#include "endGame.h"

// start playing tictactoe
void playGame(Game *game) {

  // array used to switch based on turn
  char symbols[2] = {'X','O'};
  // integer variable used to switch player based on turns
  int player = 0;
  
  printf("New game starting\n");
  showGame(game); // print board

  int turns = game->turns;

  // The loop finished when turns finish on every single input
  for (turns = 0; turns < game->maxTurns; turns++) {
    
    // if the modulus is even it returns a zero and a one when the modulus is odd
    // first player is X in case 0
    // second player is O case 1
    switch (turns % 2) {
      case 0:
        player = 0;
        break;
      case 1:
        player = 1;
        break;
    } 
    
    // print asks for user input 
    printf("Player %c: Enter your move as row column values:\n", symbols[player]);
    
    // variable used to check if the input is correct
    int IsMoveValid;
    // if makeMove equals 1 data accepted, if 0 data is rejected
    IsMoveValid = makeMove(game, symbols[player]);

    // Loop until a valid coordinate is given
    while(IsMoveValid == 0) {
      printf("Move rejected. Please try again\n"); // print an error
      IsMoveValid = makeMove(game, symbols[player]); 
    }
    showGame(game); // update board

    // if winGame is 1 print player won
    // if winGame is 0 continue playing
    int win = winGame(game, symbols[player]);
    if(win == 1) {
      printf("Player %c has won\n", symbols[player]);
      break;
    }
    
    // if drawGame is 1 stop and print a draw
    int draw = drawGame(game);
    if(draw == 1) {
      printf("Match is drawn\n");
      break;
    }
  }
  return;
}

// used to print board
void showGame(Game *game) {
  
  // array used to store coordinate numbers
  int numbers[game->boardSize];
  
  // used to print column coordinates 
  printf("      ");
  for (int i = 0; i < game->boardSize; i++) {
    numbers[i] = i;
    printf("%d  ", numbers[i]);
  }
  printf("\n");
  printf("\n");

  // used to print row column coordinates and board spaces
  for (int i = 0; i < game->boardSize; i++) {
    printf(" %d    ", numbers[i]); // print row coordinates
    // start printing board spaces
    for (int j = 0; j < game->boardSize; j++) {
      if (j != game->boardSize - 1) {
        printf("%c  ", game->board[i][j]);
      }
      else {
        printf("%c\n", game->board[i][j]);
      }
    }
  }
  printf("\n");
  return;
}


int makeMove(Game *game, char symbol) {
  int row;
  int column;
  char buffer[100]; // used to store input from the user 
  
  fgets(buffer, 100, stdin); // used to receive input from user
  sscanf(buffer, "%d %d", &row, &column); // used to split and assign to variables

  // check if input is out of range 
  if (row >= 0 && column >= 0 && row < game->boardSize && column < game->boardSize) {
    // check if the input is empty
    if(game->board[row][column] != '.') {
      return 0;
    }
    else {
      game->board[row][column] = symbol;
      return 1;  
    }
  }
  else {
    printf("Move rejected. Please try again\n"); // ask the user to input coordinates again
    return 0;
  }
}
