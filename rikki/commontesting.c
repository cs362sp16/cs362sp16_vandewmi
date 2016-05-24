//
// Created by Miles on 4/26/2016.
//
#include "dominion.h"
#include "commontesting.h"

int t_assert(int testval, char* message) {
    if(testval)  {
        printf("TEST PASSED\n");
        return 1;
    }
    else {
        printf("TEST FAILED: %s\n", message);
        return 0;
    }
}

void init_test(char* title) {
	printf("\n-----UNIT TEST %s-----\n", title);
}
