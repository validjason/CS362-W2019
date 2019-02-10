#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <assert.h>
#include "rngs.h"


//adventurer card test
int main() {

  int i;
  int failedTest = 0;

  //initializing game
  struct gameState G;                             //game state

  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,   //player cards
           sea_hag, tribute, smithy};

  initializeGame(4, k, 1, &G);     //initializing game
  printf ("Beginning cardtest2...\n");               //output
  
  
  shuffle(0,&G);
  //initial state
  int initialDeckCount = G.deckCount[0];
  int initialHandCount = G.handCount[0];
  int initialDiscardCount = G.discardCount[0];
  int initialPlayedCardCount = G.playedCardCount;
  //call card effect to test adventurerCard function
  cardEffect(adventurer, 0, 0, 0, &G, 0, 0);

  //new state
  int finalDeckCount = G.deckCount[0];
  int finalHandCount = G.handCount[0];
  int finalDiscardCount = G.discardCount[0];
  int finalPlayedCardCount = G.playedCardCount;

  //check hand count has gained 2 cards
  if(finalHandCount != (initialHandCount + 2)){
    printf("hand count TEST FAILED\n");
    failedTest = 1; //failed test flag
  }
  if((finalPlayedCardCount - initialPlayedCardCount) != 1){
    printf("played card count TEST FAILED\n");
    failedTest = 1; //failed test flag
  }

  //check total cards in the 3 piles are equal after state change
  int initialCardBalance = initialDeckCount + initialHandCount + initialDiscardCount;
  int finalCardBalance = finalDeckCount + finalHandCount + finalDiscardCount;

  if(initialCardBalance != finalCardBalance) {
    printf("card balance TEST FAILED\n");
    failedTest = 1;
  }

  //verify other player states have not changed
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

  finalDeckCount = initialDeckCount;
  finalHandCount = initialHandCount;
  finalDiscardCount = initialDiscardCount;
  finalPlayedCardCount = initialPlayedCardCount;

  //empty deck test
  G.deckCount[0] = 0;
  cardEffect(adventurer, 0, 0, 0, &G, 0, 0);

  finalDeckCount = G.deckCount[0];
  finalHandCount = G.handCount[0];
  finalDiscardCount = G.discardCount[0];
  finalPlayedCardCount = G.playedCardCount;

  //check hand count has gained 2 cards
  if(finalHandCount != (initialHandCount + 2)){
    printf("hand count TEST FAILED\n");
    failedTest = 1; //failed test flag
  }
  if((finalPlayedCardCount - initialPlayedCardCount) != 1){
    printf("played card count TEST FAILED\n");
    failedTest = 1; //failed test flag
  }

  //check total cards in the 3 piles are equal after state change
  initialCardBalance = initialDeckCount + initialHandCount + initialDiscardCount;
  finalCardBalance = finalDeckCount + finalHandCount + finalDiscardCount;

  if(initialCardBalance != finalCardBalance) {
    printf("card balance TEST FAILED\n");
    failedTest = 1;
  }

  //verify other player states have not changed
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
    printf ("cardtest2 TEST SUCCESSFULLY COMPLETED\n"); //output
  }
  return 0;
}
