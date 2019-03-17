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
  int failedTest = 0;

  struct gameState G;                             //game state

  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,   //player cards
           sea_hag, tribute, smithy};

  //initialize game
  initializeGame(4, k, 1, &G);     
  printf ("Beginning unittest3 for gainCard()...\n");           
  
  //initital counts
  int initialDeckCount = G.deckCount[0];
  int initialHandCount = G.handCount[0];
  int initialDiscardCount = G.discardCount[0];
  int initialSupplyCount = G.supplyCount[0];

  //zero supply test
  G.supplyCount[0] = 0;
  int zeroSupply = gainCard(0, &G, 0, 0);
  if(zeroSupply != -1){
    printf("zero supply TEST FAILED\n");     
    failedTest++;
  }
 
  //deck count test
  G.supplyCount[0] = 30;
  gainCard(0, &G, 1, 0);
  int finalDeckCount = G.deckCount[0];
  if((finalDeckCount - initialDeckCount) != 1){
     printf("deckCount TEST FAILED\n");
     failedTest++;
  }

  //supply count test
  int finalSupplyCount = G.supplyCount[0];
  if((initialSupplyCount - finalSupplyCount) != 1){
     printf("supplyCount TEST FAILED");
     failedTest++;
  }

  //hand count test
  gainCard(0, &G, 2, 0);
  int finalHandCount = G.handCount[0];
  if((finalHandCount - initialHandCount) != 1){
     printf("handCount TEST FAILED\n");
     failedTest++;
  } 

  //discard count test
  gainCard(0, &G, 0, 0);
  int finalDiscardCount = G.discardCount[0];
  if((finalDiscardCount - initialDiscardCount) != 1){
     printf("discardCount TEST FAILED\n");
     failedTest++;
  } 
  
  //all tests passed
  if(failedTest == 0){
    printf ("unittest3 TEST SUCCESSFULLY COMPLETED\n");
  }

  return 0;
}
