CC=g++
CFLAGS=-I.

main: main.cpp forward.cpp forward.h reverse.cpp reverse.h
	$(CC) -c main.cpp forward.cpp forward.h reverse.cpp reverse.h
	$(CC) -o main main.o forward.o reverse.o
