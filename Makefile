CC=gcc
CFLAGS=-Wall -Wextra -pedantic -Wconversion -Werror
EXE=./run

main: main.c
	$(CC) $(CFLAGS) -o $(EXE) main.c

clean:
	rm -rf *.o *.i *.asm $(EXE)
