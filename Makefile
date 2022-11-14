PROJECT = main
CC = g++

all: main

$(PROJECT): main.o Functions.o
	$(CC) main.o Functions.o -o $(PROJECT)

main.o: main.cpp
	$(CC) -c main.cpp -o main.o

func.o: Functions.cpp
	$(CC) -c Functions.cpp -o Functions.o

clean:
	rm -rf *.o $(PROJECT)

