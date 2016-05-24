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

testdominion: dominion.o testdominion.c
	gcc -o testdominion testdominion.c -g dominion.o rngs.o $(CFLAGS)

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

ct1: cardtest1.c dominion.o commontesting.o rngs.o interface.o
	gcc -o ct1 cardtest1.c -g commontesting.o dominion.o rngs.o interface.o $(CFLAGS)

ct2: cardtest2.c dominion.o commontesting.o rngs.o interface.o
	gcc -o ct2 cardtest2.c -g commontesting.o dominion.o rngs.o interface.o $(CFLAGS)

ct3: cardtest3.c dominion.o commontesting.o rngs.o interface.o
	gcc -o ct3 cardtest3.c -g commontesting.o dominion.o rngs.o interface.o $(CFLAGS)

ct4: cardtest4.c dominion.o commontesting.o rngs.o interface.o
	gcc -o ct4 cardtest4.c -g commontesting.o dominion.o rngs.o interface.o $(CFLAGS)

rt1: randomtestcard1.c dominion.o commontesting.o rngs.o interface.o
	gcc -o rt1 randomtestcard1.c -g commontesting.o dominion.o rngs.o interface.o $(CFLAGS)

rt2: randomtestcard2.c dominion.o commontesting.o rngs.o interface.o
	gcc -o rt2 randomtestcard2.c -g commontesting.o dominion.o rngs.o interface.o $(CFLAGS)

rta: randomtestadventurer.c dominion.o commontesting.o rngs.o interface.o
	gcc -o rta randomtestadventurer.c -g commontesting.o dominion.o rngs.o interface.o $(CFLAGS)

.PHONY: unittestresults.out
unittestresults.out: ut1 ut2 ut3 ut4 ct1 ct2 ct3 ct4
	rm unittestresults.out -f
	rm dominion.c.gcov -f
	gcov dominion.c
	ut1 >> unittestresults.out
	ut2 >> unittestresults.out
	ut3 >> unittestresults.out
	ut4 >> unittestresults.out
	ct1 >> unittestresults.out
	ct2 >> unittestresults.out
	ct3 >> unittestresults.out
	ct4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

.PHONY: randomtestcard1.out
randomtestcard1.out: rt1
	rm randomtestcard1.out -f
	rm dominion.c.gcov -f
	gcov dominion.c
	rt1 42 >> randomtestcard1.out
	gcov dominion.c >> randomtestcard1.out

.PHONY: randomtestcard2.out
randomtestcard2.out: rt2
	rm randomtestcard2.out -f
	rm dominion.c.gcov -f
	gcov dominion.c
	timeout 5 rt2 42 >> randomtestcard2.out
	gcov dominion.c >> randomtestcard2.out

.PHONY: randomtestadventurer.out
randomtestadventurer.out: rta
	rm randomtestadventurer.out -f
	rm dominion.c.gcov -f
	gcov dominion.c
	rta >> randomtestadventurer.out
	gcov dominion.c >> randomtestadventurer.out

clean:
	rm -f *.o playdom.exe playdom test.exe test player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so *.a *.dSYM ut1 ut2 ut3 ut4 ct1 ct2 ct3 ct4 unittestresults.out randomtestcard1.out randomtestcard2.out randomtestadventurer.out rt1 rt2 rta
