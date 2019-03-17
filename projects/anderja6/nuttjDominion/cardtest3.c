#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <assert.h>
#include "rngs.h"


//council room card test
int main() {

  int i;
  int failedTest = 0;

  //initializing game
  struct gameState G;                             //game state

  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,   //player cards
           sea_hag, tribute, smithy};

  initializeGame(4, k, 1, &G);     //initializing game
  printf ("Beginning cardtest3...\n");               //output
  
  
  shuffle(0,&G);
  //initial state
  int initialDeckCount = G.deckCount[0];
  int initialHandCount = G.handCount[0];
  int initialNumBuys = G.numBuys;
  int initialPlayedCardCount = G.playedCardCount;

  //call card effect to test adventurerCard function
  cardEffect(council_room, 0, 0, 0, &G, 0, 0);

  //new state
  int finalDeckCount = G.deckCount[0];
  int finalHandCount = G.handCount[0];
  int finalNumBuys = G.numBuys;
  int finalPlayedCardCount = G.playedCardCount;

  //check hand count has gained +3 cards after the discard
  if(finalHandCount != (initialHandCount + 3)){
    printf("hand count TEST FAILED\n");
    failedTest = 1; //failed test flag
  }

  if(finalNumBuys != (initialNumBuys + 1)){
    printf("num buys TEST FAILED\n");
    failedTest = 1; //failed test flag
  }

  //check total cards in the 3 piles are equal after state change
  int initialCardBalance = initialDeckCount + initialHandCount + initialPlayedCardCount;
  int finalCardBalance = finalDeckCount + finalHandCount + finalPlayedCardCount;

  if(initialCardBalance != finalCardBalance) {
    printf("card balance TEST FAILED\n");
    failedTest = 1;
  }

  //verify other player states have not changed
  for(i=1;i<MAX_PLAYERS;i++) {
    if(G.handCount[i] !=1) {
      printf("other player hand count state change TEST FAILED\n");
      failedTest = 1;
    }
    if(G.deckCount[i] != 9) {
      printf("other player deck count state change TEST FAILED\n");
      failedTest = 1;
    }
  }
  if(failedTest < 1) {
    printf ("cardtest3 TEST SUCCESSFULLY COMPLETED\n"); //output
  }
  return 0;
}
