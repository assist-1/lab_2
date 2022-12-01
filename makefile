out : main.o calculate.o Stack.o
	g++ main.o Stack.o calculate.o -o out
main.o : main.cpp
	g++ -c main.cpp -o main.o
Stack.o : Stack.cpp
	g++ -c Stack.cpp -o Stack.o
calculate.o : calculate.cpp
	g++ -c calculate.cpp -o calculate.o
clean :
	rm out *.o

