CC := gcc
NASMC := nasm
CFLAGS := -Isrc -g -m32 -std=c99
NASMFLAGS := -g -felf32

all: obj/functions.o obj/equations.o
	$(CC) -o bin/main src/main.c $(CFLAGS)

test: obj/functions.o
	$(CC) -o bin/test obj/functions.o src/test/tests.c $(CFLAGS) -lm

obj/functions.o: src/functions.asm
	$(NASMC) -o obj/functions.o src/functions.asm $(NASMFLAGS)

obj/equations.o: src/equations.c
	$(CC) -c -o obj/equations.o src/equations.c $(CFLAGS) -lm

clean:
	rm obj/* bin/*
