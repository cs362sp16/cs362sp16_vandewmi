#include "dominion.h"
#include <stdlib.h>
#include "rngs.h"
#include <stdio.h>
#include <time.h>

int contains(int *cards,int card) {
	int i = 0;
	for(i = 0; i < 10; i++) {
		if(cards[i] == card) return 1;
	}
	return 0;
}

void selectRandomKingdomCards(int *cards) {
	srand(time(NULL));
	int selected = 0;
	while(selected < 10) {
		int trycard = (int) (Random() * (treasure_map - adventurer) + adventurer);
		if(!contains(cards,trycard)) {
			cards[selected] = trycard;
			selected ++;
			printf("DEBUG Added Kingdom Card: %d\n",trycard);
		}
	}
}

int myGetCost(int card) {
  switch(card) {
    case curse:
      return 0;
    case estate:
      return 2;
    case duchy:
      return 5;
    case province:
      return 8;
    case copper:
      return 0;
    case silver:
      return 3;
    case gold:
      return 6;
    case adventurer:
      return 6;
    case council_room:
      return 5;
    case feast:
      return 4;
    case gardens:
      return 4;
    case mine:
      return 5;
    case remodel:
      return 4;
    case smithy:
      return 4;
    case village:
      return 3;
    case baron:
      return 4;
    case great_hall:
      return 3;
    case minion:
      return 5;
    case steward:
      return 3;
    case tribute:
      return 5;
    case ambassador:
      return 3;
    case cutpurse:
      return 4;
    case embargo:
      return 2;
    case outpost:
      return 5;
    case salvager:
      return 4;
    case sea_hag:
      return 4;
    case treasure_map:
      return 4;
    }
}

int findSupplyCard(int *cards, int budget) {
	int found = 0;
	while(!found) {
		int pos = (int) (Random() * 10);
		if(myGetCost(cards[pos]) <= budget) return cards[pos];
	}
}

int findHandMoney(struct gameState *p) {
	int i = 0;
	while(i<numHandCards(p)) {
		int money = handCard(i,p);
                if (money == copper || money == silver || money == gold){
                	return i;
		}
		i++;
        }
	return -1;
}

int selectMoneyType() {
	int kind = (int)(Random() * 3);
	switch(kind) {
		case 0:
			return copper;
			break;
		case 1:
			return silver;
			break;
		case 2:
			return gold;
			break;
	}
}

int main (int argc, char** argv) {
	
	struct gameState G;
  	struct gameState *p = &G;
	int money = 0;

	SelectStream(1);
	PutSeed(atoi(argv[1]));
  	
	int k[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	selectRandomKingdomCards(k);

 	printf ("Starting game.\n");

	int numplayers = (int)((Random() * 3) + 2);
  	initializeGame(numplayers, k, atoi(argv[1]), p);

	int i = 0;
	while(!isGameOver(p)) {
	while(i<numHandCards(p)) {
          	if (handCard(i, p) == copper){
            		playCard(i, -1, -1, -1, p);
            		money++;
          	}
          	else if (handCard(i, p) == silver){
            		playCard(i, -1, -1, -1, p);
            		money += 2;
          	}
          	else if (handCard(i, p) == gold){
            		playCard(i, -1, -1, -1, p);
            		money += 3;
          	}
        	i++;
	}
	
	//code for attempting to play cards
	int tried = 0;
	int ret;
	while(p->numActions > 0 && tried < 1000) {
		int pos = (int)(Random() * (float)numHandCards(p));
		int card = handCard(pos,p);
		int playcard;
		if((card != curse) && (card != copper) && (card != silver) && (card != gold) && (card != province) && (card != duchy) && (card != estate)) {
			switch(card) {
				case adventurer:
					ret = playCard(pos,-1,-1,-1,p);
					if(ret == -1) printf("Failed to play adventurer card\n");
					else printf("Played adventurer card\n");
					break;
				case council_room:
					ret = playCard(pos,-1,-1,-1,p);
					if(ret == -1) printf("Failed to play council_room card\n");
					else printf("Played council_room card\n");
					break;
				case feast:
					ret = playCard(pos,findSupplyCard(k,5),-1,-1,p);
					if(ret == -1) printf("Failed to play feast card\n");
                                        else printf("Played feast card\n");
				case gardens:
					ret = playCard(pos,-1,-1,-1,p);
					if(ret == -1) printf("Failed to play gardens card\n");
                                        else printf("Played gardens card\n");
					break;
				case mine:
                                        ret = playCard(pos,findHandMoney(p),selectMoneyType(),-1,p);
                                        if(ret == -1) printf("Failed to play mine card\n");
                                        else printf("Played mine card\n");
                                        break;
				case remodel:
					playcard = (int)(Random() * numHandCards(p));
                                        ret = playCard(pos,playcard,findSupplyCard(k,myGetCost(handCard(playcard,p)) + 2),-1,p);
                                        if(ret == -1) printf("Failed to play remodel card\n");
                                        else printf("Played remodel card\n");
                                        break;
                                case smithy:
                                        ret = playCard(pos,-1,-1,-1,p);
                                        if(ret == -1) printf("Failed to play smithy card\n");
                                        else printf("Played smithy card\n");
                                        break;
                                case village:
                                        ret = playCard(pos,-1,-1,-1,p);
                                        if(ret == -1) printf("Failed to play village card\n");
                                        else printf("Played village card\n");
                                        break;
                                case baron:
                                        ret = playCard(pos,(int)(Random() * 2),-1,-1,p);
                                        if(ret == -1) printf("Failed to play baron card\n");
                                        else printf("Played baron card\n");
                                        break;
                                case great_hall:
                                        ret = playCard(pos,-1,-1,-1,p);
                                        if(ret == -1) printf("Failed to play great_hall card\n");
                                        else printf("Played great_hall card\n");
                                        break;
                                case minion:
                                        ret = playCard(pos,(int)(Random() * 2 + 1),-1,-1,p);
                                        if(ret == -1) printf("Failed to play minion card\n");
                                        else printf("Played minion card\n");
                                        break;
			}
		}
		tried ++;
	}

	//code for attempting to buy cards
	tried = 0;
	while(p->numBuys > 0 && tried < 100) {
		int buyMoney = (int)(Random() * 2);
		if(buyMoney) {
			if(money >= 6) {
				ret = buyCard(gold,p);
				if(ret != -1) printf("Bought gold\n");
			}
			if(money >= 3) {
                                ret = buyCard(silver,p);
                                if(ret != -1) printf("Bought silver\n");
                        }
			else {
                                ret = buyCard(copper,p);
                                if(ret != -1) printf("Bought copper\n");
                        }
		} else {
			int cardToBuy = findSupplyCard(k,money);
			ret = buyCard(cardToBuy,p);
			if(ret != -1) printf("Bought card %d\n",cardToBuy);
		}
		tried ++;
	}
	endTurn(p);
	for(i = 0; i < numplayers; i ++) {
		printf("Player %d: %d\n",i,scoreFor(i,p));
	}
	}
	printf ("Finished game.\n");
	for(i = 0; i < numplayers; i ++) {
                printf("Player %d: %d\n",i,scoreFor(i,p));
        }
	
}

