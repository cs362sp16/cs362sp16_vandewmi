
//
// Created by Miles on 4/28/2016.
//

#include "dominion.h"
#include "commontesting.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>


int main(int argc, char *argv[]) {
	if(argc == 2) srand(atoi(argv[1]));
	else srand(time(NULL));

                init_test("random test - minion");
                struct gameState s;
                struct gameState *state = &s;

                int kingdomCards[10] = {great_hall, minion, steward, tribute, ambassador, cutpurse, embargo, outpost, salvager, sea_hag};

                int n_players = (int) ((rand() / (float)RAND_MAX) * 4 + 1);
                initializeGame(n_players, kingdomCards, rand(), state);

	int j;
	for(j = 0; j < 100; j = j + 1) {
 	
                int player = whoseTurn(state);
      	        int oldCoins = state->coins;
	        state->hand[player][0] = minion;

		int choice = (int) ((rand()/(float)RAND_MAX) * 2 + 1);
		playCard(0,choice,0,0,state);
    		t_assert(state->numActions == 1, "minion failed to add an action");
    		if(choice == 1) t_assert(state->coins == oldCoins +2, "player didn't get 2 more coins");
    		int i = 0;

    		for(i = 0; i < state->numPlayers; i++) {
        		t_assert(i == player || state->discardCount[i] == 0, "a player discarded their hand when they shouldn't have");
       	 		t_assert(i == player || state->handCount[i] == 5, "a player has an incorrect number of cards");
	    	}

		endTurn(state);

	}
	return 0;
	
	
}
