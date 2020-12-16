#Makefile

file_list = array.S main.c 

all: $(file_list)
	gcc -o main -g -lc $^

.phony: clean

clean:
	rm main
