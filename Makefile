TR = Lab2

$(TR)   : Lab2.o func.o
	g++ Lab2.o func.o -o $(TR)

Lab2.o : Lab2.cpp
	g++ -c Lab2.cpp -o Lab2.o

func.o : func.cpp
	g++ -c func.cpp -o func.o

clean : 
	rm $(TR) *.o