CC=gcc
CFLAGS=-Wall -Wextra -Wconversion
LIBS=-lglfw -lGL -lm -ldl -pthread
EXE=./run
INC=-I./include
DEPS=./src/glad.c

all: clean main

main: main.c
	$(CC) $(CFLAGS) -o $(EXE) main.c $(DEPS) $(LIBS) $(INC)

clean:
	rm -rf *.o *.i *.asm $(EXE)
