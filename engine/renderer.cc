#include <string>
#include <iostream>

#include "renderer.h"

#include "../raylib/raylib-5.0/src/raylib.h"
// #include "../raylib/raylib-5.0/src/raymath.h"

/* defining static members */

Structures::RendererConfig Renderer::config;

/* defining static methods */

void Renderer::printMessage(const std::string &msg) {
	std::cout << "[Renderer] " << msg << std::endl;
};

void Renderer::initWindow() {
	
}

void Renderer::updateConfig(const Structures::RendererConfig &config) {
	Renderer::config = config;
}

void Renderer::printConfig() {
	Renderer::printMessage("config.initialWindowWidth " + std::to_string(Renderer::config.initialWindowWidth));
	Renderer::printMessage("config.initialWindowHeight " + std::to_string(Renderer::config.initialWindowHeight));
	Renderer::printMessage("config.windowShouldScale " + std::to_string(Renderer::config.windowShouldScale));
}