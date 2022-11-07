CC=g++
CFLAGS=-c

all: lab_2

lab_2: main.o
	$(CC) main.o -o lab_2

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp -o main.o

clean:
	rm -rf *.o lab_2
