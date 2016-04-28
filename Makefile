CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player

commontesting.o: commontesting.h commontesting.c
    gcc -c commontesting.c -g $(CFLAGS)

unitest1: unittest1.c commontesting.o dominion.o
    gcc -o unittest1 unittest1.c -g commontesting.o dominion.o

unitest2: unittest2.c commontesting.o dominion.o
    gcc -o unittest2 unittest2.c -g commontesting.o dominion.o

unitest3: unittest3.c commontesting.o dominion.o
    gcc -o unittest3 unittest3.c -g commontesting.o dominion.o

unitest4: unittest4.c commontesting.o dominion.o
    gcc -o unittest4 unittest4.c -g commontesting.o dominion.o

unittestresults.out: unittest1 unittest2 unittest3 unittest4
    //do stuff here

clean:
	rm -f *.o playdom.exe playdom test.exe test player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so *.a *.dSYM
