//
// Created by Miles on 4/26/2016.
//

#include "commontesting.h"
#include "dominion.h"

//unit tests for initializeGame
//int initializeGame(int numPlayers, int kingdomCards[10], int randomSeed,
//                   struct gameState *state);
int main() {
    init_test("initalizeGame");
    struct gameState *state = newGame();

    //good test, with valid kingdom cards and two players
    int kingdomCards[10] = {great_hall, minion, steward, tribute, ambassador, cutpurse, embargo, outpost, salvager, sea_hag};

    int n_players = 2;
    initializeGame(n_players, kingdomCards, 5, state);

    t_assert(state->numPlayers == n_players, "incorrect number of players");
    t_assert(state->supplyCount[estate] == 8, "incorrect number of estates");
    t_assert(state->supplyCount[duchy] == 8, "incorrect number of duchies");
    t_assert(state->supplyCount[province] == 8, "incorrect number of provinces");
    t_assert(state->supplyCount[copper] == 60 - (7 * n_players), "incorrect number of copper");
    t_assert(state->supplyCount[silver] == 40, "incorrect number of silver");
    t_assert(state->supplyCount[gold] == 30, "incorrect number of gold");
    t_assert(state->numActions == 1, "incorrect number of actions");
    t_assert(state->numBuys == 1, "incorrect number of buys");
    t_assert(state->handCount[whoseTurn(state)] == 5, "incorrect number of cards in hand");
    t_assert(state->supplyCount[curse] == 10, "incorrect number of curses");

    //bad test, with an invald kingdom card
    kingdomCards[0] = -1;
    state = newGame();
    int ret = initializeGame(n_players, kingdomCards, 5, state);
    t_assert(ret == -1, "invalid kingdom card was allowed into the game");

    //bad test, with a duplicate kingdom card
    kingdomCards[0] = sea_hag;
    state = newGame();
    ret = initializeGame(n_players, kingdomCards, 5, state);
    t_assert(ret == -1, "duplicate kingdom card was allowed into the game");
    return 0;
}
