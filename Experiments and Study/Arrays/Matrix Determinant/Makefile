# Makefile

all: main

main: main.S test.o

	gcc -o $@ $^

test.o: test.c
	gcc -o $@ -c $^

.phony: clean

clean:
	rm main