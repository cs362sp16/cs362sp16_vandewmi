//
// Created by Miles on 4/28/2016.
//
#include "dominion.h"
#include "commontesting.h"

//unit tests for buyCard
int main() {
    printf("UNIT TEST FOR buyCard()\n");
    struct gameState *state = newGame();

    //good test, with valid kingdom cards and two players
    int kingdomCards[10] = {great_hall, minion, steward, tribute, ambassador, cutpurse, embargo, outpost, salvager, sea_hag};
    int n_players = 2;
    initializeGame(n_players, kingdomCards, 5, state);

    int result = buyCard(great_hall,state);
    t_assert(result == 1, "an error occurred");
    t_assert(state->discard[state->whoseTurn][0] == great_hall, "incorrect card added to discard pile");
    t_assert(state->numBuys == 0, "too many buys");

    result = buyCard(great_hall, state);
    t_assert(result == -1, "allowed to purchase without any remaining buys");
}
