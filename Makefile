CC=g++
ZXC = -c
VBN = -o
make : main.o header.cpp
	$(CC) main.o $(VBN) main header.cpp
main.o : main.cpp
	$(CC) $(ZXC) main.cpp
clean :
	rm *.o main