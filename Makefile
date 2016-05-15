all: src/main.c
	gcc -std=c99 -o bin/main src/main.c

clean: main.o
	rm ./*.o
