CC=g++
CFLAGS=-c -std=c++17

all: lab_2

lab_2: main.o calculator.o token.o
	$(CC) main.o calculator.o token.o -o lab_2

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp -o main.o

calculator.o: calculator.cpp
	$(CC) $(CFLAGS) calculator.cpp -o calculator.o

token.o: token.cpp
	$(CC) $(CFLAGS) token.cpp -o token.o

clean:
	rm -rf *.o lab_2
