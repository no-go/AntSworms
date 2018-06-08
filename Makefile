CC=g++
CFLAGS=-Wall -O3 -mtune=native -std=gnu++11
LDFLAGS=-lm -pthread -lfltk
SOURCES=main.cpp

all:
	$(CC) $(CFLAGS) -o sworms $(SOURCES) $(LDFLAGS)

