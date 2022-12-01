TARGET = calculator
CC=g++
CFLAGS = -c

SOURCES = calculator.cpp
OBJ = $(SOURCES: .cpp=.o)

all: $(TARGET) 

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o : %.cpp
	$(CC) $(CFLAGS) $< -o $@  

clean:
	rm -rf *.o $(TARGET)