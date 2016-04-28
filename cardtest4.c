//
// Created by Miles on 4/28/2016.
//
#include "dominion.h"
#include "commontesting.h"

//unit test for the smithy card
//intended behavior for the smithy card is to draw 3 cards
int main() {
    printf("UNIT TEST FOR great hall\n");
    struct gameState *state = newGame();

    //good test, with valid kingdom cards and two players
    int kingdomCards[10] = {smihty, minion, steward, tribute, ambassador, cutpurse, embargo, outpost, salvager, sea_hag};

    int n_players = 2;
    initializeGame(n_players, kingdomCards, 5, state);

    int player = whoseTurn(state);
    state->hand[player][0] = smithy;
    playCard(0, 0,0,0,state);
    t_assert(state->numActions == 0, "playing this card didn't use up an action");
    t_assert(state->handCount[player] == 7, "great hall failed to draw 3 card");
    t_assert(state->discardCount[player] == 1, "didn't discard the smithy")
    t_assert(state->numBuys == 1, "smithy changed the available number of buys");

    return 0;
}
