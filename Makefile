TARGET := WINDOWS
# TARGET := LINUX

ifeq ($(TARGET), WINDOWS)
	CXX := x86_64-w64-mingw32-g++ # windows thing
	CC := gcc-mingw-w64
	CXX_FLAGS := -std=c++2a -g -Wall -Wextra -static-libgcc -static-libstdc++
else
	CXX := g++
	CXX_FLAGS := -std=c++2a -g -Wall -Wextra
endif

engine_files := $(shell find engine/ -type f -name '*.cc')
engine_build_files := $(engine_files:%.cc=%.o)

game: main.exe 

main.exe: main.o $(engine_build_files)
	$(CXX) $(CXX_FLAGS) main.o $(engine_build_files) -o main.exe

main.o: main.cc
	$(CXX) $(CXX_FLAGS) -c main.cc -o main.o

$(engine_build_files):
	$(CXX) $(CXX_FLAGS) -c $(shell echo $@ | sed 's/.o/.cc/g') -o $@


.PHONY: clean raylib raylib-install raylib-clean game
clean:
	@echo Cleaning local build files
	find -L . -type f -name *.o -delete

raylib:
	$(MAKE) -C ./raylib/raylib-5.0/src

raylib-install:
	$(MAKE) install -C ./raylib/raylib-5.0/src

raylib-clean:
	@echo Cleaning raylib build files
	$(MAKE) clean -C ./raylib/raylib-5.0/src
