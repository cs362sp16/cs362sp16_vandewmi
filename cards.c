//
// Created by Miles on 4/19/2016.
//
#include "dominion.h"

int play_adventurer(struct gameState *state) {

    int drawntreasure = 0;
    int currentPlayer = whoseTurn(state);
    int cardDrawn;
    int temphand[MAX_HAND];
    int z = 0;// this is the counter for the temp hand

    while(drawntreasure<2){
        if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
            shuffle(currentPlayer, state);
        }
        drawCard(currentPlayer, state);
        cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
        if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
            drawntreasure++;
        else{
            temphand[z]=cardDrawn;
            state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
            z++;
        }
    }
    while(z-1>=0){
        state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
        z=z-1;
    }
    return 0;
}

int play_council_room(struct gameState *state, int handPos) {
    int currentPlayer = whoseTurn(state);
    int i;
    //+4 Cards
    for (i = 0; i < 4; i++)
    {
        drawCard(currentPlayer, state);
    }

    //+1 Buy
    state->numBuys++;

    //Each other player draws a card
    for (i = 0; i < state->numPlayers; i++)
    {
        if ( i != currentPlayer )
        {
            drawCard(i, state);
        }
    }

    //put played card in played card pile
    discardCard(handPos, currentPlayer, state, 0);

    return 0;
}