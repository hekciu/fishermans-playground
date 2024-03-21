#include <string>
#include <iostream>

#include "renderer.h"

#include "../raylib/raylib-5.0/src/raylib.h"
#include "../raylib/raylib-5.0/src/raymath.h"

/* defining static members */

Structures::RendererConfig Renderer::config;
bool Renderer::isConfigInitialized = false;

/* defining static methods */

void Renderer::printMessage(const std::string &msg) {
	std::cout << "[Renderer] " << msg << std::endl;
};

void Renderer::initWindow() {
	if (!Renderer::isConfigInitialized) {
		throw std::invalid_argument("Renderer config is not initialized");
	};

	// std::cout << Normalize(1, 2, 3);
	InitWindow(Renderer::config.initialWindowWidth, Renderer::config.initialWindowHeight, Renderer::config.windowName.c_str());
}

void Renderer::updateConfig(const Structures::RendererConfig &config) {
	Renderer::config = config;
	Renderer::isConfigInitialized = true;
}

void Renderer::printConfig() {
	Renderer::printMessage("config.initialWindowWidth " + std::to_string(Renderer::config.initialWindowWidth));
	Renderer::printMessage("config.initialWindowHeight " + std::to_string(Renderer::config.initialWindowHeight));
	Renderer::printMessage("config.windowShouldScale " + std::to_string(Renderer::config.windowShouldScale));
}