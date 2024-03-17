#include <string>
#include <iostream>

#include "renderer.h"

#include "../raylib/raylib-5.0/src/raylib.h"
#include "../raylib/raylib-5.0/src/raymath.h"

void Renderer::printMessage(std::string msg) {
	std::cout << "[Renderer] " << msg << std::endl;
};

void Renderer::testRaylib() {
	std::cout << Normalize(400.0, 0.0, 5.5) << std::endl;
}