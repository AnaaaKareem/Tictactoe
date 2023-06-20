
#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "initGame.h"
#include "playGame.h"


int main(int argc, char *argv[]) {

  // game struecturing pointing
  Game *game; 

  // Initializing variables   
  game = initGame(3,3);

  // start playing the game
  playGame(game);

  // free game structure when the game is done
  free(game); 

  return 0;
}
