CC=gcc
CFLAGS=-Wall -g

all: main

main: main.o io.o solver.o
	$(CC) $(CFLAGS) main.o io.o solver.o -o main

main.o: main.c io.h solver.h constants.h
	$(CC) $(CFLAGS) -c main.c

solver.o: solver.c constants.h
	$(CC) $(CFLAGS) -c solver.c

io.o: solver.c constants.h
	$(CC) $(CFLAGS) -c io.c

clean:
	rm main *.o
