out : main.o calc.o
	g++ main.o calc.o -o out

main.o : main.cpp
	g++ -c main.cpp -o main.o

calc.o: calc.cpp
	g++ -c calc.cpp -o calc.o

clean : 
	rm out *.o