
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

	init_test("random test - adventurer");
        struct gameState s;
        struct gameState *state = &s;

	int kingdomCards[10] = {great_hall, adventurer, steward, tribute, ambassador, cutpurse, embargo, outpost, salvager, sea_hag};
	
	int n_players = (int) ((rand() / (float)RAND_MAX) * 4 + 1);
	
	initializeGame(n_players, kingdomCards, rand(), state);
	
	int j;
	for(j = 0; j < 100; j = j + 1) {
                int player = whoseTurn(state);
	        state->hand[player][0] = adventurer;
		int numdiscards = state->discardCount[player];
		int initHandCount = state->handCount[player];	
	
		playCard(0,0,0,0,state);
		t_assert(initHandCount = state->handCount[player] - 1, "player didn't get two more cards");
		t_assert((state->hand[player][state->handCount[player]-2] == copper ||
			state->hand[player][state->handCount[player]-2] == silver ||
			state->hand[player][state->handCount[player]-2] == gold) &&
			(state->hand[player][state->handCount[player]-1] == copper ||
                        state->hand[player][state->handCount[player]-1] == silver ||
                        state->hand[player][state->handCount[player]-1] == gold), "player drew a non-treasure card");
		
		endTurn(state);

	}
	return 0;
	
	
}
