#Makefile

AS = as
CC = gcc
CC_FLAGS =  -g3
LN = ld

target = main

#rules for dependencies

peterson.o: peterson.s
	$(AS) -o peterson.o peterson.s

main.o: peterson.o
	$(CC) $(CC_FLAGS) -o main.o peterson.o

all: main.o
	$(LN) -o $(main) main.o


.PHONY: clean

clean:
	rm main.o peterson.o $(target)


