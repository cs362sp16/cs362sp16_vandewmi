//
// Created by Miles on 4/28/2016.
//
#include "dominion.h"
#include "commontesting.h"

//unit test for the minion card
//intended behavior for the minion card is to add an action and then
// either gain 2 gold or discard, draw 4, and force each other player to discard and draw 4
int main() {
    printf("UNIT TEST FOR great hall\n");
    struct gameState *state = newGame();

    //good test, with valid kingdom cards and two players
    int kingdomCards[10] = {great_hall, minion, steward, tribute, ambassador, cutpurse, embargo, outpost, salvager, sea_hag};

    int n_players = 2;
    initializeGame(n_players, kingdomCards, 5, state);

    int player = whoseTurn(state);
    int oldCoins = state->coins;
    state->hand[player][0] = minion;

    // choice1 == 1 -> take the money
    // choice1 == 2 -> do the discarding
    playCard(0, 2,0,0,state);

    t_assert(state->numActions == 1, "minion failed to add an action");
    int i = 0;
    for(i = 0; i < state->numPlayers; i++) {
        t_assert(state->discardCount[i] >= 4, "a player failed to discard their hand");
        t_assert(state->handCount[i] == 4, "a player failed to draw 4 cards");
    }
    t_assert(state->coins == oldCoins, "minion wasn't supposed to add gold, but did");

    initializeGame(n_players, kingdomCards, 5, state);
    player = whoseTurn(state);
    oldCoins = state->coins;
    state->hand[player][0] = minion;

    playCard(0,1,0,0,state);
    t_assert(state->numActions == 1, "minion failed to add an action");
    t_assert(state->discardCount[player] == 1, "player didn't discard properly");
    t_assert(state->coins == oldCoins +2);
    int i = 0;
    for(i = 0; i < state->numPlayers; i++) {
        t_assert(i == player || state->discardCount[i] == 0, "a player discarded their hand when they shouldn't have");
        t_assert(i == player || state->handCount[i] == 5, "a player has an incorrect number of cards");
    }

    return 0;
}