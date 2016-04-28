CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c dominion.h cards.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player

commontesting.o: commontesting.h commontesting.c
	gcc -c commontesting.h commontesting.c -g $(CFLAGS)

ut1: unittest1.c dominion.o commontesting.o rngs.o interface.o
	gcc -o ut1 unittest1.c -g commontesting.o dominion.o rngs.o interface.o $(CFLAGS)

ut2: unittest2.c dominion.o commontesting.o rngs.o interface.o 
	gcc -o ut2 unittest2.c commontesting.o dominion.o rngs.o interface.o $(CFLAGS)

ut3: unittest3.c dominion.o commontesting.o rngs.o interface.o
	gcc -o ut3 unittest3.c commontesting.o dominion.o rngs.o interface.o $(CFLAGS)

ut4: unittest4.c dominion.o commontesting.o rngs.o interface.o
	gcc -o ut4 unittest4.c commontesting.o dominion.o rngs.o interface.o $(CFLAGS)

.PHONY: unittestresults.out
unittestresults.out: ut1 ut2 ut3 ut4
	rm unittestresults.out -f
	ut1 >> unittestresults.out
	ut2 >> unittestresults.out
	ut3 >> unittestresults.out
	ut4 >> unittestresults.out


clean:
	rm -f *.o playdom.exe playdom test.exe test player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so *.a *.dSYM
