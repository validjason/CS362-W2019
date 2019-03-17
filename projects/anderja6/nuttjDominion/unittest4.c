#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <assert.h>
#include "rngs.h"


//fullDeckCount() test
int main() {

  //initializing game
  int i;
  int failedTest = 0;

  struct gameState G;                             //game state

  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,   //player cards
           sea_hag, tribute, smithy};

  //initialize game
  initializeGame(4, k, 1, &G);     
  printf ("Beginning unittest4 for fullDeckCount()...\n");           
  
  //set deck to all the same value to calculate total
  for(i=0;i<G.deckCount[0];i++){
    G.deck[0][i] = 4;
  } 
  
  //set hand to all the same value to calculate total
  for(i=0;i<G.handCount[0];i++){
    G.hand[0][i] = 4;
  } 
  
  //set discard pile to all the same value to calculate total
  G.discardCount[0] = 5;
  for(i=0;i<G.discardCount[0];i++){
    G.discard[0][i] = 4;
  } 

  int manualCount = G.deckCount[0] + G.handCount[0] + G.discardCount[0];
  int result = fullDeckCount(0, 4, &G); 

  //check if manual count matches function return amount
  if(manualCount != result){
    printf("fullDeckCount TEST FAILED\n");
    failedTest++;
  }

  //all tests passed
  if(failedTest == 0){
    printf ("unittest3 TEST SUCCESSFULLY COMPLETED\n");
  }

  return 0;
}
