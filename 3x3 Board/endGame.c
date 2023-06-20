
#include <stdio.h>

#include "game.h"
#include "endGame.h"


int winGame(Game *game, char symbol) {

  // assign variables to check for a winning condition
  int Hwin = horizontalChecker(game, symbol); // horizontal checker
  int Vwin = verticalChecker(game, symbol); // vertical checker
  int Dwin = diagonalChecker(game, symbol); // diagonal checker
  int RDwin = reverseDiagonalChecker(game, symbol); // reverse diagonal checker

  // if any check is 1 return true
  if(Hwin == 1 || Vwin == 1 || Dwin == 1 || RDwin == 1) {
    return 1;
  }
  else {
    return 0;
  }
}

// check for if there is no spaces left
int drawGame(Game *game) {
  //variables used in the function
  int i; // row
  int j; // column
  int counter = 0; // used to check empty spaces

  // if there is an empty space add to the counter 
  for(i = 0; i < game->boardSize; i++) {
    for(j = 0; j < game->boardSize; j++) {
      if(game->board[i][j] == '.') {
        counter += 1;
      }
    }
  }

  // if count equals 0 return 1 else return 0
  if(counter != 0) {
    return 0; // return false
  }
  else {
    return 1; // return true
  }
}

// check horizontally 
int horizontalChecker(Game *game, char symbol){
  int isWinner;

  // check of column 0, 1, and 2 are equal in every single row
  for (int i = 0; i < 3; i++) {
    if (game->board[i][0] == game->board[i][1] && game->board[i][0] == game->board[i][2]) {
      if (game->board[i][0] == symbol && game->board[i][1] == symbol && game->board[i][2] == symbol) {
        isWinner = 1; // assign 1 for true
      }
    }
  }
  return isWinner; // return either 0 or 1
}

// check vertically
int verticalChecker(Game *game , char symbol) {
  int isWinner;

  // check of row 0, 1, and 2 are equal in every single column
  for (int i = 0; i < 3; i++) {
    if (game->board[0][i] == game->board[1][i] && game->board[1][i] == game->board[2][i]) {
      if (game->board[0][i] == symbol && game->board[1][i] == symbol && game->board[2][i] == symbol) {
        isWinner = 1; // assign 1 for true
      }
    }
  }
  return isWinner; // return either 0 or 1
}
    
// check diagonally
int diagonalChecker(Game *game, char symbol){
  int isWinner = 0;

  // check top left, middle, and bottom right
  if (game->board[0][0] == symbol && game->board[1][1] == symbol && game->board[2][2] == symbol) {
    if (game->board[0][0] == game->board[1][1] && game->board[0][0] == game->board[2][2]) {
      isWinner = 1; // assign 1 for true
    }
  }
  return isWinner; // return either 0 or 1
}

// check opposite diagonal
int reverseDiagonalChecker(Game *game, char symbol){
  int isWinner = 0;

  // check bottom left, middle, and top right
  if (game->board[2][0] == symbol && game->board[1][1] == symbol && game->board[0][2] == symbol) {
    if (game->board[2][0] == game->board[0][2] && game->board[2][0] == game->board[1][1]) {
      isWinner = 1; // assign 1 for true
    }
  }
  return isWinner; // return either 0 or 1
}
    
