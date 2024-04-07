#include "engine/renderer.h"

int main() {
	Renderer::printMessage("Hello renderer");
	Renderer::updateConfig({1000, 1000, true, "Hello Raylib", 60});

	Renderer::printConfig();
	Renderer::initWindow();
	while(!Renderer::windowShouldClose()) {
		Renderer::render();
	}
	Renderer::closeWindow();
}

