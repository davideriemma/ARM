##Makefile assolutamente non copiato da quello di get_parent_pid

#compiler definition
CC = gcc
CC_FLAGS = -g3

#linker parameters
LIBS = 

#output
out = main

#rules
all: main.c
	$(CC) $(CC_FLAGS) -o $(out) $(out).c

#cleaning definitions
RM = rm 
RM_FLAGS = -vr

.PHONY: clean
clean:
	$(RM) $(RM_FLAGS) $(out)