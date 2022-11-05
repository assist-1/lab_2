CC=g++
Fcu = -c
Fend = -o

make : main.o function.cpp
	$(CC) main.o $(Fend) main function.cpp

main.o : main.cpp
	$(CC) $(Fcu) main.cpp

clean :
	rm *.o main