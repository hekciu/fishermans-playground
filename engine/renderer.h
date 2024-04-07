#include <string>

#include "structures.h"

class Renderer {
public:
	static void printMessage(const std::string &msg);
	static void initWindow();
	static bool windowShouldClose();
	static void closeWindow();
	static void updateConfig(const Structures::RendererConfig &config);
	static void printConfig();
	static void render();
private:
	static Structures::RendererConfig config;
	static bool isConfigInitialized;
	static void checkConfig();
	static void setup();
};
