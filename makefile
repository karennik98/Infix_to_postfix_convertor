CC=g++
CFLAGS=-c
all: run.out

run.out: Main.o Convert.o
	$(CC) Main.o Convert.o -o run.out
Main.o: Main.cpp
	$(CC) $(CFLAGS) Main.cpp
Convert.o: Convert.cpp
	$(CC) $(CFLAGS) Convert.cpp
clean:
	rm *.o
