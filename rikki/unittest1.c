//
// Created by Miles on 4/28/2016.
//

#include "dominion.h"
#include "commontesting.h"

//unit test for isGameOver
int main() {
    init_test("isGameOver");
    struct gameState s;
    struct gameState *state = &s;
    t_assert(state != 0, "state not initialized properly");
    state->supplyCount[province] = 0;
    int result = isGameOver(state);
    t_assert(result == 1, "game didn't end when we ran out of provinces");
    return 0;
}
