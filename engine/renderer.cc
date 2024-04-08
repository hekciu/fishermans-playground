#include <string>
#include <iostream>

#include "renderer.h"
#include "constants.h"

#include "raylib.h"

/* defining static members */

Structures::RendererConfig Renderer::config;
bool Renderer::isConfigInitialized = false;

/* defining static methods */

void Renderer::printMessage(const std::string &msg) {
	std::cout << "[Renderer] " << msg << std::endl;
};

void Renderer::checkConfig() {
	if (!Renderer::isConfigInitialized) {
		throw std::invalid_argument("Renderer config is not initialized");
	};
}

void Renderer::setup() {
	SetTargetFPS(Renderer::config.targetFPS);
}

void Renderer::initWindow() {
	Renderer::checkConfig();

	InitWindow(Renderer::config.initialWindowWidth,
		Renderer::config.initialWindowHeight,
		Renderer::config.windowName.c_str());

	Renderer::setup();
}

bool Renderer::windowShouldClose() {
	return WindowShouldClose();
}

void Renderer::render() {
	BeginDrawing();

	ClearBackground(RAYWHITE);

	DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

	EndDrawing();
}

void Renderer::closeWindow() {
	CloseWindow();
}

void Renderer::updateConfig(const Structures::RendererConfig &config) {
	Renderer::config = config;
	Renderer::isConfigInitialized = true;
}

void Renderer::printConfig() {
	Renderer::printMessage("config.initialWindowWidth " + std::to_string(Renderer::config.initialWindowWidth));
	Renderer::printMessage("config.initialWindowHeight " + std::to_string(Renderer::config.initialWindowHeight));
	Renderer::printMessage("config.windowShouldScale " + std::to_string(Renderer::config.windowShouldScale));
	Renderer::printMessage("config.windowName " + Renderer::config.windowName);
	Renderer::printMessage("config.targetFPS " + std::to_string(Renderer::config.targetFPS));
}