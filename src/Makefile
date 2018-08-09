CC=g++
CFLAGS=-Wall -O3 -mtune=native -std=gnu++11
LDFLAGS=-lm -pthread -lfltk
OBJS=Robot.o World.o sim.o robot_impl/Ant.o
PROGRAM=sworms

all: $(OBJS)
	$(CC) $(CFLAGS) -o $(PROGRAM) $(OBJS) $(LDFLAGS)

%.o: %.cpp
	g++ $(COPTS) -o $@ -c $*.cpp

clean:
	rm -f $(PROGRAM)
	rm -f *.o