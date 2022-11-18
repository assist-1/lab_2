all: exp
exp: exp.o convert.o evaluate.o
	g++ exp.o convert.o evaluate.o -o exp
exp.o: exp.cpp
	g++ -c exp.cpp
convert.o: convert.cpp
	g++ -c convert.cpp
evaluate.o: evaluate.cpp
	g++ -c evaluate.cpp
clean:
	rm -rf *.o exp
