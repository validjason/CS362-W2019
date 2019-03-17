#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <assert.h>
#include "rngs.h"


//updateCoins test
int main() {

  //initializing game
  int i;                                          //count

  struct gameState G;                             //game state

  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,   //player cards
           sea_hag, tribute, smithy};

  initializeGame(4, k, 1, &G);     
  printf ("Beginning unittest2 for updateCoins()...\n");               //output

  //set hand to have exactly 1 of each treasure card
  G.hand[0][0] = copper;
  G.hand[0][1] = silver;
  G.hand[0][2] = gold;

  //set remaining hand to feast cards (non treasure)
  for (i=3;i<G.handCount[0];i++) {
    G.hand[0][i] = feast;
  }

  //call update coins
  updateCoins(0,&G,1);

  //test that coins value is correct after coins update
  if(G.coins != 7){
    printf("updateCoins TEST FAILED\n");
  }

  //all tests passed
  printf ("unittest2 TEST SUCCESSFULLY COMPLETED\n");

  return 0;
}
