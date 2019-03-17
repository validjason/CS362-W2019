#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
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

  printf ("Beginning unittest1 for isGameOver()...\n");               //output

  //game initialization test
  gameInstance = initializeGame(4, k, 1, &G);     //
  if(gameInstance != 0){
    printf ("game initialization TEST FAILED\n");
    exit(1);
  }
  
  //check newly initialized game is not over
  gameInstance = isGameOver(&G);
  if(gameInstance != 0){
    printf ("game is not over TEST FAILED\n");
    exit(1);
  }

  //check empty province card count ends game
  G.supplyCount[province] = 0;
  gameInstance = isGameOver(&G);
  if(gameInstance != 1){
    printf ("Province count = 0 game over TEST FAILED\n");
    exit(1);
  }

  //province count not empty test
  G.supplyCount[province] = 1;
  gameInstance = isGameOver(&G);
  if(gameInstance != 0){
    printf ("Province count TEST FAILED");
    exit(1);
  }

  //set 3 supplyCounts to 0
  for(i=0;i<3;i++)
  {
    G.supplyCount[i] = 0;
  }

  //test 3 empty supplyCounts ends game
  gameInstance = isGameOver(&G);
  if(gameInstance != 1){
    printf ("3 empty supply piles game over TEST FAILED");
    exit(1);
  }

  printf ("unittest1 TEST SUCCESSFULLY COMPLETED\n");

  return 0;
}
