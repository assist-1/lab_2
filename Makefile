CC=g++
CFLAGS=-c

all: lab_2

lab_2: main.o calc.o structures.o
	$(CC) main.o calc.o structures.o -o lab_2

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp -o main.o

calc.o: calc.cpp
	$(CC) $(CFLAGS) calc.cpp -o calc.o

structures.o: structures.cpp
	$(CC) $(CFLAGS) structures.cpp -o structures.o

clean:
	rm -rf *.o lab_2
