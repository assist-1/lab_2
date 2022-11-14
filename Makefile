PR = laba2

$(PR) : main.o func.o
	g++ main.o func.o -o $(PR)

main.o : main.cpp
	g++ -c main.cpp -o main.o

func.o : func.cpp
	g++ -c func.cpp -o func.o

clean :
	rm $(PR) *.o