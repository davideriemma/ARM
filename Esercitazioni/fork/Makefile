#compiler and flag definition
compiler = gcc
flags = -g3

#files involved in the compilation projetc
files = main.c parent_process.c child_process.c

#libs involved in the compilation
libs = -lcurl
libpath = -L/usr/lib/x86_64-linux-gnu/

#final executable file
finalexec = main

#rules to make target

all: $(files)
	$(compiler) $(flags) $(libpath) $(files) -o $(finalexec) $(libs)

#project cleaning procedures
rmprog = rm
rmflags = -vr

.PHONY: clean

clean:
	$(rmprog) $(rmflags) $(finalexec)
