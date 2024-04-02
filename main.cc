#include "engine/renderer.h"

int main() {
	Renderer::printMessage("Hello renderer");
	Renderer::updateConfig({10, 20, true, "Hello Raylib"});

	Renderer::printConfig();
	Renderer::initWindow();
}

