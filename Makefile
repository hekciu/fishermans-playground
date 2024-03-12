CXX := x86_64-w64-mingw32-gcc-win32 # windows thing

CXX_FLAGS := -std=c++2a -g

engine_files := $(shell find engine/ -type f -name '*.cc')
engine_build_files := $(engine_files:%.cc=%.o)

all: main.exe 

main.exe: main.o $(engine_build_files)
	$(CXX) $(CXX_FLAGS) main.o $(engine_build_files) -o main.exe

main.o: main.cc
	$(CXX) $(CXX_FLAGS) -c main.cc -o main.o

$(engine_build_files): raylib
	$(CXX) $(CXX_FLAGS) -c $(shell echo $@ | sed 's/.o/.cc/g') -o $@


.PHONY: clean raylib raylib-install
clean:
	@echo Cleaning local build files
	find -type f -name *.o -delete
	@echo Cleaning Raylib build files
	$(MAKE) clean -C ./raylib/raylib-5.0/src

raylib:
	$(MAKE) -C ./raylib/raylib-5.0/src

raylib-install:
	$(MAKE) install -C ./raylib/raylib-5.0/src
