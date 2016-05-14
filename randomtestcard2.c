
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

	init_test("random test - feast");
        struct gameState s;
        struct gameState *state = &s;

	int kingdomCards[10] = {great_hall, feast, steward, tribute, ambassador, cutpurse, embargo, outpost, salvager, sea_hag};
	
	int n_players = (int) ((rand() / (float)RAND_MAX) * 4 + 1);
	
	initializeGame(n_players, kingdomCards, rand(), state);
	
	int j;
	for(j = 0; j < 100; j = j + 1) {
                int player = whoseTurn(state);
	        state->hand[player][0] = feast;
		int numdiscards = state->discardCount[player];
	
		int choice = (int) ((rand()/(float)RAND_MAX) * 10);
		playCard(0,choice,0,0,state);
		t_assert(numdiscards = state->discardCount[player]-1, "player didn't get a new card in their discard pile");
    		t_assert(state->discard[player][state->discardCount[player]-1] == kingdomCards[choice], "didn't get the correct card!");
		
		endTurn(state);

	}
	return 0;
	
	
}
