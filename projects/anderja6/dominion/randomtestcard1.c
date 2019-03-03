#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <assert.h>
#include "rngs.h"
#include <time.h>


//smithy card test
int main() {

  srand(time(NULL));
  int i;
  int failedTest = 0;
  
  int j;
  int zeroTest = 0;

  for(j=0;(j<100);j++){
    //initializing game
    struct gameState G;                             //game state

    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,   //player cards
            sea_hag, tribute, smithy};

    initializeGame(4, k, 1, &G);     //initializing game

    printf ("Beginning random smithy card test...\n");               //output

    //setting all players even after init before random pic and assignment
    G.deckCount[0] = 10;
    G.handCount[0] = 0;
    
    //randomize player
    int playerNumber = rand() % 4;

    G.whoseTurn = playerNumber;

    //randomize deck count of player
    G.deckCount[playerNumber] = rand() % 30 + 3;
    printf("deckCount = %d\n", G.deckCount[playerNumber]);

    //flag when zero deck count case is tested
    if(G.deckCount[playerNumber] < 1){
      zeroTest++;
    }

    //testing handcount state after smithy
    int initialHandCount = G.handCount[playerNumber];
    int initialDeckCount = G.deckCount[playerNumber];
    printf("initial hand count = %d\n",initialHandCount);
    printf("initial deck count = %d\n",initialDeckCount);
    
    //function call
    cardEffect(smithy, 0, 0, 0, &G, 0, 0);
    int finalHandCount = G.handCount[playerNumber];
    int finalDeckCount = G.deckCount[playerNumber];
    
    //hand count should increase by 2
    if((finalHandCount - initialHandCount) != 2) {
      printf("smithy card handCount TEST FAILED\n");
      printf("initial = %d || final = %d\n", initialHandCount, finalHandCount);
      failedTest = 1;
    }
    //deck should be down 3 cards
    if((initialDeckCount - finalDeckCount) != 3) {
      printf("smithy card deckCount TEST FAILED\n");
      printf("initial = %d || final = %d\n", initialDeckCount, finalDeckCount);
      failedTest = 1;
    }

    //checking other players deck states
    for(i=0;i<MAX_PLAYERS;i++) {
      if(i != playerNumber){
        if(G.handCount[i] !=0) {
          printf("other player hand count state change TEST FAILED\n");
          failedTest = 1;
        }
        if(G.deckCount[i] != 10) {
          printf("other player deck count state change TEST FAILED\n");
          failedTest = 1;
        }
      }
    }

    //all tests passed
    if(failedTest < 1) {
      printf ("cardtest1 TEST SUCCESSFULLY COMPLETED\n"); //output
    }
    printf("zeroTest Count = %d\n", zeroTest);
  }
  return 0;
}