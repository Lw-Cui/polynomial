SRC = polynomial.cpp main.cpp
OBJ = ${patsubst %.cpp, %.o, $(SRC)}
HEAD = polynomial.h

FLAG = -g -c
CC = g++

all: main.out

main.out: $(OBJ)
	$(CC) $^ -o $@

$(OBJ): %.o: %.cpp $(HEAD)
	$(CC) $< -o $@ $(FLAG)

clean:
	rm $(OBJ) main.out

.PHONY: all clean