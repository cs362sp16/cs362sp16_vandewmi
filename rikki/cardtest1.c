//
// Created by Miles on 4/28/2016.
//
#include "dominion.h"
#include "commontesting.h"

//unit test for the great_hall card
//intended behavior for the great hall card is to draw a new card and add an action
int main() {
    init_test("great hall");
    struct gameState *state = newGame();

    //good test, with valid kingdom cards and two players
    int kingdomCards[10] = {great_hall, minion, steward, tribute, ambassador, cutpurse, embargo, outpost, salvager, sea_hag};

    int n_players = 2;
    initializeGame(n_players, kingdomCards, 5, state);

    int player = whoseTurn(state);
    state->hand[player][player] = great_hall;
    playCard(0, 0,0,0,state);
    t_assert(state->numActions == 1, "great hall failed to add an action");
    t_assert(state->handCount[0] == 5, "great hall failed to draw a card");
    t_assert(state->numBuys == 1, "great hall changed the available number of buys");

    return 0;
}
