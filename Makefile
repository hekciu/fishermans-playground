TARGET := WINDOWS_64
# TARGET := LINUX

RAYLIB_VERSION := 5.0

current_dir = $(shell pwd)
BUILD_DIR := $(current_dir)/build

raylib_src_path = $(current_dir)/raylib/raylib-$(RAYLIB_VERSION)/src

engine_files := $(shell find engine/ -type f -name '*.cc')
engine_build_files := $(engine_files:%.cc=%.o)

raylib_files := $(shell find $(raylib_src_path) -type f -name '*.c')
raylib_build_files := $(raylib_files:%.c=%.o)

raylib_glfw_files := $(shell find $(raylib_src_path)/external/glfw/src -type f -name '*.c')
raylib_glfw_build_files := $(raylib_glfw_files:%.c=%.o)

ifeq ($(TARGET), WINDOWS_64)
	CXX := x86_64-w64-mingw32-g++
	CXX_FLAGS := -std=c++2a -mwindows -Wall -Wextra -g

	CC := x86_64-w64-mingw32-gcc
	CC_FLAGS := -ggdb -DPLATFORM_DESKTOP -fPIC -DSUPPORT_FILEFORMAT_FLAC=1 -DPLATFORM_DESKTOP -fPIC -mwindows
else
	CXX := g++
	CXX_FLAGS := -std=c++2a -g -Wall -Wextra
endif

game: main.exe

main.exe: main.o $(engine_build_files)
	$(CXX) $(CXX_FLAGS) -I$(raylib_src_path) $(BUILD_DIR)/main.o $(engine_build_files) -o main.exe \
			-L $(current_dir)/raylib/raylib-$(RAYLIB_VERSION) $(BUILD_DIR)/raylib/libraylib.a \
			-lwinmm -lgdi32 -static

main.o: main.cc
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXX_FLAGS) -c main.cc -o $(BUILD_DIR)/main.o

$(engine_build_files): $(engine_files)
	$(CXX) $(CXX_FLAGS) -c $< -o $(BUILD_DIR)/engine/$(notdir $@)

.PHONY: clean raylib game

clean:
	rm $(BUILD_DIR)/main.o $(engine_build_files) $(raylib_build_files) $(raylib_glfw_build_files)

raylib: $(raylib_glfw_build_files) $(raylib_build_files)
	$(CC) $(CC_FLAGS) -lwinmm -lgdi32 $(raylib_build_files) $(raylib_glfw_build_files) \
	-o $(BUILD_DIR)/raylib/libraylib.a

$(raylib_build_files): $(raylib_files)
	mkdir -p $(BUILD_DIR)/raylib
	$(CC) $(CC_FLAGS) -I./raylib/raylib-$(RAYLIB_VERSION)/src/external/glfw/include -c $< -o $(BUILD_DIR)/raylib/$(notdir $@)

$(raylib_glfw_build_files): $(raylib_glfw_files)
	mkdir -p $(BUILD_DIR)/raylib/glfw
	$(CC) $(CC_FLAGS) -c $< -o $(BUILD_DIR)/raylib/glfw/$(notdir $@)

