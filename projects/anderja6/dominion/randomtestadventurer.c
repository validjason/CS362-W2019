#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <assert.h>
#include "rngs.h"
#include <time.h>


//adventurer card test
int main() {

  srand(time(NULL));
  int j;
  int zeroTest = 0;
  
  for(j=0;(j<100);j++){
    int i;
    int failedTest = 0;
    

    //initializing game
    struct gameState G;                             //game state

    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,   //player cards
           sea_hag, tribute, smithy};

    initializeGame(4, k, 1, &G);     //initializing game
    printf ("Beginning adventurer card test...\n");               //output
  
    shuffle(0,&G);
    
    //setting all players even after init before random pic and assignment
    G.deckCount[0] = 10;
    G.handCount[0] = 0;
  
    //randomize player
    int playerNumber = rand() % 4;

    //randomize deck count of player
    G.deckCount[playerNumber] = rand() % 30;

    if(G.deckCount[playerNumber] < 1){
      zeroTest++;
    }

    G.whoseTurn = playerNumber;
    //initial state
    int initialDeckCount = G.deckCount[playerNumber];
    int initialHandCount = G.handCount[playerNumber];
    int initialDiscardCount = G.discardCount[playerNumber];
    int initialPlayedCardCount = G.playedCardCount;

    //call card effect to test adventurerCard function
    cardEffect(adventurer, 0, 0, 0, &G, 0, 0);

    //new state
    int finalDeckCount = G.deckCount[playerNumber];
    int finalHandCount = G.handCount[playerNumber];
    int finalDiscardCount = G.discardCount[playerNumber];
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
    for(i=0;i<MAX_PLAYERS;i++) {
      if(i != playerNumber){
        if(G.handCount[i] !=0) {
          printf("other player hand count state change TEST FAILED handcount = %d\n", G.handCount[i]);
          failedTest = 1;
        }
        if(G.deckCount[i] != 10) {
          printf("other player deck count state change TEST FAILED deckCount = %d\n", G.deckCount[i]);
          failedTest = 1;
        }
      }
    }

    printf("Empty Deck tests completed: %d\n", zeroTest);
    if(failedTest < 1) {
      printf ("adventurer card TEST SUCCESSFULLY COMPLETED\n"); //output
    }
  }  
  return 0;
}
