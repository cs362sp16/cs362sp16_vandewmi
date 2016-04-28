//
// Created by Miles on 4/28/2016.
//

#include "dominion.h"
#include "commontesting.h"

//unit test for newGame
int main() {
    printf("UNIT TEST FOR newGame()\n");
    struct gameState *state;
    newGame(state);
    t_assert(state != 0, "state not initialized properly");

}