#compiler and flag definition
compiler = g++
flags = -g3

#files involved in the compilation projetc
files = main.cpp

#libs involved in the compilation
libs = 
libpath = 

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
