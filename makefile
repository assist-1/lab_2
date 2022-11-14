laba2 : main.o mylib.o
	g++ main.cpp mylib.o -o laba2
main.o : main.cpp
	g++ -c main.cpp -o main.o
mylib.o : mylib.cpp
	g++ -c mylib.cpp -o mylib.o

clean :
	rm laba2 *.o