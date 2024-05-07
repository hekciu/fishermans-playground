#include <string>
#include <iostream>
#include <algorithm>
#include <queue>

#include "renderer.h"
#include "constants.h"

/* defining static members */

Structures::RendererConfig Renderer::config;
bool Renderer::wasConfigInitialized = false;
bool Renderer::wereRendererModesInitialized = false;
std::vector<int> Renderer::rendererModes;
std::map<int, std::vector<GameObjects::AbstractObject * >> Renderer::gameObjects;
int Renderer::currentRendererMode;

/* defining static methods */

void Renderer::printMessage(const std::string &msg) {
	std::cout << "[Renderer] " << msg << std::endl;
};

void Renderer::checkConfig() {
	if (!Renderer::wasConfigInitialized) {
		throw std::invalid_argument("Renderer config is not initialized");
	};
}

void Renderer::setup() {
	SetTargetFPS(Renderer::config.targetFPS);
}

/*
	This function initializes openGL context - need to be called before everything else
*/
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

int Renderer::getCurrentMode() {
	return Renderer::currentRendererMode;
}

void Renderer::render() {
	BeginDrawing();

	/*
		Draw elements in current 'mode'
	*/
	for (GameObjects::AbstractObject * object : Renderer::gameObjects[Renderer::currentRendererMode]) {
		object->draw();
	}

	EndDrawing();
}

void Renderer::closeWindow() {
	CloseWindow();
}

void Renderer::updateConfig(const Structures::RendererConfig &config) {
	Renderer::config = config;
	Renderer::wasConfigInitialized = true;
}

void Renderer::updateRendererModes(const std::vector<int> &modes) {
	if (Renderer::wereRendererModesInitialized) {
		throw std::invalid_argument("Renderer modes could only be initialized once");
	}
	Renderer::wereRendererModesInitialized = true;

	Renderer::rendererModes = modes;

	for (const int &mode : Renderer::rendererModes) {
		Renderer::gameObjects.insert({mode, {}});
	}
}

void Renderer::changeCurrentMode(const int &mode) {
	Renderer::isModeValid(mode);

	Renderer::currentRendererMode = mode;
}

void Renderer::isModeValid(const int &mode) {
	const int cnt = count(Renderer::rendererModes.begin(), Renderer::rendererModes.end(), mode);

	if (cnt == 0) {
		throw std::invalid_argument("Invalid mode: " + std::to_string(mode));
	}
}

void Renderer::addObjects(const int &mode, const std::vector<GameObjects::AbstractObject * > &objects) {
	Renderer::isModeValid(mode);

	for (GameObjects::AbstractObject * object : objects) {
		Renderer::gameObjects[mode].emplace_back(object);
	}
}

void Renderer::printConfig() {
	Renderer::printMessage("config.initialWindowWidth " + std::to_string(Renderer::config.initialWindowWidth));
	Renderer::printMessage("config.initialWindowHeight " + std::to_string(Renderer::config.initialWindowHeight));
	Renderer::printMessage("config.windowShouldScale " + std::to_string(Renderer::config.windowShouldScale));
	Renderer::printMessage("config.windowName " + Renderer::config.windowName);
	Renderer::printMessage("config.targetFPS " + std::to_string(Renderer::config.targetFPS));
}
