CC := gcc
NASMC := nasm
CFLAGS := -Isrc -g -m32 -std=c99
NASMFLAGS := -g -felf32

all: obj/functions.o obj/numerical.o
	$(CC) -o bin/main src/main.c obj/functions.o obj/numerical.o $(CFLAGS)

test: obj/functions.o obj/numerical.o
	$(CC) -o bin/test obj/functions.o obj/numerical.o src/test/tests.c $(CFLAGS) -lm

obj/functions.o: src/functions.asm
	$(NASMC) -o obj/functions.o src/functions.asm $(NASMFLAGS)

obj/numerical.o: src/numerical.c
	$(CC) -c -o obj/numerical.o src/numerical.c $(CFLAGS) -lm

clean:
	rm obj/* bin/*
