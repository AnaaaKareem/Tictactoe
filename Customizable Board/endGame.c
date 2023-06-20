
#include <stdio.h>

#include "game.h"
#include "endGame.h"

// indicates if a player won 
int winGame(Game *game, char symbol) {

  // each variable is a checker that store integer values
  int Hwin = horizontalChecker(game, symbol); // horizontal checker
  int Vwin = verticalChecker(game, symbol); // vertical checker
  int Dwin = diagonalChecker(game, symbol); // diagonal checker
  int RDwin = reverseDiagonalChecker(game, symbol); // reverse diagonal checker

  // if the checker's value is equal to the winning line return 1 else return 0
  if(Hwin == game->winLength || Vwin == game->winLength || Dwin == game->winLength || RDwin == game->winLength) {
    return 1; // return true
  } 
  else {
    return 0; // return false
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
int horizontalChecker(Game *game, char symbol) {
  // variables used in the function
  int i; // row
  int j; // column
  int k; // winning line
  int counter = 0; // used to add if symbol found

  // loop over row then column
  for (i = 0; i < game->boardSize; i++) {
    for (j = 0; j < game->boardSize; j++) {
      counter = 0; // reset counter
      // if the current coordinate is equal to symbol
      if (game->board[i][j] == symbol) {
        counter += 1; // add to counter
        // loop over the winning line
        for (k = 1; k < game->winLength; k++) {
          // if coordinates out of bounds break loop
          if (j + k > game->boardSize) {
            break; // break loop
          }
          // if the next coordinate does not equal symbol
          if (game->board[i][j+k] != symbol) {
            counter = 0; // reset counter
            break; // break loop
          }
          else {
            counter += 1; // add to counter
          }
        }
        // check if counter is equal to the winning line
        // stop looping if true
        if (counter == game->winLength) {
          return counter; // return the counter
          break; // break loop
        } 
      }
    }
  }
  return 0; // return false
}

// check vertically
int verticalChecker(Game *game, char symbol){
  // variables used in the function
  int i; // row
  int j; // column
  int k; // winning line
  int counter = 0; // used to add if symbol found

  // loop over column then row
  for (j = 0; j < game->boardSize; j++) {
    for (i = 0; i < game->boardSize; i++) {
      counter = 0;
      // if the current coordinate is equal to symbol
      if (game->board[i][j] == symbol) {
        counter += 1; // add to counter
        // loop over the winning line
        for (k = 1; k < game->winLength; k++) {
          // if coordinates out of bounds break loop
          if (i + k > game->boardSize) {
            break; // break loop
          }
          // if the next coordinate does not equal symbol
          if (game->board[i+k][j] != symbol) {
            counter = 0; // reset counter
            break; // break loop
          }
          else {
            counter += 1; // add to counter
          }
        }
        // check if counter is equal to the winning line
        // stop looping if true
        if (counter == game->winLength) {
          return counter; // return counter
          break; // break loop
        }
      }
    }
  }
  return 0; // return false
}

// check diagonally
int diagonalChecker(Game *game, char symbol) {
    // variables used in the function
    int i; // row
    int j; // column
    int k; // winning line
    int counter = 0; // used to add if symbol found

    // loop over row then column
    for (i = 0; i < game->boardSize; i++) {
      for (j = 0; j < game->boardSize; j++) {
        // if the current coordinate is equal to symbol
        if (game->board[i][j] == symbol) {
          counter += 1; // add to counter
          // loop over the winning line
          for (k = 1; k < game->winLength; k++) {
            // if coordinates out of bounds break loop
            if (i + k > game->boardSize || j + k > game->boardSize) {
              break; // break loop
            }
            // if the next coordinate does not equal symbol
            if (game->board[i+k][j+k] != symbol) {
              counter = 0; // reset counter
              break; // break loop
            }
            else {
              counter += 1; // add to counter
            }
          }
          // check if counter is equal to the winning line
          // stop looping if true
          if (counter == game->winLength) {
            return counter; // reset counter
            break; // break loop
          }
        }   
      }
    }
 return 0; // return false
}

// check opposite diagonal
int reverseDiagonalChecker(Game *game, char symbol) {
  // variables used in the function
  int i; // row
  int j; // column
  int k; // winning line
  int counter = 0; // used to add if symbol found

  // loop over row then column
  for (i = 0; i < game->boardSize; i++) {
    for (j = 0; j < game->boardSize; j++) {
      counter = 0; // reset counter
      // if the current coordinate is equal to symbol
      if (game->board[j][i] == symbol) {
        counter += 1; // add to counter
        // loop over the winning line
        for (k = 1; k < game->winLength; k++) {
          // if coordinates out of bounds break loop
          if (j - k < 0 || i + k > game->boardSize) {
            break; // break loop
          }
          // if the next coordinate does not equal symbol
          if (game->board[j-k][i+k] != symbol) {
            counter = 0; // reset counter
            break; // break loop
          }
          else {
            counter += 1; // add to counter
          }
        }
        // check if counter is equal to the winning line
        // stop looping if true
        if (counter == game->winLength) {
          return counter; // return counter
          break; // break loop
        } 
      }   
    }
  }
  return 0; // return false
}
