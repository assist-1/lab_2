OBJS	= main.o parse.o
SOURCE	= main.cpp parse.cpp
HEADER	= parse.h
OUT		= run
CC		= g++
FLAGS	= -g -c 
LFLAGS	= -Wl,--allow-multiple-definition

all: $(OBJS)
	$(CC) -w $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp 

parse.o: parse.cpp
	$(CC) $(FLAGS) parse.cpp 


clean:
	rm -f $(OBJS) $(OUT)