#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <assert.h>
#include "rngs.h"


//village card test
int main() {

  int i;
  int failedTest = 0;

  //initializing game
  struct gameState G;                             //game state

  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,   //player cards
           sea_hag, tribute, smithy};

  initializeGame(4, k, 1, &G);     //initializing game
  printf ("Beginning cardtest4...\n");               //output
  
  
  shuffle(0,&G);
  //initial state
  int initialDeckCount = G.deckCount[0];
  int initialHandCount = G.handCount[0];
  int initialPlayedCardCount = G.playedCardCount;
  int initialNumActions = G.numActions;
  //call card effect to test adventurerCard function
  cardEffect(village, 0, 0, 0, &G, 0, 0);

  //new state
  int finalDeckCount = G.deckCount[0];
  int finalHandCount = G.handCount[0];
  int finalPlayedCardCount = G.playedCardCount;
  int finalNumActions = G.numActions;

  //check hand count has gained +0 cards after the discard
  if(finalHandCount != (initialHandCount)){
    printf("hand count TEST FAILED\n");
    failedTest = 1; //failed test flag
  }
  //verify 2 actions have been gained
  if(finalNumActions != (initialNumActions + 2)){
    printf("num actions TEST FAILED\n");
    failedTest = 1; //failed test flag
  }
  //verify only one card has been played
  if((finalPlayedCardCount - initialPlayedCardCount) != 1) {
    printf("played card TEST FAILED\n");
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
    printf ("cardtest4 TEST SUCCESSFULLY COMPLETED\n"); //output
  }
  return 0;
}
