make : flags.o calcul.o
	g++ -o make flags.o calcul.o
clean :
		rm *.o make
