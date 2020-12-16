all: main

main: main.S
	gcc -x assembler-with-cpp -o $@ $^

.phony: clean

clean:
	rm main
