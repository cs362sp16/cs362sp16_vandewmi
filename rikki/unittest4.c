//
// Created by Miles on 4/28/2016.
//
#include "dominion.h"
#include "commontesting.h"

//unit tests for endTurn
int main() {
    init_test("endTurn");
    struct gameState *state = newGame();

    //good test, with valid kingdom cards and two players
    int kingdomCards[10] = {great_hall, minion, steward, tribute, ambassador, cutpurse, embargo, outpost, salvager, sea_hag};
    int n_players = 2;
    initializeGame(n_players, kingdomCards, 5, state);

    int result = whoseTurn(state);
    t_assert(result == 0, "incorrect starting player's turn");

    result = endTurn(state);
    t_assert(result != -1, "unable to end turn properly");

    result = whoseTurn(state);
    t_assert(result == 1, "incorrect next player's turn");
    return 0;
}
