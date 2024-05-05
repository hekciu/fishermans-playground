#include "engine/renderer.h"
#include "engine/event_manager.h"

int main() {
	Renderer::printMessage("Hello renderer");
	Renderer::updateConfig({1000, 1000, true, "Hello Raylib", 60});

	Renderer::printConfig();
	Renderer::initWindow();
	Renderer::updateRendererModes({0, 1});
	const std::vector<GameObjects::AbstractObject * > vec = {new GameObjects::BackgroundColor(GRAY),
		new GameObjects::RectangleButton2D(40, 40, 100, 50, RED, "something", 5)};
	Renderer::addObjects(0, vec);

	const std::vector<GameObjects::AbstractObject * > vec2 = {new GameObjects::BackgroundColor(BLACK),
		new GameObjects::RectangleButton2D(40, 40, 100, 50, GREEN, "something else", 5)};
	Renderer::addObjects(1, vec2);
	Renderer::changeCurrentMode(0);
	while(!Renderer::windowShouldClose()) {
		Renderer::render();
	}
	Renderer::closeWindow();
}

