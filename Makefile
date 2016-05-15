CC := gcc
CFLAGS := -Isrc -g -m32 -std=c99
NASMFLAGS := -g -felf32

all: obj/functions.o
	$(CC) -o bin/main src/main.c $(CFLAGS)

test: obj/functions.o
	gcc -o bin/test obj/functions.o src/test/tests.c $(CFLAGS) -lm

obj/functions.o: src/functions.asm
	nasm -o obj/functions.o src/functions.asm $(NASMFLAGS)

clean:
	rm obj/* bin/*
