
#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "initGame.h"


Game *initGame(int boardSize, int winLength) {

  // game pointer creation
  Game *game;

  // for incorrect boardSize or winLength you should return a NULL pointer
  if(winLength > boardSize || winLength < 3 || boardSize < 3 || boardSize > 8){
    printf("Incorrect parameter values for board size or win length. Exiting\n");
    return NULL;
  }

  // game structure allocation
  game = (Game*)malloc(sizeof(Game));

  // start assigning data to the structure
  game -> boardSize = boardSize;
  game -> winLength = winLength;
  game -> maxTurns = boardSize * boardSize;
  game -> turns = 0;

  // setting empty spaces on the board to zero
  assignBoard(game, boardSize);
  int i; // variable for row
  int j; // variable for column

  // assign '.' symbol to empty spaces
  for (i = 0; i < game->boardSize; i++) {
    for (j = 0; j < game->boardSize; j++) {
      game->board[i][j] = '.';
    }
  }
  return game;
}

// allocate the game board
void assignBoard(Game *game, int BoardSize) {
  int i;
  game->board = (char**)calloc(BoardSize, sizeof(char*));
    for(i = 0 ; i < BoardSize + 1; i++){
      game->board[i] = (char*)calloc(BoardSize, sizeof(char));
    }
  return;
}