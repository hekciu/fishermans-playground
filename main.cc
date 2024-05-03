#include "engine/renderer.h"

int main() {
	Renderer::printMessage("Hello renderer");
	Renderer::updateConfig({1000, 1000, true, "Hello Raylib", 60});

	Renderer::printConfig();
	Renderer::initWindow();
	Renderer::updateRendererModes({0});
	const std::vector<GameObjects::AbstractObject * > vec = {new GameObjects::BackgroundColor(GRAY), new GameObjects::RectangleButton2D(40, 40, 100, 50, RED)};
	Renderer::addObjects(0, vec);
	Renderer::changeCurrentMode(0);
	while(!Renderer::windowShouldClose()) {
		Renderer::render();
	}
	Renderer::closeWindow();
}

