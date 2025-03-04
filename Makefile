CC = gcc
CFLAGS = -Wall -g

all: money_converter

money_converter: main.o memoization.o cache.o
	$(CC) $(CFLAGS) -o money_converter main.o memoization.o cache.o

main.o: main.c memoization.h cache.h
	$(CC) $(CFLAGS) -c main.c

memoization.o: memoization.c memoization.h
	$(CC) $(CFLAGS) -c memoization.c

cache.o: cache.c cache.h
	$(CC) $(CFLAGS) -c cache.c

clean:
	rm -f *.o money_converter cache.dat
