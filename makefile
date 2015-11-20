SRC = polynomial.cpp main.cpp
HEAD = polynomial.h
OBJ = ${patsubst %.cpp, %.o, $(SRC)}
TARGET = polynomial.out

FLAG = -g -c
CC = g++

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $^ -o $@

$(OBJ): %.o: %.cpp $(HEAD)
	$(CC) $< -o $@ $(FLAG)

clean:
	rm $(OBJ) $(TARGET)

rebuild: clean all

.PHONY: all clean rebuild
