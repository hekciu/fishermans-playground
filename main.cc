#include "engine/renderer.h"

int main() {
	Renderer::printMessage("Hello renderer");
	Renderer::updateConfig({10, 20, true});

	Renderer::printConfig();
}

