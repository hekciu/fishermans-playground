CXX_FLAGS := -std=c++2a -g
SHELL := /bin/bash

engine_files := $(shell find engine/ -type f -name '*.cc')
engine_build_files := $(engine_files:%.cc=%.o)

all: main.exe 

main.exe: main.o $(engine_build_files)
	$(CXX) $(CXX_FLAGS) main.o $(engine_build_files) -o main.exe

main.o: main.cc
	$(CXX) $(CXX_FLAGS) -c main.cc -o main.o

$(engine_build_files):
	$(CXX) $(CXX_FLAGS) -c $(shell echo $@ | sed 's/.o/.cc/g') -o $@

.PHONY: clean
clean:
	find -type f -name *.o -delete
