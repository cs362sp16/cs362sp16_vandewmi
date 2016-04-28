//
// Created by Miles on 4/28/2016.
//
#include "dominion.h"
#include "commontesting.h"

//unit test for the outpost card
//intended behavior for the outpost card is to give the player a second turn after this one, but only draw 3 cards for that turn
int main() {
    printf("UNIT TEST FOR great hall\n");
    struct gameState *state = newGame();

    //good test, with valid kingdom cards and two players
    int kingdomCards[10] = {great_hall, minion, steward, tribute, ambassador, cutpurse, embargo, outpost, salvager, sea_hag};

    int n_players = 2;
    initializeGame(n_players, kingdomCards, 5, state);

    int player = whoseTurn(state);
    state->hand[player][0] = outpost;
    playCard(0, 0,0,0,state);
    endTurn(state);

    t_assert(whoseTurn(state) == player, "player didn't get a second turn");
    t_assert(state->handCount[player] == 3, "player drew an incorrect number of cards for their second turn");
    t_assert(state->numActions == 1, "player didn't get another action");
    t_assert(state->numBuys[player] == 1, "player didn't get another buy");

    endTurn(state);

    t_assert(whoseTurn(state) != player, "player just keeps getting more turns");


    return 0;
}