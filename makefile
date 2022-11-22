TR = main

$(TR)   : main.o forward.o reverse.o
	g++ main.o forward.o reverse.o -o $(TR)

main.o : main.cpp
	g++ -c main.cpp -o main.o

forward.o : forward.cpp
	g++ -c forward.cpp -o forward.o

reverse.o : reverse.cpp
	g++ -c reverse.cpp -o reverse.o


clean :
	rm $(TR) *.o
