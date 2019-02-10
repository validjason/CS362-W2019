#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <assert.h>
#include "rngs.h"


//gain card test
int main() {

  //initializing game
  int i;                                          //count
  int failedTest = 0;

  struct gameState G;                             //game state

  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,   //player cards
           sea_hag, tribute, smithy};

  initializeGame(4, k, 1, &G);     //
  printf ("Beginning unittest2...\n");               //output
  
  int initialDeckCount = G.deckCount[0];
  int initialHandCount = G.handCount[0];
  int initialDiscardCount = G.discardCount[0];
  int initialSupplyCount = G.supplyCount[0];

  G.supplyCount[0] = 0;
  int zeroSupply = gainCard(0, &G, 0, 0);
  if(zeroSupply != -1){
    printf("zero supply TEST FAILED\n");     
    failedTest++;
  }
 
  G.supplyCount[0] = 30;
  gainCard(0, &G, 1, 0);
  int finalDeckCount = G.deckCount[0];
  if((finalDeckCount - initialDeckCount) != 1){
     printf("deckCount TEST FAILED\n");
     failedTest++;
  }
  int finalSupplyCount = G.supplyCount[0];
  if((initialSupplyCount - finalSupplyCount) != 1){
     printf("supplyCount TEST FAILED");
     failedTest++;
  }

  gainCard(0, &G, 2, 0);
  int finalHandCount = G.handCount[0];
  if((finalHandCount - initialHandCount) != 1){
     printf("handCount TEST FAILED\n");
     failedTest++;
  } 

  gainCard(0, &G, 0, 0);
  int finalDiscardCount = G.discardCount[0];
  if((finalDiscardCount - initialDiscardCount) != 1){
     printf("discardCount TEST FAILED\n");
     failedTest++;
  } 
  

  if(failedTest == 0){
    printf ("unittest2 TEST SUCCESSFULLY COMPLETED\n");
  }

  return 0;
}
