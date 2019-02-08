#include<stdio.h>
#include<stdlib.h>
#include "dominion.h"
#include "structs.h"
#include "dominion_helpers.h"
#include <string.h>
#include <assert.h>
#include "rngs.h"


//isGameOver test
int main() {

  //initializing game
  int i;                                          //count
  int gameInstance;                               //return status

  struct gameState G;                             //game state

  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,   //player cards
           sea_hag, tribute, smithy};

  printf ("Starting unittest1.\n");               //output

  gameInstance = initializeGame(4, k, 1, &G);     //
  assert(gameInstance == 0);
  printf ("Game Initialized\n");

  gameInstance = isGameOver(&G);
  assert(gameInstance == 0);
  printf ("Game is not over\n");

  G->supplyCount[province] = 0;
  gameInstance = isGameOver(&G);
  assert(gameInstance == 1);
  printf ("province count = 0; Game over\n");

  G->supplyCount[province] = 1;
  gameInstance = isGameOver(&G);
  assert(gameInstance == 0);
  printf ("Province card stack increased. Game is not over\n");

  for(i=0;i<3;i++)
  {
    G->supplyCount[i] = 0;
  }
  gameInstance = isGameOver(&G);
  assert(gameInstance == 1);
  printf ("3 supply piles are empty; Game over\n");

  printf ("unittest1 has passed\n");

  return 0;
}