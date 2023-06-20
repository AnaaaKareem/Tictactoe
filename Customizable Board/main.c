
#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "initGame.h"
#include "playGame.h"


int main(int argc, char *argv[]) {
  // game struecturing pointing
  Game *game;

  // checking number of arguments
  if (argc != 3) {
    printf("Incorrect arguments given. Expecting BoardSize Winning-length Exiting.\n");
    return 0;
  }

  // assign command line arguments to variables
  int boardsize = atoi(argv[1]);
  int winLength = atoi(argv[2]);

  // Initializing variables 
  game = initGame(boardsize, winLength);
  if (game == NULL) {
    return -1;
  }
  
  // start playing the game
  playGame(game);

  // free game structure when the game is done
  free(game);

  return 0;
}

