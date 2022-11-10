main : make3.o make2.o make.o
	g++ make3.o make2.o make.o -o main

make3.o : make3.cpp
	g++ -c make3.cpp -o make3.o

make2.o : make2.cpp
	g++ -c make2.cpp -o make2.o

make.o : make.cpp
	g++ -c make.cpp -o make.o

clean:
	rm main *.o 