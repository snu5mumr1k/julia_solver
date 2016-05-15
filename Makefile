all: src/main.c
	nasm -g -felf32 src/functions.asm -o obj/functions.o
	gcc -g -std=c99 -m32 -o bin/main obj/functions.o src/main.c -I src

clean:
	rm obj/* bin/*
