#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <assert.h>
#include "rngs.h"


//smithy card test
int main() {

  int i;
  int failedTest = 0;
  //initializing game
  struct gameState G;                             //game state

  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,   //player cards
           sea_hag, tribute, smithy};

  initializeGame(4, k, 1, &G);     //initializing game
  printf ("Beginning cardtest1...\n");               //output
  
  //testing handcount state after smithy
  int initialHandCount = G.handCount[0];
  cardEffect(smithy, 0, 0, 0, &G, 0, 0);
  int afterSmithyCount = G.handCount[0];
  
  //hand count should increase by 2
  if((afterSmithyCount - initialHandCount) != 2) {
    printf("smithy card handCount TEST FAILED\n");
    failedTest = 1;
  }

  for(i=1;i<MAX_PLAYERS;i++) {
    if(G.handCount[i] !=0) {
      printf("other player hand count state change TEST FAILED\n");
      failedTest = 1;
    }
    if(G.deckCount[i] != 10) {
      printf("other player deck count state change TEST FAILED\n");
      failedTest = 1;
    }
  }




  if(failedTest < 1) {
    printf ("cardtest1 TEST SUCCESSFULLY COMPLETED\n"); //output
  }
  return 0;
}
