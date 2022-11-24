CC=g++
Fcu = -c
Fend = -o

make : main.o calc_lib.cpp
	$(CC) main.o $(Fend) main calc_lib.cpp

main.o : main.cpp
	$(CC) $(Fcu) main.cpp

clean :
	rm *.o main