CXX_FLAGS := -std=c++2a -g

engine_files := $(shell find engine/ -type f -name '*.cc')

all: main.exe engine

main.exe: main.o
	$(CXX) $(CXX_FLAGS) main.o -o main.exe

main.o: main.cc $(engine_files)
	$(CXX) $(CXX_FLAGS) -c main.cc -o main.o

.PHONY: engine
engine: $(engine_files)
	$(CXX) $(CXX_FLAGS) -c $< -o $(shell echo $< | sed 's/.cc/.o/g')

.PHONY: clean
clean:
	find -type f -name *.o -delete
