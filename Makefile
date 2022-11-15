TR = main

$(TR)   : main.o cac.o
	g++ main.o cac.o -o $(TR)

main.o : main.cpp
	g++ -c main.cpp -o main.o

cac.o : cac.cpp
	g++ -c cac.cpp -o cac.o

clean : 
	rm $(TR) *.o
