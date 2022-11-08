make : main.o calculator.o
	g++ -o make main.o calculator.o
clean:
	rm *.o make