CC = g++
CFLAGS += -c
RM = del -f
OBJS = main.o solve.o

.PHONY: all clean
all: solve
solve: $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o solve
main.o: main.cpp solve.h
	$(CC) $(CFLAGS) main.cpp -o main.o
solve.o: solve.cpp
	$(CC) $(CFLAGS) $^ -o solve.o

clean:
	$(RM) $(OBJS)
distclean: clean
	$(RM) solve.exe

