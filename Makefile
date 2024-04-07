TARGET := WINDOWS_64
# TARGET := LINUX

RAYLIB_VERSION := 5.0

current_dir := $(shell pwd)
BUILD_DIR := $(current_dir)/build
SRC_DIR := $(current_dir)

raylib_src_path := $(current_dir)/raylib/raylib-$(RAYLIB_VERSION)/src
engine_src_path := $(SRC_dir)/engine

engine_files := $(notdir $(shell find $(SRC_DIR)/engine/ -maxdepth 1 -type f -name '*.cc'))
engine_build_files := $(engine_files:%.cc=$(BUILD_DIR)/engine/%.o)

raylib_files := $(notdir $(shell find $(raylib_src_path) -maxdepth 1 -type f -name '*.c'))
raylib_build_files := $(raylib_files:%.c=$(BUILD_DIR)/raylib/%.o)

raylib_glfw_files := $(notdir $(shell find $(raylib_src_path)/external/glfw/src -maxdepth 1 -type f -name '*.c'))
raylib_glfw_build_files := $(raylib_glfw_files:%.c=$(BUILD_DIR)/raylib/glfw/%.o)

ifeq ($(TARGET), WINDOWS_64)
	CXX := x86_64-w64-mingw32-g++
	CXX_FLAGS := -std=c++2a -mwindows -Wall -Wextra -g

	CC := x86_64-w64-mingw32-gcc
	CC_FLAGS := -ggdb -DPLATFORM_DESKTOP -fPIC -DSUPPORT_FILEFORMAT_FLAC=1 -DPLATFORM_DESKTOP -fPIC
else
	CXX := g++
	CXX_FLAGS := -std=c++2a -g -Wall -Wextra
endif

game: main.exe

main.exe: main.o $(engine_build_files)
	$(CXX) $(CXX_FLAGS) -I$(raylib_src_path) $(BUILD_DIR)/main.o $(engine_build_files) -o main.exe \
			-L $(current_dir)/raylib/raylib-$(RAYLIB_VERSION) -l:$(BUILD_DIR)/raylib/libraylib.a \
			-lwinmm -lgdi32 -static

main.o: main.cc
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXX_FLAGS) -c main.cc -o $(BUILD_DIR)/main.o

$(BUILD_DIR)/engine/%.o: $(SRC_DIR)/engine/%.c
	$(CXX) $(CXX_FLAGS) -c $< -o $@

.PHONY: clean raylib game

clean:
	rm -rf $(BUILD_DIR)

raylib: $(raylib_build_files)
	$(CC) $(CC_FLAGS) -lwinmm -lgdi32 $(raylib_build_files) \
	-o $(BUILD_DIR)/raylib/libraylib.a

$(BUILD_DIR)/raylib/%.o: $(raylib_src_path)/%.c
	mkdir -p $(BUILD_DIR)/raylib
	$(CC) $(CC_FLAGS) -I./raylib/raylib-$(RAYLIB_VERSION)/src/external/glfw/include -I/usr/include/SDL2 \
	 -c $< -o $@

$(BUILD_DIR)/raylib/glfw/%.o: $(raylib_src_path)/external/glfw/src/%.c
	mkdir -p $(BUILD_DIR)/raylib/glfw
	$(CC) $(CC_FLAGS) -c $< -o $@

