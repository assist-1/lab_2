CC=g++
CFLAGS=-c

all: lab_2

lab_2: main.o calculator.o
	$(CC) main.o calculator.o -o lab_2

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp -o main.o

calculator.o: calculator.cpp
	$(CC) $(CFLAGS) calculator.cpp -o calculator.o

clean:
	rm -rf *.o lab_2
